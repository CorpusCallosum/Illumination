#ifndef DISPLAY_H
#define DISPLAY_H

#include "ofMain.h"
#include "ofxXmlSettings.h"

class DisplaySystem
{
public:
    DisplaySystem();
    void draw();
    void updateData(ofxXmlSettings d);
    ofxXmlSettings dataXml;
};

#endif // DISPLAY_H
