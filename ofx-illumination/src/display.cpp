#include "display.h"

DisplaySystem::DisplaySystem()
{
    mode = "CALIBRATE";
}

void DisplaySystem::setup(int w, int h){
    fbo.allocate(w,h, GL_RGBA);
    wordIndex = 0;
    waitTime = 0;
}

void DisplaySystem::update(){
    /*if(clearOnce){
        fbo.clear();
        clearOnce = false;
    }*/

    //draw to FBO

    //fbo.begin();
       // ofSetColor(0,2);
       // ofDrawRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    //fbo.end();


}

void DisplaySystem::lightWord(int index){
    //draw to FBO
    fbo.begin();
        //ofBackground(0,10);
        //ofSetColor(0,10);
        //ofDrawRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight());
        ofSetColor(lightColor);
        if(wordsVector.size()){
            Word & word = wordsVector[index];
            word.padding = padding;
            word.light();
        }
    fbo.end();

}

void DisplaySystem::draw(int x, int y, float scaleX, float scaleY){

    if(ofGetElapsedTimeMillis()>waitTime){

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
                   pauseForWordAt(wordIndex);
               }
           }
          else if(mode == "SEQUENCE"){
               if(wordsVector.size()){
                   wordIndex++;
                   if(wordIndex>=wordsVector.size()-1)
                       wordIndex = 0;

                   lightWord(wordIndex);
                  // ofSleepMillis(100);
               }
           }

          //light next word after elapsed time
          cout<<"elapsed time: "<<ofGetElapsedTimeMillis()<<endl;
          cout<<"wait time: "<<waitTime<<endl;

              // lightWord(wordIndex);
           }

    fbo.draw(x,y,scaleX*fbo.getWidth(),scaleY*fbo.getHeight());



}

void DisplaySystem::clear(){
    //fbo.clear();
    //clear out words vector
    //wordsVector.clear();
    //fbo.clear();
    /*if(mode == "CALIBRATE"){
        mode = "OFF";
    }*/
    fbo.begin();
    ofSetColor(0);
    ofDrawRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    fbo.end();
}

void DisplaySystem::reset(){
    //clear out words vector
    wordsVector.clear();
}

void DisplaySystem::calibrate(){
    clearOnce = false;
}

void DisplaySystem::pauseForWordAt(int i){
    //ofSleepMillis(getTimeForWordAt(i));
    waitTime = ofGetElapsedTimeMillis()+getTimeForWordAt(i);
}

int DisplaySystem::getTimeForWordAt(int i){
     Word & word = wordsVector[i];
     return word.length()*100+200;
}

void DisplaySystem::updateData(ofxXmlSettings d){

}
