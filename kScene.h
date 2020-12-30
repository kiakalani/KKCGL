typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Color;
typedef char *String;
void initDisplay(unsigned int width, unsigned height, String title, Color background);
char closeDisplay();
void repaint(unsigned char fps);
void drawRect(int x, int y, unsigned int width, unsigned int height, Color color);
void fillRect(int x, int y, unsigned int width, unsigned int height, Color color);
void drawLine(int x, int y, int x2, int y2, Color color);
void drawCircle(int x, int y, unsigned int radius, Color color);
void fillCircle(int x, int y, unsigned int radius, Color color);
void setOnMousePressed(void (*pressed)());
void setOnMouseReleased(void (*released)());
void setOnKeyPressed(void (*pressed)());
void setOnKeyReleased(void (*released)());