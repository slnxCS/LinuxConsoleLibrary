#include "console.h"
#include <sys/ioctl.h>

static struct termios lc_old_termios;

void lc_clear(void)
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void lc_goto(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
}

void lc_hide_cursor(void)
{
    printf("\033[?25l");
}

void lc_show_cursor(void)
{
    printf("\033[?25h");
}

void lc_set_color(lc_color fg, lc_color bg)
{
    printf("\033[%d;%dm", 30 + fg, 40 + bg);
}

void lc_reset_color(void)
{
    printf("\033[0m");
}

void lc_raw_on(void)
{
    struct termios raw;
    tcgetattr(STDIN_FILENO, &lc_old_termios);
    raw = lc_old_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN]  = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void lc_raw_off(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &lc_old_termios);
}

int lc_kbhit(void)
{
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

int lc_getch(void)
{
    unsigned char c;
    if (read(STDIN_FILENO, &c, 1) == 1)
        return c;
    return -1;
}

void lc_sleep_ms(long ms)
{
    struct timespec ts;
    ts.tv_sec  = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

int lc_get_console_width()
{
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        perror("ioctl");
        return -1;
    }

    return ws.ws_col;
}

int lc_get_console_heigth()
{
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        perror("ioctl");
        return -1;
    }

    return ws.ws_row - 1;
}