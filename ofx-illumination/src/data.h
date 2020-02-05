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
    vector<int> loadPoem();
    ofRectangle parseRect(string d);

    //vars
    ofxXmlSettings dataXml;
    vector<Word> wordsVector;
    vector<int> poemDataVector;
    string text;


private:
    void addWord(string wordText, ofRectangle rect);
    void removeChar(string c);

};

#endif // DATA_H
