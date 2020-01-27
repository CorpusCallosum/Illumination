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
    ic.draw();
    display.draw();
}

void ofApp::runOCR(){
    //save video capture to file
    cout<<"run ocr"<<endl;
    ic.saveImage();
    //run tesseract on the saved image
    system("tesseract data/capture.png data/output -l eng -psm 1 hocr");
    //load the ocr data
    ocrXml.load("output.hocr");
    //display.dataXml = ocrXml;
    display.updateData(ocrXml)
   // data.load();
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
