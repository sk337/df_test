#ifndef ANSI_CPP
#define ANSI_CPP

#include <cstdint>

struct ANSI
{
    static const char *reset;
    static const char *bold;
    static const char *underline;
    static const char *blink;
    static const char *reverse;
    static const char *concealed;
    static const char *black;
    static const char *red;
    static const char *green;
    static const char *yellow;
    static const char *blue;
    static const char *magenta;
    static const char *cyan;
    static const char *white;
    static const char *black_bg;
    static const char *red_bg;
    static const char *green_bg;
    static const char *yellow_bg;
    static const char *blue_bg;
    static const char *magenta_bg;
    static const char *cyan_bg;
    static const char *white_bg;
    

    static const char *clear;
    void set_line(uint32_t line);
    void set_column(uint32_t column);
    void set_position(uint32_t line, uint32_t column);
    void move_up(uint32_t lines);
    void move_down(uint32_t lines);
    void move_left(uint32_t columns);
    void move_right(uint32_t columns);
    void clear_line();
    void clear_line(uint32_t line);
    void clear_screen();
};

#endif