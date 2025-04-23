#pragma once

#ifdef _WIN32
#include <conio.h>
#include <stdlib.h>

char get_char()
{
    char c = _getch();
    if (c == 3)
        exit(-1);
    return c;
}

#else
#include <termios.h>
#include <unistd.h>

static inline char get_char()
{
    struct termios oldt, newt;
    char c;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    read(STDIN_FILENO, &c, 1);

    // Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return c;
}
#endif
