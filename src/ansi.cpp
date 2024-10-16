#include "ansi.hpp"
#include <cstdint>
#include <cstdio>

const char *ANSI::reset = "\033[0m";
const char *ANSI::clear = "\033[2J\033[H";
const char *ANSI::bold = "\033[1m";
const char *ANSI::underline = "\033[4m";
const char *ANSI::blink = "\033[5m";
const char *ANSI::reverse = "\033[7m";
const char *ANSI::concealed = "\033[8m";
const char *ANSI::black = "\033[30m";
const char *ANSI::red = "\033[31m";
const char *ANSI::green = "\033[32m";
const char *ANSI::yellow = "\033[33m";
const char *ANSI::blue = "\033[34m";
const char *ANSI::magenta = "\033[35m";
const char *ANSI::cyan = "\033[36m";
const char *ANSI::white = "\033[37m";
const char *ANSI::black_bg = "\033[40m";
const char *ANSI::red_bg = "\033[41m";
const char *ANSI::green_bg = "\033[42m";
const char *ANSI::yellow_bg = "\033[43m";
const char *ANSI::blue_bg = "\033[44m";
const char *ANSI::magenta_bg = "\033[45m";
const char *ANSI::cyan_bg = "\033[46m";
const char *ANSI::white_bg = "\033[47m";

void ANSI::set_line(uint32_t line)
{
    printf("\033[%d;0H", line);
}

void ANSI::set_column(uint32_t column)
{
    printf("\033[%dG", column);
}

void ANSI::set_position(uint32_t line, uint32_t column)
{
    printf("\033[%d;%dH", line, column);
}

void ANSI::move_up(uint32_t lines)
{
    printf("\033[%dA", lines);
}

void ANSI::move_down(uint32_t lines)
{
    printf("\033[%dB", lines);
}

void ANSI::move_left(uint32_t columns)
{
    printf("\033[%dD", columns);
}

void ANSI::move_right(uint32_t columns)
{
    printf("\033[%dC", columns);
}

void ANSI::clear_line()
{
    printf("\033[2K");
}

void ANSI::clear_line(uint32_t line)
{
    printf("\033[%dK", line);
}

void ANSI::clear_screen()
{
    printf("\033[2J\033[H");
}

