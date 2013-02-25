#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    grabber.initGrabber(1024, 768);
    counter = 0;
    
    ofBackground(0);
    ofSetCircleResolution(100);
    
    mover.setup();

}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
    counter ++;
    
    if (counter >= ofGetHeight()) counter = 0;
    
    mover.update();
    mover.noise();
    mover.checkEdges();

}

//--------------------------------------------------------------
void testApp::draw(){
    float step = 10;

    
    ofPushStyle();
  //  ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    
    for(float y = 0; y < grabber.getHeight(); y+=step){
        for(float x = 0; x < grabber.getWidth(); x+=step){
            
            ofVec2f pixelPosition;
            pixelPosition.x = ofMap(x, 0, grabber.getWidth(), -100, ofGetWidth()+100);
            pixelPosition.y = ofMap(y, 0, grabber.getHeight(), -100, ofGetHeight()+100);
            
            float diameter = step + ofDist(mover.location.x,mover.location.y, pixelPosition.x, pixelPosition.y) / 10;

            
             ofColor c = grabber.getPixelsRef().getColor(x, y);
            
            ofSetColor(c.r, c.g, c.b);
            ofFill();

            ofCircle(pixelPosition, diameter);

            
        }
    }
    
    //mover.draw();

    ofPopStyle();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}