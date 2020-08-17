#ifndef GUI_H
#define GUI_H

#include "ofMain.h"
#include "ofxGui.h"

class GUI
{
public:
    GUI();
    void setup(int cw, int ch);
    void draw();
    void startMouseMove(int x, int y);
    void mouseMove(int x, int y);
    void shiftUp();
    void shiftRight();
    void shiftDown();
    void shiftLeft();
    void scaleDown();
    void scaleUp();
    void rotate(float dir);
    void save();

    ofParameter<float> xPos, yPos, xScale, yScale, rotation, padding;

   // ofxIntSlider xPos, yPos;
   // ofxFloatSlider xScale, yScale;
    ofxPanel guiPanel;
    float shiftAmt, scaleAmt;
    ofParameter<ofColor> lightColor;
    int camWidth, camHeight, mouseX, mouseY, lastXPos, lastYPos;


};

#endif // GUI_H
