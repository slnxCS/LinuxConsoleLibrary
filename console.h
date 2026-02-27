#ifndef LINUX_CONSOLE_H
#define LINUX_CONSOLE_H

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>

typedef enum {
    LC_BLACK = 0,
    LC_RED,
    LC_GREEN,
    LC_YELLOW,
    LC_BLUE,
    LC_MAGENTA,
    LC_CYAN,
    LC_WHITE
} lc_color;

void lc_clear(void);
void lc_goto(int x, int y);
void lc_hide_cursor(void);
void lc_show_cursor(void);
void lc_set_color(lc_color fg, lc_color bg);
void lc_reset_color(void);
void lc_raw_on(void);
void lc_raw_off(void);
void lc_sleep_ms(long ms);

int  lc_kbhit(void);
int  lc_getch(void);
int lc_get_console_width();
int lc_get_console_heigth();

#endif 
