/*
** EPITECH PROJECT, 2021
** Skybox.cpp
** File description:
** Skybox.cpp
*/

#include "component/Skybox.hpp"

ray::Skybox::Skybox(sw::Entity& entityRef) :
sw::Component(entityRef),
m_mesh(),
m_box(),
m_cubeMap()
{
    int mat = MATERIAL_MAP_CUBEMAP;
    int one = 1;
    int zero = 0;

    m_mesh = GenMeshCube(1, 1, 1);
    m_box = LoadModelFromMesh(m_mesh);
    m_box.materials[0].shader = LoadShader("resources/shaders/skybox.vs", "resources/shaders/skybox.fs");
    SetShaderValue(m_box.materials[0].shader, GetShaderLocation(m_box.materials[0].shader, "environmentMap"),
                   &mat, SHADER_UNIFORM_INT);
    SetShaderValue(m_box.materials[0].shader, GetShaderLocation(m_box.materials[0].shader, "doGamma"),
                   &one, SHADER_UNIFORM_INT);
    SetShaderValue(m_box.materials[0].shader, GetShaderLocation(m_box.materials[0].shader, "vflipped"),
                   &one, SHADER_UNIFORM_INT);
    m_cubeMap = LoadShader("resources/shaders/cubeMap.vs", "resources/shaders/cubeMap.fs");
    SetShaderValue(m_cubeMap, GetShaderLocation(m_cubeMap, "equirectangularMap"),
                   &zero, SHADER_UNIFORM_INT);
    m_texture = LoadTexture("resources/hdri/Ocean.hdr");
    m_box.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = GenCubeMap(m_cubeMap, m_texture, 1024, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
}

TextureCubemap ray::Skybox::GenCubeMap(Shader shader, Texture2D panorama, int size, int format)
{
    TextureCubemap cubemap = { 0 };
    rlDisableBackfaceCulling();
    unsigned int rbo = rlLoadTextureDepth(size, size, true);
    cubemap.id = rlLoadTextureCubemap(0, size, format);
    unsigned int fbo = rlLoadFramebuffer(size, size);
    rlFramebufferAttach(fbo, rbo, RL_ATTACHMENT_DEPTH, RL_ATTACHMENT_RENDERBUFFER, 0);
    rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X, 0);

    if (rlFramebufferComplete(fbo))
        TraceLog(LOG_INFO, "FBO: [ID %i] Framebuffer object created successfully", fbo);
    rlEnableShader(shader.id);
    Matrix matFboProjection = MatrixPerspective(90.0*DEG2RAD, 1.0, RL_CULL_DISTANCE_NEAR, RL_CULL_DISTANCE_FAR);
    rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_PROJECTION], matFboProjection);
    Matrix fboViews[6] = {
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, {  1.0f,  0.0f,  0.0f }, { 0.0f, -1.0f,  0.0f }),
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, { -1.0f,  0.0f,  0.0f }, { 0.0f, -1.0f,  0.0f }),
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, {  0.0f,  1.0f,  0.0f }, { 0.0f,  0.0f,  1.0f }),
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, {  0.0f, -1.0f,  0.0f }, { 0.0f,  0.0f, -1.0f }),
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, {  0.0f,  0.0f,  1.0f }, { 0.0f, -1.0f,  0.0f }),
            MatrixLookAt({ 0.0f, 0.0f, 0.0f }, {  0.0f,  0.0f, -1.0f }, { 0.0f, -1.0f,  0.0f })
    };
    rlViewport(0, 0, size, size);
    rlActiveTextureSlot(0);
    rlEnableTexture(panorama.id);
    for (int i = 0; i < 6; i++)
    {
        rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_VIEW], fboViews[i]);
        rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X + i, 0);
        rlEnableFramebuffer(fbo);
        rlClearScreenBuffers();
        rlLoadDrawCube();
    }
    rlDisableShader();
    rlDisableTexture();
    rlDisableFramebuffer();
    rlUnloadFramebuffer(fbo);
    rlViewport(0, 0, rlGetFramebufferWidth(), rlGetFramebufferHeight());
    rlEnableBackfaceCulling();
    cubemap.width = size;
    cubemap.height = size;
    cubemap.mipmaps = 1;
    cubemap.format = format;
    return (cubemap);
}

Model ray::Skybox::getModel() const
{
    return (m_box);
}