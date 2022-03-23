/*
** EPITECH PROJECT, 2022
** Game Object Sprite
** File description:
** Sprite
*/

#pragma once

#include <memory>
#include "GameObject.hpp"

namespace Arcade
{
    struct AsciiSprite
    {
        VectorXY size;
        Pixel *pixels;
    };

    class Sprite : public Arcade::AGameObject
    {
    public:
        Sprite(const std::string &texturePath = "", const std::string &asciiTexturePath = "");
        ~Sprite();

        

    private:
        std::string texturePath;
        std::unique_ptr<AsciiSprite *> asciiSprite;
    };
}
