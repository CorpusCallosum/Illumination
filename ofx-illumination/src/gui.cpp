#include "gui.h"

GUI::GUI()
{
    shiftAmt = .2;
    scaleAmt = .001;

    int w = 500;
    guiPanel.setup("GUI","gui_settings.xml", ofGetWindowWidth()-w-10, 10);
    //guiPanel.setSize(w,w);

    //calibration
    guiPanel.add(xPos.set("X", 0, 0, 1000));
    guiPanel.add(yPos.set("Y", 0, 0, 1000));
    guiPanel.add(xScale.set("X Scale", 1, 0, 1));
    guiPanel.add(yScale.set("Y Scale", 1, 0, 1));
    guiPanel.add(padding.set("Padding", 2, 0, 20));

    //color
    guiPanel.add(lightColor.set("Color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));

    //setup listeners
    //xScale.addListener(this, &GUI::onScaleX);

    //load settings
    guiPanel.loadFromFile("gui_settings.xml");
}

void GUI::setup(int cw, int ch){
    camWidth = cw;
    camHeight = ch;
}

void GUI::draw(){
    guiPanel.draw();
}

/*void GUI::onScaleX(float & newValue){
}*/


void GUI::shiftUp(){
    yPos -= shiftAmt;
}

void GUI::shiftRight(){
    xPos += shiftAmt;
}

void GUI::shiftDown(){
    yPos += shiftAmt;
}

void GUI::shiftLeft(){
    xPos -= shiftAmt;
}

void GUI::scaleUp(){
    xScale += scaleAmt;
    yScale += scaleAmt;
    xPos -= (scaleAmt*camWidth)/2;
    yPos -= (scaleAmt*camHeight)/2;
}

void GUI::scaleDown(){
    xScale -= scaleAmt;
    yScale -= scaleAmt;
    xPos += (scaleAmt*camWidth)/2;
    yPos += (scaleAmt*camHeight)/2;
}

void GUI::save(){
    //save current XML state
    guiPanel.saveToFile("gui_settings.xml");
}
