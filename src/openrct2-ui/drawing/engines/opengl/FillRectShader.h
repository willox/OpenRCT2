#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#pragma once

#include "GLSLTypes.h"
#include "OpenGLShaderProgram.h"

class OpenGLFramebuffer;

class FillRectShader final : public OpenGLShaderProgram
{
private:
    GLuint uScreenSize;
    GLuint uPalette;
    GLuint uClip;
    GLuint uBounds;
    GLuint uColour;
    // TODO: no magic numbers
    // 0x1 = cross hatch
    // 0x2 = NYI pattern
    // 0x4 = use colour lookup table
    GLuint uFlags;
    GLuint uSourceFramebuffer;

    GLuint vIndex;

    GLuint _vbo;
    GLuint _vao;

public:
    FillRectShader();
    ~FillRectShader() override;

    void SetScreenSize(sint32 width, sint32 height);
    void SetClip(sint32 left, sint32 top, sint32 right, sint32 bottom);
    void SetBounds(sint32 left, sint32 top, sint32 right, sint32 bottom);
    void SetFlags(uint32 flags);
    void SetColour(uint8 colour);
    void SetSourceFramebuffer(GLuint texture);
    void SetPalette(const vec4f *glPalette);
    
    void Draw(sint32 left, sint32 top, sint32 right, sint32 bottom);

    GLuint GetSourceFramebuffer() const;

private:
    void GetLocations();
};
