/**
 * @author Kia Kalani
 * This header file contains the components of the display structure.
 * This can be used in order to create a simple display for the users.
 * @version 1.00
 * @since 1.00
 */


/**
 * The color structure. The user can utilize this structure in order to set the color for the
 * shapes or the background.
 */
typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Color;

typedef char *String;

/**
 * This method is responsible for initializing the display according to the provided components.
 * @param width is the width of the display.
 * @param height is the height of the display.
 * @param title is the title of the display.
 * @param background is the color of the background.
 */
void initDisplay(unsigned int width, unsigned height, String title, Color background);

/**
 * This method is responsible for closing the display.
 * @return 0 if the display has been closed successfully.
 */
char closeDisplay();

/**
 * This method is responsible for updating the display.
 * @param fps is the number of the frames per second the user wants to updates the
 * display for.
 */
void repaint(unsigned char fps);

/**
 * This method will draw a rectangle to the display.
 * @param x is the x position of the rectangle.
 * @param y is the y position of the rectangle.
 * @param width is the width of the rectangle.
 * @param height is the height of the rectangle.
 * @param color the color of the rectangle.
 */
void drawRect(int x, int y, unsigned int width, unsigned int height, Color color);

/**
 * This method will fill a rectangle to the display.
 * @param x is the x position of the rectangle.
 * @param y is the y position of the rectangle.
 * @param width is the width of the rectangle.
 * @param height is the height of the rectangle.
 * @param color the color of the rectangle.
 */
void fillRect(int x, int y, unsigned int width, unsigned int height, Color color);

/**
 * This method is responsible for drawing a line to the display.
 * @param x the starting x coordinate for the line.
 * @param y the starting y coordinate for the line.
 * @param x2 the ending x coordinate for the line.
 * @param y2 the ending y coordinate for the line.
 * @param color the color of the line.
 */
void drawLine(int x, int y, int x2, int y2, Color color);

/**
 * This method will draw a circle to the display.
 * @param x the x coordinate of the circle.
 * @param y the y coordinate of the circle.
 * @param radius the radius of the circle.
 * @param color the color of the circle.
 */
void drawCircle(int x, int y, unsigned int radius, Color color);

/**
 * This method will fill a circle to the display.
 * @param x the x coordinate of the circle.
 * @param y the y coordinate of the circle.
 * @param radius the radius of the circle.
 * @param color the color of the circle.
 */
void fillCircle(int x, int y, unsigned int radius, Color color);

/**
 * This method is responsible for setting the events for the times
 * that the mouse has been pressed.
 * @param pressed is the function that will be called when the mouse
 * has been pressed.
 */
void setOnMousePressed(void (*pressed)(char key));

/**
 * This method is responsible for setting the events for the times
 * that the mouse has been released.
 * @param released is the function that will be called when the mouse
 * has been released.
 */
void setOnMouseReleased(void (*released)(char key));

/**
 * This method is responsible for setting the events for the times
 * that the key has been pressed.
 * @param pressed is the function that will be called when the key
 * has been pressed.
 */
void setOnKeyPressed(void (*pressed)(char key));

/**
 * This method is responsible for setting the events for the times
 * that the key has been released.
 * @param released is the function that will be called when the key
 * has been released.
 */
void setOnKeyReleased(void (*released)(char key));

/**
 * This method provides the x position of the mouse.
 * @return the x position of the mouse.
 */
int mouseX();

/**
 * This method provides the y position of the mouse.
 * @return the y position of the mouse.
 */
int mouseY();

/**
 * This method provides the color according to the provided coordinates.
 * @param r is the red portion of the color.
 * @param g is the grreen portion of the color.
 * @param b is the blue portion of the color.
 * @return a color according to these components.
 */
Color rgb(unsigned char r, unsigned char g, unsigned char b);