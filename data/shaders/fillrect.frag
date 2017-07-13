#version 150

uniform ivec2       uScreenSize;
uniform vec4        uPalette[256];
uniform ivec4       uClip;
uniform ivec4       uBounds;
uniform int         uColour;
uniform int         uFlags;
uniform sampler2D   uSourceFramebuffer;

in vec2 fPosition;

out vec4 oColour;

void main()
{
    if (fPosition.x < uClip.x || fPosition.x > uClip.z ||
        fPosition.y < uClip.y || fPosition.y > uClip.w)
    {
        discard;
    }

    // Cross-stitching
    if ((uFlags & 1) != 0)
    {
        
        int posSum = int(fPosition.x) + int(fPosition.y);
        if ((posSum % 2) != 0)
        {
            discard;
        }
    }

    // NYI pattern
    if ((uFlags & 2) != 0)
    {

    }

    // Colour lookup table
    if ((uFlags & 4) != 0)
    {
        //vec2 textureCoordinates = (fPosition / vec2(uScreenSize)) * vec2(1, -1);
        //int dstColour = int(texture(uSourceFramebuffer, textureCoordinates).b * 255.0);

        //oColour = uPalette[uColourLookup[dstColour]];
        // NYI
        oColour = vec4( 1.0, 0.0, 0.5, 1.0 );
        return;
    }

    oColour = uPalette[uColour];
}
