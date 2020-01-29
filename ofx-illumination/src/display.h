#ifndef DISPLAY_H
#define DISPLAY_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "word.h"

class DisplaySystem
{
public:
    DisplaySystem();
    void setup(int w, int h);
    void update();
    void draw(int x, int y, float scaleX, float scaleY);
    void updateData(ofxXmlSettings d);

    //vars
    ofxXmlSettings dataXml;
    vector<Word> wordsVector;
    float xScale, yScale;

private:
    ofFbo fbo;
};

#endif // DISPLAY_H
