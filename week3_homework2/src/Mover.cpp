//
//  mover.cpp
//  NOC_2_5_fluid_resistance
//
//  Created by Maria Paula Saba dos Reis on 2/6/13.
//
//

#include "Mover.h"


void Mover::setup(){
    location.set(0, 0);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    tx = 0;
    ty = 1000;
    mass = 1;
}


void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
    
    
    tx = tx + 0.01;
    ty = ty + 0.01;
}


void Mover::noise(){

    float n = ofNoise(1);
    
    location.x = ofMap(ofNoise(tx), 0, 1, 0, ofGetWidth(), true);
    location.y = ofMap(ofNoise(ty), 0, 1, 0, ofGetHeight(), true);
    
    tx = tx + 0.01;
    ty = ty + 0.01;
    


}


void Mover::draw(){
    ofSetColor(175);
    ofFill();
    ofEllipse(location, mass * 16, mass * 16);
    
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
