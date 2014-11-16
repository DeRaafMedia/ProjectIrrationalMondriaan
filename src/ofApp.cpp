#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDataPathRoot("../Resources/data/");
    showInfo = false;
    showSquaresId = false;
    oscEnabled = false;
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawBitmapString((oscHandler.xAxisValue), 10, 20);
    rectangle_1.draw("square_1", 0, 0, 790, 800, 255, 255, 255, 0, showSquaresId, oscEnabled);
    ofSetCircleResolution(50);
    ofSetColor(0, 0, 0);
    ofDrawCircle(356, 450, 110);
    ofSetColor(255,0,0);
    ofDrawCircle(356, 450, 100);
    rectangle_2.draw("square_2", 349, 0, 15, 800, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_3.draw("square_3", 0, 439, 790, 20, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_4.draw("square_4", 690, 457, 17, 362, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_5.draw("square_5", 707, 564, 85, 29, 0, 0, 0, 0, showSquaresId, oscEnabled);
    rectangle_6.draw("square_6", 0, 0, 349, 439, 254, 235, 25, 0, showSquaresId, oscEnabled);
    rectangle_7.draw("square_7", 707, 457, 83, 108, 18, 18, 87, 0, showSquaresId, oscEnabled);
    ofSetColor(255, 0, 0);
    if(showInfo == true){
        ofDrawBitmapString("TRUE" , 50, 50);
    }
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
