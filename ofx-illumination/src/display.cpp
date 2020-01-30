#include "display.h"

DisplaySystem::DisplaySystem()
{
    mode = "CALIBRATE";
}

void DisplaySystem::setup(int w, int h){
    fbo.allocate(w,h, GL_RGBA);
    wordIndex = 0;
}

void DisplaySystem::update(){
    //draw to FBO
   if(mode == "CALIBRATE"){
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
   else if(mode == "RANDOM"){
        if(wordsVector.size()){
            int wordIndex =  (int) round(ofRandom(wordsVector.size()-1));
            lightWord(wordIndex);
        }
    }
   else if(mode == "SEQUENCE"){
        if(wordsVector.size()){
            wordIndex++;
            if(wordIndex>=wordsVector.size()-1)
                wordIndex = 0;

            lightWord(wordIndex);
        }
    }
   /* if(test){
        if(wordsVector.size()){
            int rand =  (int) round(ofRandom(wordsVector.size()));
            lightWord(rand);
        }
    }
    else{
        fbo.begin();
            ofBackground(0,10);
            ofSetColor(lightColor);
            //draw all words
            for (Word & word : wordsVector) {
                word.padding = padding;
                word.light();
            }
        fbo.end();
    }*/
}

void DisplaySystem::lightWord(int index){
    //draw to FBO
    fbo.begin();
        ofBackground(0,10);
        ofSetColor(lightColor);
        Word & word = wordsVector[index];
        word.padding = padding;
        word.light();
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
