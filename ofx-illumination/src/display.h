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
    void clear();
    void calibrate();
    void reset();
    void lightWord(int index);
    void pauseForWordAt(int i);
    void pauseFor(int t);
    int getTimeForWordAt(int i);
    void readPoem(vector<int> poem);

    //vars
    ofxXmlSettings dataXml;
    vector<Word> wordsVector;
    float xScale, yScale, padding, waitTime;
    ofColor lightColor;
    bool test, clearOnce, poemCompleted, fade;
    string mode;
    int wordIndex;

private:
    ofFbo fbo;
    vector<int> _poem;
};

#endif // DISPLAY_H
