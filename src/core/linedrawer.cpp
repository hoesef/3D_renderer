#include "linedrawer.h"
#include <stdlib.h>

int drawline(FrameBuffer& fb, int x1, int y1, int x2, int y2) {

    int dx = x2-x1;
    int dy = y2-y1;

    if (dx == 0 && dy == 0) {
        return fb.plotPixel(x1, y1, 1, 1, 1);
    }


    int step = (abs(dx) > abs(dy)) ? abs(dx):abs(dy);

    float xinc = (float)dx/(float)step;
    float yinc = (float)dy/(float)step;

    float x = (float) x1;
    float y = (float) y1;

    for (int i = 0; i < step; i++) {
        fb.plotPixel(x, y, 1, 1, 1);
        x += xinc;
        y += yinc;
    }

    return 0;

}