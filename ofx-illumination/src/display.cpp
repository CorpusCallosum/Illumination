#include "display.h"

DisplaySystem::DisplaySystem()
{

}

void DisplaySystem::setup(int w, int h){
    fbo.allocate(w,h, GL_RGBA);
}

void DisplaySystem::update(){
    //draw to FBO
    fbo.begin();
        ofBackground(0,10);
        ofSetColor(lightColor);
        //draw all words
        for (Word & word : wordsVector) {
            word.padding = padding;
            word.light();
        }
    fbo.end();
}

void DisplaySystem::draw(int x, int y, float scaleX, float scaleY){

    fbo.draw(x,y,scaleX*fbo.getWidth(),scaleY*fbo.getHeight());

}

void DisplaySystem::clear(){
    //clear out words vector
    wordsVector.clear();
}

void DisplaySystem::updateData(ofxXmlSettings d){

}
