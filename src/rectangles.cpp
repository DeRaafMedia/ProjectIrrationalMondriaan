//
//  rectangels.cpp
//  ProjectIrrationalMondriaan
//
//  Created by Remco Platjes on 16-11-14.
//
//

#include "rectangles.h"
#include "ofApp.h"

void rectangles::draw(string squareId,
                      int initXAxis,
                      int initYAxis,
                      int initWidth,
                      int initHeight,
                      int initRed,
                      int initGeen,
                      int initBlue,
                      int diameter,
                      bool showSquaresId,
                      bool oscEnabled){
    ofSetColor(initRed, initGeen, initBlue);
    ofDrawRectangle(initXAxis, initYAxis, initWidth, initHeight);
    if(showSquaresId == true){
        ofSetColor(255, 0, 0);
        ofDrawBitmapString("<" + squareId, initXAxis + 10, initYAxis + 10);
    }
}