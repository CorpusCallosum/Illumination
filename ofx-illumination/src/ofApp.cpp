#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 1920;
    camHeight = 1080;
    ic.setup(camWidth,camHeight);
    display.setup(camWidth,camHeight);
    gui.setup(camWidth,camHeight);
    drawCamera = true;
}

//--------------------------------------------------------------
void ofApp::update(){
   // if(drawCamera)
     //   ic.update();

    //update app settings from GUI
    display.lightColor = gui.lightColor;
    display.padding = gui.padding;

    display.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    int x = gui.xPos;
    int y = gui.yPos;
    float scaleX = gui.xScale;
    float scaleY = gui.yScale;

    //clear screen
    ofBackground(0);

    if(drawCamera){
       // if(alt){
            ic.update();
      //  }
       // else{
            ic.draw(x,y,scaleX,scaleY);
      //  }
    }

    display.draw(x,y,scaleX,scaleY);

    gui.draw();

    alt = !alt;
}

void ofApp::runOCR(){
    //save video capture to file
    cout<<"run ocr"<<endl;
    ic.update();
    ic.saveImage();
    //run tesseract on the saved image
    system("tesseract data/capture.png data/output -l eng -psm hocr");
    //load the ocr data
    data.load();
    display.wordsVector = data.wordsVector;
   // display.dataXml = data.dataXml;
}

void ofApp::snapShot(){
    ic.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   /* if(key == ' '){
        runOCR();
    }*/
    switch (key){
    case ' ':
        runOCR();
        break;
    case 'f':
        ofToggleFullscreen();
        break;
    case 'c':
        drawCamera = !drawCamera;
        display.mode = "CALIBRATE";
    break;
    case 's':
        display.mode = "SEQUENCE";
    break;
    case 'd':
        display.clear();
    break;
    case 't':
        display.mode = "RANDOM";
    break;
    case OF_KEY_UP:
        gui.shiftUp();
    break;
    case OF_KEY_RIGHT:
        gui.shiftRight();
    break;
    case OF_KEY_DOWN:
        gui.shiftDown();
    break;
    case OF_KEY_LEFT:
        gui.shiftLeft();
    break;
    case ',':
        gui.scaleDown();
    break;
    case '.':
        gui.scaleUp();
    break;
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

//ON EXIT
//--------------------------------------------------------------
void ofApp::exit(){
    gui.save();
}
