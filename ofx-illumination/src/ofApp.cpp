#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    ic.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int x = 0;
    int y = 0;
    float scaleX = 1;
    float scaleY = 1;

    ic.draw(x,y,scaleX,scaleY);
    display.draw(x,y,scaleX,scaleY);
}

void ofApp::runOCR(){
    //save video capture to file
    cout<<"run ocr"<<endl;
    ic.saveImage();
    //run tesseract on the saved image
    system("tesseract data/capture.png data/output -l eng -psm hocr");
    //load the ocr data
    data.load();
    display.wordsVector = data.wordsVector;
   // display.dataXml = data.dataXml;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        runOCR();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
