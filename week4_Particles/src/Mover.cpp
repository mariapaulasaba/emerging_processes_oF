//
//  Mover.cpp
//  NOC_midterm1
//
//  Created by Maria Paula Saba dos Reis on 2/28/13.
//
//

#include "Mover.h"


Mover::Mover(const ofVec2f & position, ofColor cor){
    initialLoc = position;
    location = position;
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    color = cor;
    isBack = false;
    mass = ofRandom(15);
}

void Mover::applyForce(const ofVec2f & force){
    ofVec2f f(force/mass);
    acceleration += f;
}



void Mover::goBack( ){
    
    ofVec2f forceBack =  initialLoc - location;
    forceBack.normalize();
    forceBack.x *= 4;
    forceBack.y*= 10;
 //   forceBack /= 4;
        applyForce(forceBack);
    
}


void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
    
    if(isBack) {
        
        ofVec2f forceBack =  initialLoc - location;
        
        if(forceBack.length() < 2) {
            location = initialLoc;
        }
        else{
            goBack();
            velocity *= 0.8;
            
        }
        
        
        
        
    }
}

void Mover::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle(location, mass);
    
    ofSetColor(color);
    ofNoFill();
    ofCircle(location, mass);
    
}



void Mover::setMass(float m){
    mass = m;
}

void Mover::changeColor(ofColor c){

    color = c;
}



void Mover::checkEdges(){
    
    if (location.x > ofGetWidth()){
        velocity.x *= -1;
        location.x = ofGetWidth();
    } else if (location.x < 0){
        velocity.x *= -1;
        location.x = 0;
    }
    
    if (location.y > ofGetHeight()){
        velocity.y *= -1;
        location.y = ofGetHeight();
    }else if (location.y < 0){
        velocity.y *= -1;
        location.y = 0;
    }
}


void Mover::airResistance(){
    
    float speed = velocity.length();
    float dragMagnitude = 0.005 * speed * speed;
    
    ofVec2f drag;
    drag.set(velocity);
    drag *= -1;
    drag.normalize();
    
    
    drag *= dragMagnitude;
    applyForce(drag);
    
}