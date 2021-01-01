#include "_sComponents.h"
#include <unistd.h>

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
    scene->display = XOpenDisplay(NULL);
    scene->window = XCreateSimpleWindow(scene->display, RootWindow(scene->display, 0), 0, 0, width, height, 0, 0, convertRGB(background));
    scene->gc = XCreateGC(scene->display, scene->window, 0, NULL);
    XSelectInput(scene->display, scene->window, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ExposureMask);
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

void drawRect(int x, int y, unsigned int width, unsigned int height, Color color)
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

void fillCircle(int x, int y, unsigned int radius, Color color)
{
    XSetForeground(scene->display, scene->gc, convertRGB(color));
    XFillArc(scene->display, scene->window, scene->gc, x - (radius / 2), y - (radius / 2), radius, radius, 0, 360 * 64);
}

void drawCircle(int x, int y, unsigned int radius, Color color)
{
    XSetForeground(scene->display, scene->gc, convertRGB(color));
    XDrawArc(scene->display, scene->window, scene->gc, x - (radius / 2), y - (radius / 2), radius, radius, 0, 360 * 64);
}

void drawLine(int x, int y, int x2, int y2, Color color)
{
    XSetForeground(scene->display, scene->gc, convertRGB(color));
    XDrawLine(scene->display, scene->window, scene->gc, x, y, x2, y2);
}

int mouseX()
{
    return scene->mouseX;
}

int mouseY()
{
    return scene->mouseY;
}