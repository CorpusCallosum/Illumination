#ifndef DISPLAY_H
#define DISPLAY_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "word.h"

class DisplaySystem
{
public:
    DisplaySystem();
    void draw();
    void updateData(ofxXmlSettings d);

    //vars
    ofxXmlSettings dataXml;
    vector<Word> wordsVector;
    float xScale, yScale;
};

#endif // DISPLAY_H
