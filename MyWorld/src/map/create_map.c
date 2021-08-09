/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f new_point = {0, 0};
    float angle_x = (float) (25 * M_PI / 180);
    float angle_y = (float) (25 * M_PI / 180);

    x *= 64;
    y *= 64;
    z *= 10;
    new_point.x = cos(angle_x) * (x + 1000) - cos(angle_x) * (y + 50);
    new_point.y = sin(angle_y) * (y + 50) + sin(angle_y) * (x + 600) - z;
    return (new_point);
}

sfVector2f **create_2d_map(int **tree_dim_map, data_game *data)
{
    sfVector2f **two_dim_map = malloc(sizeof(sfVector2f *) * (data->map_y + 1));

    for (int y = 0; y < data->map_y; y++) {
        two_dim_map[y] = malloc(sizeof(sfVector2f) * (data->map_x));
        for (int x = 0; x < data->map_x; x++)
            two_dim_map[y][x] = project_iso_point(x, y,
                                                  tree_dim_map[x][y]);
    }
    return (two_dim_map);
}

sfVertexArray *create_quad(data_game *data, int x, int y)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = data->map[y - 1][x - 1],
            .color = sfWhite, .texCoords = {0, 0}};
    sfVertex vertex2 = {.position = data->map[y][x - 1],
            .color = sfWhite, .texCoords = {0, 48}};
    sfVertex vertex3 = {.position = data->map[y - 1][x],
            .color = sfWhite, .texCoords = {48, 0}};
    sfVertex vertex4 = {.position = data->map[y][x],
            .color = sfWhite, .texCoords = {48, 48}};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

int draw_2d_map(data_game *data)
{
    sfVertexArray *vertex_array = NULL;
    sfRenderStates state = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    for (int x = 1; x < data->map_x; x++)
        for (int y = 1; y < data->map_y; y++) {
            vertex_array = create_quad(data, x, y);
            state.texture = get_texture(data, x, y);
            sfRenderWindow_drawVertexArray(data->window, vertex_array,
                                           &state);
            sfVertexArray_destroy(vertex_array);
        }
}