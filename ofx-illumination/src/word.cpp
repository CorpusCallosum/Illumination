#include "word.h"

Word::Word(string t, ofRectangle r)
{
    text = t;
    rect = r;
}

void Word::light(){
    ofSetColor(200,100,100,100);
    ofDrawRectangle(rect);
   // cout<<"light "<<text;
}
