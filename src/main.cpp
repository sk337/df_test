#include <vector>
#include <cstdint>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

using namespace std;

typedef uint64_t map_t[8];

struct Color
{
    uint8_t r, g, b;
};

struct Light
{
    u_int32_t x, y;
    Color color;
    u_int32_t intensity; 
};

struct Map
{
    std::vector<Light> lights;
    // bool map[32][16];
    uint64_t bitmap[8];
};

typedef Color pixel_buffer[256][128];


/// @brief Mixes two colors together with factor
/// @param a color a
/// @param b color b
/// @param factor facor to mix the colors
/// @return mixed color
Color mix_color(Color a, Color b, double factor){
    Color c;
    c.r = a.r * (1 - factor) + b.r * factor;
    c.g = a.g * (1 - factor) + b.g * factor;
    c.b = a.b * (1 - factor) + b.b * factor;
    return c;
};


int main(){
    // Create a pixel buffer
    // pixel_buffer buffer;
    // create a map
    Map m;
    // create a light
    Light l;
    l.x = 128;
    l.y = 64;
    l.color.r = 255;
    l.color.g = 255;
    l.color.b = 255;
    l.intensity = 100;
    m.lights.push_back(l);


    // create a bitmap manually
    m.bitmap[0] = 0xffffffffe0000001;
    m.bitmap[1] = 0xe0000001ff01ffe1;
    m.bitmap[2] = 0xe0000001f0000001;
    m.bitmap[3] = 0xf0000001f0000001;
    m.bitmap[4] = 0xe0e007ffe000007f;
    m.bitmap[5] = 0xe000000fe001800f;
    m.bitmap[6] = 0xe001800380000003;
    m.bitmap[7] = 0xe000000fffffffff;

    

}

