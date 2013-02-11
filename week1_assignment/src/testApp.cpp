#include "testApp.h"


Boolean videos;

//--------------------------------------------------------------
void testApp::setup(){
    my_video1.loadMovie("IMG_0060.MOV");
    my_video2.loadMovie("IMG_0031.MOV");
    my_video1.play();
    my_video2.play();
    
    doorlock.loadImage("knob.png");
    
    ofEnableAlphaBlending();
    
    ofBackground(0, 0, 0);
    
    videos = true;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetColor(255, 255, 255);
    my_video1.update();
    my_video2.update();

    if (videos) my_video1.draw(mouseX - 232, mouseY - 400,464,800);
    else my_video2.draw(mouseX - 232, mouseY - 400,600,800);
   
    doorlock.draw(0,0);

    ofSetColor(0, 0, 0);
    ofFill();
    



}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    videos =! videos;

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