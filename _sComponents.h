/**
 * @author Kia Kalani
 * This header file contains all of the necessary components for making the scene functional.
 * @version 1.00
 * @since 1.00
 */
#include <X11/Xlib.h>
#include <pthread.h>
#include <stdlib.h>
#include "kScene.h"
// The color converter
#define convertRGB(color) (color.r << 16) + (color.g << 8) + color.b

/**
 * The structure that contains all of the display related components.
 */
typedef struct 
{
    int x, y, mouseX, mouseY, mouseCache;
    unsigned int width, height;
    Display *display;
    Window window, receivedWindow;
    GC gc;
    XEvent nextEvent;
    pthread_t keyE;
    pthread_t mouseE;
    Color color;
}Scene;
/**
 * The instance of our scene.
 */
Scene *scene;
/**
 * The method that would be invoked when mouse is being pressed.
 */
void (*__m__p)(char key) = NULL;
/**
 * The method that would be invoked when mouse is being released.
 */
void (*__m__r)(char key) = NULL;
/**
 * The method that would be invoked when the key is being pressed.
 */
void (*__k__p)(char key) = NULL;
/**
 * The method that would be invoked when the key is being released.
 */
void (*__k__r)(char key);
/**
 * This method is responsible for handling the key events related to the thread.
 */
void *handleKeyEvenets();
/**
 * This method is responsible for handling the mouse events related to the thread.
 */
void *handleMouseEvents();
/**
 * This method is responsible for handling the display events related to the thread.
 */
void *handleResizeEvents();