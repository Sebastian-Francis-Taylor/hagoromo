#ifndef HAGOROMO_H
#define HAGOROMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* ANSI escape codes */
#define ANSI_RESET "\033[0m"
#define ANSI_BOLD "\033[1m"
#define ANSI_DIM "\033[2m"
#define ANSI_ITALIC "\033[3m"
#define ANSI_UNDERLINE "\033[4m"
#define ANSI_INVERSE "\033[7m"
#define ANSI_STRIKETHROUGH "\033[9m"

#define ANSI_BLACK "\033[30m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN "\033[36m"
#define ANSI_WHITE "\033[37m"

#define ANSI_BRIGHT_BLACK "\033[90m"
#define ANSI_BRIGHT_RED "\033[91m"
#define ANSI_BRIGHT_GREEN "\033[92m"
#define ANSI_BRIGHT_YELLOW "\033[93m"
#define ANSI_BRIGHT_BLUE "\033[94m"
#define ANSI_BRIGHT_MAGENTA "\033[95m"
#define ANSI_BRIGHT_CYAN "\033[96m"
#define ANSI_BRIGHT_WHITE "\033[97m"

#define ANSI_BG_BLACK "\033[40m"
#define ANSI_BG_RED "\033[41m"
#define ANSI_BG_GREEN "\033[42m"
#define ANSI_BG_YELLOW "\033[43m"
#define ANSI_BG_BLUE "\033[44m"
#define ANSI_BG_MAGENTA "\033[45m"
#define ANSI_BG_CYAN "\033[46m"
#define ANSI_BG_WHITE "\033[47m"

#define ANSI_BG_BRIGHT_BLACK "\033[100m"
#define ANSI_BG_BRIGHT_RED "\033[101m"
#define ANSI_BG_BRIGHT_GREEN "\033[102m"
#define ANSI_BG_BRIGHT_YELLOW "\033[103m"
#define ANSI_BG_BRIGHT_BLUE "\033[104m"
#define ANSI_BG_BRIGHT_MAGENTA "\033[105m"
#define ANSI_BG_BRIGHT_CYAN "\033[106m"
#define ANSI_BG_BRIGHT_WHITE "\033[107m"

static int hagoromo_enabled = -1;

static inline void hagoromo_init(void) {
    if (hagoromo_enabled == -1) {
        hagoromo_enabled = isatty(STDOUT_FILENO);
    }
}

static inline void hagoromo_set_enabled(int enabled) { hagoromo_enabled = enabled; }

static inline int hagoromo_is_enabled(void) {
    if (hagoromo_enabled == -1) hagoromo_init();
    return hagoromo_enabled;
}

static inline char *hagoromo_wrap(const char *code, const char *str) {
    if (!hagoromo_is_enabled()) {
        return strdup(str);
    }
    size_t len = strlen(code) + strlen(str) + strlen(ANSI_RESET) + 1;
    char *result = (char *)malloc(len);
    if (result) {
        snprintf(result, len, "%s%s%s", code, str, ANSI_RESET);
    }
    return result;
}

/* Foreground colors */
static inline char *hagoromo_black(const char *s) { return hagoromo_wrap(ANSI_BLACK, s); }

static inline char *hagoromo_red(const char *s) { return hagoromo_wrap(ANSI_RED, s); }

static inline char *hagoromo_green(const char *s) { return hagoromo_wrap(ANSI_GREEN, s); }

static inline char *hagoromo_yellow(const char *s) { return hagoromo_wrap(ANSI_YELLOW, s); }

static inline char *hagoromo_blue(const char *s) { return hagoromo_wrap(ANSI_BLUE, s); }

static inline char *hagoromo_magenta(const char *s) { return hagoromo_wrap(ANSI_MAGENTA, s); }

static inline char *hagoromo_cyan(const char *s) { return hagoromo_wrap(ANSI_CYAN, s); }

static inline char *hagoromo_white(const char *s) { return hagoromo_wrap(ANSI_WHITE, s); }

/* Bright colors */
static inline char *hagoromo_bright_black(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_BLACK, s);
}

static inline char *hagoromo_bright_red(const char *s) { return hagoromo_wrap(ANSI_BRIGHT_RED, s); }

static inline char *hagoromo_bright_green(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_GREEN, s);
}

static inline char *hagoromo_bright_yellow(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_YELLOW, s);
}

static inline char *hagoromo_bright_blue(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_BLUE, s);
}

static inline char *hagoromo_bright_magenta(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_MAGENTA, s);
}

static inline char *hagoromo_bright_cyan(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_CYAN, s);
}

static inline char *hagoromo_bright_white(const char *s) {
    return hagoromo_wrap(ANSI_BRIGHT_WHITE, s);
}

/* Background colors */
static inline char *hagoromo_bg_black(const char *s) { return hagoromo_wrap(ANSI_BG_BLACK, s); }

static inline char *hagoromo_bg_red(const char *s) { return hagoromo_wrap(ANSI_BG_RED, s); }

static inline char *hagoromo_bg_green(const char *s) { return hagoromo_wrap(ANSI_BG_GREEN, s); }

static inline char *hagoromo_bg_yellow(const char *s) { return hagoromo_wrap(ANSI_BG_YELLOW, s); }

static inline char *hagoromo_bg_blue(const char *s) { return hagoromo_wrap(ANSI_BG_BLUE, s); }

static inline char *hagoromo_bg_magenta(const char *s) { return hagoromo_wrap(ANSI_BG_MAGENTA, s); }

static inline char *hagoromo_bg_cyan(const char *s) { return hagoromo_wrap(ANSI_BG_CYAN, s); }

static inline char *hagoromo_bg_white(const char *s) { return hagoromo_wrap(ANSI_BG_WHITE, s); }

/* Bright backgrounds */
static inline char *hagoromo_bg_bright_black(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_BLACK, s);
}

static inline char *hagoromo_bg_bright_red(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_RED, s);
}

static inline char *hagoromo_bg_bright_green(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_GREEN, s);
}

static inline char *hagoromo_bg_bright_yellow(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_YELLOW, s);
}

static inline char *hagoromo_bg_bright_blue(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_BLUE, s);
}

static inline char *hagoromo_bg_bright_magenta(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_MAGENTA, s);
}

static inline char *hagoromo_bg_bright_cyan(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_CYAN, s);
}

static inline char *hagoromo_bg_bright_white(const char *s) {
    return hagoromo_wrap(ANSI_BG_BRIGHT_WHITE, s);
}

/* Styles */
static inline char *hagoromo_bold(const char *s) { return hagoromo_wrap(ANSI_BOLD, s); }

static inline char *hagoromo_dim(const char *s) { return hagoromo_wrap(ANSI_DIM, s); }

static inline char *hagoromo_italic(const char *s) { return hagoromo_wrap(ANSI_ITALIC, s); }

static inline char *hagoromo_underline(const char *s) { return hagoromo_wrap(ANSI_UNDERLINE, s); }

static inline char *hagoromo_inverse(const char *s) { return hagoromo_wrap(ANSI_INVERSE, s); }

static inline char *hagoromo_strikethrough(const char *s) {
    return hagoromo_wrap(ANSI_STRIKETHROUGH, s);
}

/* 256-color */
static inline char *hagoromo_color256(int code, const char *s) {
    char buf[32];
    snprintf(buf, sizeof(buf), "\033[38;5;%dm", code);
    return hagoromo_wrap(buf, s);
}

static inline char *hagoromo_bg_color256(int code, const char *s) {
    char buf[32];
    snprintf(buf, sizeof(buf), "\033[48;5;%dm", code);
    return hagoromo_wrap(buf, s);
}

/* RGB/truecolor */
static inline char *hagoromo_rgb(int r, int g, int b, const char *s) {
    char buf[32];
    snprintf(buf, sizeof(buf), "\033[38;2;%d;%d;%dm", r, g, b);
    return hagoromo_wrap(buf, s);
}

static inline char *hagoromo_bg_rgb(int r, int g, int b, const char *s) {
    char buf[32];
    snprintf(buf, sizeof(buf), "\033[48;2;%d;%d;%dm", r, g, b);
    return hagoromo_wrap(buf, s);
}

static inline void hagoromo_free(char *s) { free(s); }

#endif /* HAGOROMO_H */
