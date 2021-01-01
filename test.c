#include "kScene.h"
#include <stdio.h>
/**
 * For debugging only
 */
int main()
{
    initDisplay(1024, 768, "something", rgb(200, 200, 0));
    int x = 0;
    int y = 0;
    while (1)
    {
        x += 2;
        y += 2;
        fillRect(x, y, 30, 30, rgb(200, 0, 0));
        fillCircle(0, 0, 30, rgb(0, 0, 255));
        drawLine(50, 50, x, y, rgb(69, 69, 200));
        repaint(60);
    }
    
    return closeDisplay();
}