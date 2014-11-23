//
//  ofApp.cpp
//  ProjectIrrationalMondriaan
//
//  Created by Remco Platjes on 19-11-14.
//
//
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/");
    
    showInfo = false;
    showSquaresId = false;
    oscEnabled = false;
    
    displayResolutionWidth = 1280;
    displayResolutionHeight = 800;
    
    midlineWidth = displayResolutionWidth * 0.5;
    midlineHeight = displayResolutionHeight * 0.5;
    
    ofBackground(0, 0, 0);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    serial.setup("/dev/tty.usbserial-A600clxb", 9600); // mac osx example
    
    serial.startContinuousRead();
    ofAddListener(serial.NEW_MESSAGE,this,&ofApp::onNewMessage);
    
    message = "";
    
    randomColorIsSet = false;
    
    redColor = 0;
    greenColor = 0;
    blueColor = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    fullscreenWidthOffset = (ofGetWindowWidth() * 0.5);
    fullscreenHeightOffset = (ofGetWindowHeight() * 0.5);
    
    if(requestRead)
    {
        serial.sendRequest();
        requestRead = false;
    }
    
    if(randomColorIsSet != true){
        redColor = 255 / (random() % 10 + 1);
        greenColor = 255 / (random() % 10 + 1);
        blueColor = 255 / (random() % 10 + 1);
        randomColorIsSet = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
        ofTranslate(fullscreenWidthOffset, 0);
        // Calculate background square size
        float backGroundSquare = sqrt(pow(displayResolutionHeight, 2.0) + pow(displayResolutionHeight, 2.0)) * 0.5;
        rectangle_1.draw("background", 0, 0, backGroundSquare, backGroundSquare, 255, 255, 255, 45, false, false);
    
    
        if(noColor != true){
        
            if(button_1 == true){
                ofSetColor(255, 0, 0);
            }
            else if(button_2 == true){
                ofSetColor(255, 255, 0);
            }
            else if(button_3 == true){
                ofSetColor(0, 0, 255);
            }
            else if(button_4 == true){
                ofSetColor(redColor, greenColor, blueColor);
            }
            else{
                ofSetColor(255, 255, 255);
            }
        }else{
            randomColorIsSet = false;
            ofSetColor(255, 255, 255);
        }
        ofDrawTriangle(0,0, -128,128, 128,128);
    
    
        if(noColor != true){
        
            if(button_1 == true){
                ofSetColor(redColor, greenColor, blueColor);
            }
            else if(button_2 == true){
                ofSetColor(255, 0, 0);
            }
            else if(button_3 == true){
                ofSetColor(255, 255, 0);
            }
            else if(button_4 == true){
                ofSetColor(0, 0, 255);
            }
            else{
                ofSetColor(255, 255, 255);
            }
        }else{
            ofSetColor(255, 255, 255);
        }
        ofDrawTriangle(-256,256, -400,400, -256,544);
    
    
        if(noColor != true){
        
            if(button_1 == true){
                ofSetColor(0, 0, 255);
            }
            else if(button_2 == true){
                ofSetColor(redColor, greenColor, blueColor);
            }
            else if(button_3 == true){
                ofSetColor(255, 0, 0);
            }
            else if(button_4 == true){
                ofSetColor(255, 255, 0);
            }
            else{
                ofSetColor(255, 255, 255);
            }
        }else{
            ofSetColor(255, 255, 255);
        }
        ofDrawTriangle(-211,588, 0,displayResolutionHeight, 211,588);
    
    
        if(noColor != true){
            if(button_1 == true){
                ofSetColor(255, 255, 0);
            }
            else if(button_2 == true){
                ofSetColor(0, 0, 255);
            }
            else if(button_3 == true){
                ofSetColor(redColor, greenColor, blueColor);
            }
            else if(button_4 == true){
                ofSetColor(255, 0, 0);
            }
            else{
                ofSetColor(255, 255, 255);
            }
        }else{
            ofSetColor(255, 255, 255);
        }
        ofDrawTriangle(238,238, 400,400, 238,561);
    
    
        ofSetColor(0, 0, 0);
    
        ofDrawRectangle(-(displayResolutionWidth * 0.5),
                        midlineHeight * (0.32),
                        displayResolutionWidth * 2,
                        displayResolutionHeight * 0.040);
    
        ofDrawRectangle(-(displayResolutionWidth * 0.5),
                        (midlineHeight * 1.41),
                        displayResolutionWidth * 2,
                        displayResolutionHeight * 0.03);
    
        ofDrawRectangle(midlineWidth - (midlineWidth * 0.66),
                        -(displayResolutionHeight * 0.5),
                        displayResolutionHeight * 0.026,
                        displayResolutionHeight * 2);
    
        ofDrawRectangle(-(midlineWidth * 0.40),
                        -(displayResolutionHeight * 0.5),
                        displayResolutionHeight * 0.035,
                        displayResolutionHeight * 2);
    
    ofPopMatrix();
    
    if(showInfo == true){
        ofPushMatrix();
        
        
        ofPopMatrix();
    }
}

void ofApp::onNewMessage(string & message)
{
    cout << "onNewMessage, message: " << message << "\n";
    
    button_1 = (message == "1");
    button_2 = (message == "2");
    button_3 = (message == "3");
    button_4 = (message == "4");
    noColor = (message == "0");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'i'){
        showInfo = !showInfo;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    requestRead = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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