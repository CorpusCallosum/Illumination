#ifndef WORD_H
#define WORD_H

#include "ofMain.h"


class Word
{
public:
    Word(string t, ofRectangle r);
    void light();

    //vars
    string text;
    ofRectangle rect;
};

#endif // WORD_H
