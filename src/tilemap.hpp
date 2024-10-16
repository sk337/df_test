#include <cstdint>
#include <iostream>

using namespace std;

struct texmap {
    uint8_t loc_data[47];
    FILE *file;
};

texmap create_default_texmap();

