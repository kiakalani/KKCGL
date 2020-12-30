#include "_sComponents.h"
#include <unistd.h>
#include <stdio.h>

/**
 * @author Kia Kalani
 * The actual logic fully coded can be found here.
 * @version 1.00
 * @since 1.00
 */


Color rgb(unsigned char r, unsigned char g, unsigned char b)
{
    Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    return color;
}

void initDisplay(unsigned int width, unsigned height, String title, Color background)
{
    XInitThreads();
    scene = (Scene*) calloc(sizeof(Scene), 1);
    printf("something\n");

    scene->display = XOpenDisplay(NULL);
    scene->window = XCreateSimpleWindow(scene->display, RootWindow(scene->display, 0), 0, 0, width, height, 0, 0, convertRGB(background));
    scene->gc = XCreateGC(scene->display, scene->window, 0, NULL);
    XMapWindow(scene->display, scene->window);
    XFlush(scene->display);
    usleep(10000);
    XStoreName(scene->display, scene->window, title);
    scene->color = background;
    scene->width = width;
    scene->height = height;
}

char closeDisplay()
{
    XUnmapWindow(scene->display, scene->window);
    XDestroyWindow(scene->display, scene->window);
    XFreeGC(scene->display, scene->gc);
    XCloseDisplay(scene->display);
    free(scene);
    return 0;
}

void fillRect(int x, int y, unsigned int width, unsigned int height, Color color)
{
    XSetForeground(scene->display, scene->gc, convertRGB(color));
    XFillRectangle(scene->display, scene->window, scene->gc, x, y, width, height);
}

void repaint(unsigned char fps)
{
    XFlush(scene->display);
    usleep(1000000 / fps);
    fillRect(scene->x, scene->y, scene->width, scene->height, scene->color);
}