#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/");
    showInfo = false;
    showSquaresId = false;
    oscEnabled = false;
    ofBackground(0, 0, 0);
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    
    soundStream.listDevices();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    volHistory.push_back( scaledVol );
    
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float fullscreenOffset = (ofGetWindowWidth() * 0.5) - (790 * 0.5);
    
    rectangle_1.draw("square_1", 0 + fullscreenOffset, 0, 790, 800, 255, 255, 255, 0, showSquaresId, oscEnabled);
    
    ofSetColor(0, 0, 0);
    ofDrawCircle(356 + fullscreenOffset, 449, (((scaledVol * 1.0) * 190.0f) * 1.4) + (((((scaledVol * 1.0) * 190.0f) / 100) * 10) * 1.4));
    ofSetColor(255,0,0);
    ofDrawCircle(356 + fullscreenOffset, 449, ((scaledVol * 1.0) * 190.0f) * 1.4);
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(255, 0, 0, 255);
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    ofDrawCircle(695 + fullscreenOffset, 450, ((scaledVol * 0.3) * 190.0f) * 0.9);
    ofSetColor(0,255,0, 255);
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    ofDrawCircle(358 + fullscreenOffset, 780, ((scaledVol * 0.4) * 190.0f) * 1.2);
    ofSetColor(0,0,255, 255);
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    ofDrawCircle(695 + fullscreenOffset, 780, ((scaledVol * 0.5) * 190.0f) * 1.5);
    ofDisableAlphaBlending();
    
    rectangle_2.draw("square_2", 348 + fullscreenOffset, 0, 18, 800, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_3.draw("square_3", 0 + fullscreenOffset, 440, 790, 19, 0, 0, 0, 0, showSquaresId, oscEnabled);
    
    rectangle_4.draw("square_4", 688 + fullscreenOffset, 459, 17, 362, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_5.draw("square_5", 705 + fullscreenOffset, 567, 85, 28, 0, 0, 0, 0, showSquaresId, oscEnabled);
    
    rectangle_6.draw("square_6", 0 + fullscreenOffset, 0, 348, 440, 254, 235, 25, 0, showSquaresId, oscEnabled);
    
    rectangle_7.draw("square_7", 705 + fullscreenOffset, 459, 85, 108, 18, 18, 87, 0, showSquaresId, oscEnabled);
    rectangle_8.draw("square_8", 366 + fullscreenOffset, 776, 324, 17, 0, 0, 0, 0, showSquaresId, oscEnabled);
    
    ofSetColor(0, 0, 0);
    if(showInfo == true){
        if(oscEnabled == true){
            ofDrawBitmapString("[ OSC enabled ] --> true"  , 30, 30);
        }else{
            ofDrawBitmapString("[ OSC enabled ] --> false"  , 30, 30);
        }
        ofDrawBitmapString("[ i ] --> information"  , 30, 45);
        ofDrawBitmapString("[ s ] --> show squares ( get ids )"  , 30, 60);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'i'){
        showInfo = !showInfo;
    }
    if(key == 's'){
        showSquaresId = !showSquaresId;
    }
    if(key == 'o'){
        oscEnabled = !oscEnabled;
    }
    if( key == 'x' ){
        soundStream.start();
    }
    
    if( key == 'y' ){
        soundStream.stop();
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
