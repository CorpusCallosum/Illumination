#ifndef DATA_H
#define DATA_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "word.h"

class Data
{
public:
    Data();
    void load();
    ofRectangle parseRect(string d);

    //vars
    ofxXmlSettings dataXml;
    vector<Word> wordsVector;

};

#endif // DATA_H
