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
    if(oscEnabled == true){
        
        red = listener.redValue;
        green = listener.greenValue;
        blue = listener.blueValue;
        xAxis = listener.xAxisValue;
        yAxis = listener.yAxisValue;
        width = listener.widthValue;
        height = listener.heightValue;
        
        ofSetColor(initRed + red, initGeen + green, initBlue + blue);
        ofDrawRectangle(initXAxis + xAxis, initYAxis + yAxis, initWidth + height, initHeight + height);
    }else{
        ofSetColor(initRed, initGeen, initBlue);
        ofDrawRectangle(initXAxis, initYAxis, initWidth, initHeight);
    }
    if(showSquaresId == true){
        ofSetColor(255, 0, 0);
        ofDrawBitmapString("<" + squareId, initXAxis + 10, initYAxis + 10);
        ofDrawBitmapString(red, 100, 100);
    }
}