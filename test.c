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
        repaint(60);
    }
    
    return closeDisplay();
}