#include "word.h"

Word::Word(string t, ofRectangle r)
{
    text = t;
    rect = r;
}

Word::light(){
    ofSetColor(100,100,100,.5);
    ofRect(rect);
}
