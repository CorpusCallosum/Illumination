#pragma once

#include "ofMain.h"
#include "imagecapture.h"
#include "data.h"
#include "display.h"
#include "ofxXmlSettings.h"
#include "gui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void runOCR();
        void snapShot();
        void updateState(char *state);
        void generateNewPoem();
        void calibrate(bool c);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void exit();

        ImageCapture ic;
        Data data;
        DisplaySystem display;
        ofxXmlSettings ocrXml;
        GUI gui;

        bool drawCamera, alt, test, serialSuccess, isCalibrating;
        int camWidth, camHeight, mouseX, mouseY;

        ofSerial	serial;
        char		bytesReturned[2];				// data from serial, we will be trying to read 3
        char		bytesRead[2];
        int         lastReadByte;

};
