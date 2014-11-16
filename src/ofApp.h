#pragma once

#include "ofMain.h"
#include "rectangles.h"

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
    
        rectangles  rectangle_1,
                    rectangle_2,
                    rectangle_3,
                    rectangle_4,
                    rectangle_5,
                    rectangle_6,
                    rectangle_7;
    
        ofTrueTypeFont font;
};