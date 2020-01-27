#ifndef IMAGECAPTURE_H
#define IMAGECAPTURE_H

#include "ofMain.h"

class ImageCapture
{
public:
    ImageCapture();
    void update();
    void draw();
    void saveImage();
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    ofImage image;
};

#endif // IMAGECAPTURE_H
