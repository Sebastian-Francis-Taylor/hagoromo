#include "hagoromo.h"
#include <stdio.h>

int main(void) {
    hagoromo_init();

    char *r = hagoromo_red("red");
    printf("%s\n", r);
    hagoromo_free(r);

    char *g = hagoromo_green("green");
    printf("%s\n", g);
    hagoromo_free(g);

    char *b = hagoromo_blue("blue");
    printf("%s\n", b);
    hagoromo_free(b);

    char *bold = hagoromo_bold("bold text");
    printf("%s\n", bold);
    hagoromo_free(bold);

    char *ul = hagoromo_underline("underlined");
    printf("%s\n", ul);
    hagoromo_free(ul);

    // stacking
    char *t1 = hagoromo_bold("bold red");
    char *t2 = hagoromo_red(t1);
    printf("%s\n", t2);
    hagoromo_free(t1);
    hagoromo_free(t2);

    // bg colors
    char *bg = hagoromo_bg_blue("blue background");
    printf("%s\n", bg);
    hagoromo_free(bg);

    // bright colors
    char *bright = hagoromo_bright_magenta("bright magenta");
    printf("%s\n", bright);
    hagoromo_free(bright);

    // 256 color
    char *c256 = hagoromo_color256(208, "orange-ish (256 mode)");
    printf("%s\n", c256);
    hagoromo_free(c256);

    // rgb
    char *rgb = hagoromo_rgb(255, 100, 50, "custom rgb color");
    printf("%s\n", rgb);
    hagoromo_free(rgb);

    printf("\n");

    // practical use
    char *err = hagoromo_bright_red("ERROR: file not found");
    printf("%s\n", err);
    hagoromo_free(err);

    char *warn = hagoromo_yellow("WARNING: deprecated function");
    printf("%s\n", warn);
    hagoromo_free(warn);

    char *ok = hagoromo_green("SUCCESS: build complete");
    printf("%s\n", ok);
    hagoromo_free(ok);

    return 0;
}
