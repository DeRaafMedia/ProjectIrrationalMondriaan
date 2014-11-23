#pragma once

//
//  ofApp.h
//  ProjectIrrationalMondriaan
//
//  Created by Remco Platjes on 19-11-14.
//
//
#include "ofMain.h"
#include "rectangles.h"
#include "ofxSimpleSerial.h"

#define _USE_LIVE_VIDEO

class ofApp : public ofBaseApp {
    public:
    
        void setup();
        void update();
        void draw();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    bool showInfo;
    bool showSquaresId;
    bool oscEnabled;
    
    int displayResolutionWidth, displayResolutionHeight;
    float midlineWidth, midlineHeight;
    float fullscreenWidthOffset, fullscreenHeightOffset;
    
    rectangles rectangle_1;
    
    ofxSimpleSerial	serial;
    
    string message;
    
    bool button_1;
    bool button_2;
    bool button_3;
    bool button_4;
    bool noColor;
    bool requestRead;
    void onNewMessage(string & message);
    int redColor;
    int greenColor;
    int blueColor;
    bool randomColorIsSet;
    
};