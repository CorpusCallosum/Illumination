#include "word.h"

Word::Word(string t, ofRectangle r)
{
    text = t;
    rect = r;
}

void Word::light(){
    //ofSetColor(200,100,100,100);
    ofDrawRectangle(rect.x-padding,
                    rect.y-padding,
                    rect.width+padding*2,
                    rect.height+padding*2);
    //ofDrawRectangle(rect);
   // cout<<"light "<<text;
}

int Word::length(){
    return text.size();
}
