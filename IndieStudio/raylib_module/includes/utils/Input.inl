/*
** EPITECH PROJECT, 2021
** Input.inl
** File description:
** Input.inl
*/

inline bool ray::Input::GetKeyDown(ray::Keyboard key)
{
    return (::IsKeyDown(key));
}

inline bool ray::Input::GetKeyPressed(ray::Keyboard key)
{
    return (::IsKeyPressed(key));
}

inline bool ray::Input::GetKeyReleased(ray::Keyboard key)
{
    return (::IsKeyReleased(key));
}

inline bool ray::Input::GetKeyUp(ray::Keyboard key)
{
    return (::IsKeyUp(key));
}

inline float ray::Input::GetGamepadAxis(int padNbr, int axisNbr)
{
    return (::GetGamepadAxisMovement(padNbr, axisNbr));
}

inline std::string ray::Input::GetGamePadName(int padNbr)
{
    return (std::string(::GetGamepadName(padNbr)));
}

inline bool ray::Input::IsGamePadButtonDown(int padNbr, int key)
{
    return (::IsGamepadButtonDown(padNbr, key));
}

inline bool ray::Input::IsGamePadButtonPressed(int padNbr, int key)
{
    return (::IsGamepadButtonPressed(padNbr, key));
}

inline bool ray::Input::IsGamePadButtonReleased(int padNbr, int key)
{
    return (::IsGamepadButtonReleased(padNbr, key));
}

inline bool ray::Input::IsGamePadButtonUp(int padNbr, int key)
{
    return (::IsGamepadButtonUp(padNbr, key));
}

inline bool ray::Input::IsMouseButtonPressed(ray::Mouse key)
{
    return (::IsMouseButtonPressed(key));
}

inline bool ray::Input::IsMouseButtonDown(ray::Mouse key)
{
    return (::IsMouseButtonDown(key));
}

inline bool ray::Input::IsMouseButtonReleased(ray::Mouse key)
{
    return (::IsMouseButtonReleased(key));
}

inline bool ray::Input::IsMouseButtonUp(ray::Mouse key)
{
    return (::IsMouseButtonUp(key));
}

inline int ray::Input::GetMouseX()
{
    return (::GetMouseX());
}

inline int ray::Input::GetMouseY()
{
    return (::GetMouseY());
}

inline sw::Vector2f ray::Input::GetMousePosition()
{
    Vector2 mousePos = ::GetMousePosition();
    return (sw::Vector2f{mousePos.x, mousePos.y});
}
