#include "imagecapture.h"

ImageCapture::ImageCapture()
{
    camWidth = 320;  // try to grab at this size.
    camHeight = 240;

    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);


    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ImageCapture::update(){
    ofBackground(100, 100, 100);
    vidGrabber.update();
}

//--------------------------------------------------------------
void ImageCapture::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber.draw(20, 20);
}
