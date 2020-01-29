#include "display.h"

DisplaySystem::DisplaySystem()
{

}

void DisplaySystem::draw(){
    //draw all words
    for (Word & word : wordsVector) {
        word.light();
    }
}

void DisplaySystem::updateData(ofxXmlSettings d){
    //
}
