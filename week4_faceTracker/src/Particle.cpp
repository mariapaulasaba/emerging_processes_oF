//
//  Particle.cpp
//  week4_faceTracker
//
//  Created by Maria Paula Saba dos Reis on 3/3/13.
//
//

#include "Particle.h"


void Particle::setupCustom(){
 

}


void Particle::draw(){

    float radius = getRadius();
    ofPushMatrix();
    ofTranslate(getPosition());
    ofRotateZ(getRotation());
    ofSetColor(0, 100, 200);
    ofFill();
    ofCircle(0, 0, radius);
    
    ofPopMatrix();



}