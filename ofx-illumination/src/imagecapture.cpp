#include "imagecapture.h"

ImageCapture::ImageCapture()
{
    camWidth = 1920;  // try to grab at this size.
    camHeight = 1080;

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
    image.allocate(camWidth, camHeight, OF_IMAGE_COLOR);

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

void ImageCapture::saveImage(){
    cout<<"save image"<<endl;
    ofPixels & pixels = vidGrabber.getPixels();
    image.setFromPixels(pixels);
    image.save("capture.png");
}





