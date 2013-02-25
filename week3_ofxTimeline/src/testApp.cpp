#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    timeline.setup();
    
    timeline.addBangs("bangs");
    timeline.addCurves("curves", ofRange(0, ofGetWidth()));
    timeline.addSwitches("switches");
    timeline.addFlags("flags");
    timeline.addLFO("lfo", ofRange(0,200));
    timeline.addColors("colors");
    
    size = 20;
    text = "";
    
    ofAddListener(timeline.events().bangFired, this, &testApp::bang);
    

}


void testApp::bang(ofxTLBangEventArgs& args ){
    if(args.flag == "") {
        size = ofRandom(50);
    
    }
    else {
        text = args.flag;
    
    }

}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    timeline.draw();
    
    
    ofPoint position;
    position.x = timeline.getValue("curves");
    position.y = timeline.getValue("lfo");
    position.y += timeline.getHeight();
    
    ofSetColor(timeline.getColor("colors"));
    
    if(timeline.isSwitchOn("switches")) {
    
        ofRect(position, size, size);
    
    }
                
    else{
    
        ofCircle(position, size);
    }
    
    ofSetColor(255);
    
    ofDrawBitmapString(text, position);
    
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