#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 1920;
    camHeight = 1080;
    ic.setup(camWidth,camHeight);
    display.setup(camWidth,camHeight);
    gui.setup(camWidth,camHeight);
    drawCamera = true;

    //setup serial to read data from arduino microcomputer
    int baud = 9600;
    serialSuccess = serial.setup("/dev/ttyACM0", baud); //linux example
    cout<<"serialSuccess: "<<serialSuccess<<endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(serialSuccess){
        //read data from serial
        serial.readBytes(bytesReturned, 2);

        if(strcmp(bytesReturned, bytesRead) != 0){
            //they are different, issue a state change
            memcpy(bytesRead, bytesReturned, 2);
            cout<<"bytesRead: "<< bytesRead << endl;
            updateState(bytesRead);
        }
    }

    //update app settings from GUI
    display.lightColor = gui.lightColor;
    display.padding = gui.padding;

    display.update();
}

void ofApp::updateState(char* state){
   // cout<<state<<endl;
  //  int ss = *state;
   // cout<<ss<<endl;
    switch (*state){
        case 49:
            cout<<"state: open"<<endl;
            break;
        case 50:
            cout<<"state: closed/empty"<<endl;
            break;
        case 51:
            cout<<"state: ready"<<endl;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int x = gui.xPos;
    int y = gui.yPos;
    float scaleX = gui.xScale;
    float scaleY = gui.yScale;

    //clear screen
    ofBackground(0);

    //apply rotation
    ofPushMatrix();

    //offset to center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(gui.rotation);
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);

    if(drawCamera){
       ic.update();
       ic.draw(x,y,scaleX,scaleY);
    }

    display.draw(x,y,scaleX,scaleY);
    ofPopMatrix();

    display.drawAfter();

    gui.draw();
}

void ofApp::runOCR(){
    //save video capture to file
    cout<<"run ocr"<<endl;
    ic.update();
    ic.saveImage();

    //run tesseract on the saved image
    //TODO: this should happen asynch
    system("tesseract data/capture.png data/output -l eng+deu -psm hocr"); //english and german

    //load the ocr data
    data.loadOutputOCR();
    display.wordsVector = data.wordsVector;

    //generate poem
    system("ls");
    cout<<data.text<<endl;
    string cmd = "python writepoem.py '"+data.text+"'";
    system(cmd.c_str());

    //load the poem text file
    vector<int> poem = data.loadPoem();
    drawCamera = false;
    display.readPoem(poem);
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
        //display.mode = "CALIBRATE";
        //if(drawCamera)
          //  display.reset();
    break;
    case 's':
        display.mode = "SEQUENCE";
        display.clear();
    break;
    case 'd':
        display.clear();
    break;
    case 't':
        display.mode = "RANDOM";
        display.clear();
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
    case ']':
        gui.rotate(+1);
    break;
    case '[':
        gui.rotate(-1);
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
    //move image with mouse
    gui.mouseMove(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    gui.startMouseMove(x,y);
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
