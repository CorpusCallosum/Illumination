#ifndef GUI_H
#define GUI_H

#include "ofMain.h"
#include "ofxGui.h"

class GUI
{
public:
    GUI();
    void draw();
    void shiftUp();
    void shiftRight();
    void shiftDown();
    void shiftLeft();
    void scaleDown();
    void scaleUp();
    void save();

    ofParameter<float> xPos, yPos, xScale, yScale, padding;

   // ofxIntSlider xPos, yPos;
   // ofxFloatSlider xScale, yScale;
    ofxPanel guiPanel;
    float shiftAmt, scaleAmt;
    ofParameter<ofColor> lightColor;


};

#endif // GUI_H
