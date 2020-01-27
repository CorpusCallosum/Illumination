#ifndef IMAGECAPTURE_H
#define IMAGECAPTURE_H

#include "ofMain.h"

class ImageCapture
{
public:
    ImageCapture();
    void update();
    void draw();
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
};

#endif // IMAGECAPTURE_H
