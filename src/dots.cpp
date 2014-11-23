//
//  dots.cpp
//  ProjectIrrationalMondriaan
//
//  Created by Remco Platjes on 18-11-14.
//
//

#include "dots.h"

// CMY dot
ofEnableAlphaBlending();
ofFill();
ofSetColor(255, 0, 0, 255);
ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
ofDrawCircle(695 + fullscreenOffset, 450, ((scaledVol * 0.3) * 190.0f) * 0.9);
ofDrawCircle(695 + fullscreenOffset, 450, ((scaledVol * 0.5) * 190.0f) * 1.4);
ofDisableAlphaBlending();

// CMY dot
ofEnableAlphaBlending();
ofSetColor(0,255,0, 255);
ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
ofDrawCircle(358 + fullscreenOffset, 780, ((scaledVol * 0.4) * 190.0f) * 1.2);
ofDrawCircle(358 + fullscreenOffset, 780, ((scaledVol * 0.7) * 190.0f) * 1.5);
ofDisableAlphaBlending();

// CMY dot
ofEnableAlphaBlending();
ofSetColor(0,0,255, 255);
ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
ofDrawCircle(695 + fullscreenOffset, 780, ((scaledVol * 0.5) * 190.0f) * 1.5);
ofDrawCircle(695 + fullscreenOffset, 780, ((scaledVol * 0.9) * 190.0f) * 1.6);
ofDisableAlphaBlending();