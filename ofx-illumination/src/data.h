#ifndef DATA_H
#define DATA_H

#include "ofMain.h"
#include "ofxXmlSettings.h"

class Data
{
public:
    Data();
    void load();

    //vars
    ofxXmlSettings dataXml;
};

#endif // DATA_H
