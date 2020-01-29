#ifndef GUI_H
#define GUI_H

#include "ofMain.h"
#include "ofxGui.h"

class GUI
{
public:
    GUI();
    void draw();

    ofxIntSlider xPos, yPos;
    ofxFloatSlider xScale, yScale;
    ofxPanel guiPanel;
};

#endif // GUI_H
