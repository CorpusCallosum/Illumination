#include "display.h"

DisplaySystem::DisplaySystem()
{
    mode = "CALIBRATE";
}

void DisplaySystem::setup(int w, int h){
    fbo.allocate(w,h, GL_RGBA);
    wordIndex = 0;
    waitTime = 0;
    poemCompleted = false;
    showGrid = false;
}

void DisplaySystem::update(){
    if(fade){
        fbo.begin();
            ofSetColor(0,10);
            ofDrawRectangle(0,0,ofGetWindowWidth(), ofGetWindowHeight());
        fbo.end();
    }

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
          else if(mode == "POEM"){
              if(wordsVector.size()){
                  if(wordIndex>=_poem.size()-1){
                    //poem completed
                      poemCompleted = true;
                      return;
                  }
                  int i = _poem[wordIndex];
                  if(i == -1){
                      //consider as newline
                      fade = true;
                      pauseFor(1000);
                  }
                  else{
                      //light word
                      fade = false;
                      lightWord(i);
                      pauseForWordAt(i);
                  }

                  wordIndex++;
              }
          }

          //light next word after elapsed time
         // cout<<"elapsed time: "<<ofGetElapsedTimeMillis()<<endl;
         // cout<<"wait time: "<<waitTime<<endl;

           }

    fbo.draw(x,y,scaleX*fbo.getWidth(),scaleY*fbo.getHeight());
}

//called after matrix popped
void DisplaySystem::drawAfter(){
    if(mode == "CALIBRATE"){
         drawGrid();
     }
}

void DisplaySystem::drawGrid(){
    float size = 100;
    ofSetLineWidth(1);
    ofSetColor(100,50);
    int w = ofGetWidth();
    int h = ofGetHeight();

    for(float i=0; i<=size; i++){
        float y = (i/size)*h;
        //horizontal lines
        ofDrawLine(0,y,w,y);
        //vertical lines
        float x = (i/size)*w;
        ofDrawLine(x,0,x,h);
    }
    ofSetColor(255);
}

void DisplaySystem::clear(){
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

void DisplaySystem::pauseFor(int t){
    waitTime = ofGetElapsedTimeMillis()+t;
}

void DisplaySystem::pauseForWordAt(int i){
    waitTime = ofGetElapsedTimeMillis()+getTimeForWordAt(i);
}

int DisplaySystem::getTimeForWordAt(int i){
     Word & word = wordsVector[i];
     //this should be an inverse exponential curve based on word length
     //return log2(word.length())*250+200;
     return sqrt(word.length())*300;
}

void DisplaySystem::readPoem(vector<int> poem){
    poemCompleted = false;
    _poem = poem;
    mode = "POEM";
    wordIndex = 0;
}
