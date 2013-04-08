#pragma once
#include "ofxBox2d.h"

class Data {
public:
	ofColor color;
	int		id;
};



// A Custom Particle extedning the box2d circle
class Particle : public ofxBox2dCircle {
	
public:
	
	void setupCustom();
	void draw();


};
