#include "display.h"

DisplaySystem::DisplaySystem()
{

}

void DisplaySystem::draw(int x, int y, float scaleX, float scaleY){
    //draw all words
    for (Word & word : wordsVector) {
        word.light();
    }
}

void DisplaySystem::updateData(ofxXmlSettings d){
    //
}
