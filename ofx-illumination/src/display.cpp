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
        int lastIndex = wordIndex;
        if(wordsVector.size()){
            wordIndex =  (int) round(ofRandom(wordsVector.size()-1));
            lightWord(wordIndex);
            pauseForWordAt(lastIndex);
        }
    }
   else if(mode == "SEQUENCE"){
        if(wordsVector.size()){
            wordIndex++;
            if(wordIndex>=wordsVector.size()-1)
                wordIndex = 0;

            lightWord(wordIndex);
            ofSleepMillis(100);
        }
    }
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

void DisplaySystem::pauseForWordAt(int i){
    ofSleepMillis(getTimeForWordAt(i));
}

int DisplaySystem::getTimeForWordAt(int i){
     Word & word = wordsVector[i];
     return word.length()*100+200;
}

void DisplaySystem::updateData(ofxXmlSettings d){

}
