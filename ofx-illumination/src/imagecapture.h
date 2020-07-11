#ifndef IMAGECAPTURE_H
#define IMAGECAPTURE_H

#include "ofMain.h"

class ImageCapture
{
public:
    ImageCapture();
    void setup(int w, int h);
    void update();
    void draw(int x, int y, float scaleX, float scaleY);
    void saveImage();
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    ofImage image;
};

#endif // IMAGECAPTURE_H
