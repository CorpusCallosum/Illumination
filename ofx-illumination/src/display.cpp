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
        //draw all words
        for (Word & word : wordsVector) {
            word.light();
        }
    fbo.end();
}

void DisplaySystem::draw(int x, int y, float scaleX, float scaleY){

    //draw to FBO
    //fbo.begin();
        //draw all words
        //for (Word & word : wordsVector) {
      //      word.light();
      //  }
    //fbo.end();

    fbo.draw(x,y,scaleX*fbo.getWidth(),scaleY*fbo.getHeight());

}

void DisplaySystem::updateData(ofxXmlSettings d){

}
