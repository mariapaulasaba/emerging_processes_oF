#pragma once

#include "ofMain.h"

class Mover {
    
public:
    float mass;
    ofVec2f location;
    ofVec2f velocity;
   
    void setup();
    void update();
    void draw();
    void noise();
    void checkEdges();
    
    
    
private:
    ofVec2f acceleration;
    float tx, ty;

};
