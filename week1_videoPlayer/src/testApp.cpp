#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    my_video.loadMovie("natureCode1.mov");
    my_video.play();
    my_video.setLoopState(OF_LOOP_PALINDROME);
    
    ofEnableAlphaBlending();
    
}

//--------------------------------------------------------------
void testApp::update(){
   // my_video.setFrame(mouseX);
 
    

}

//--------------------------------------------------------------
void testApp::draw(){
   // my_video.draw(mouseX -105,mouseY -75, 210, 150);
    my_video.update();
    
    int sampleX = ofClamp(mouseX, 0, my_video.getWidth()-1);
    int sampleY = ofClamp(mouseY, 0, my_video.getHeight()-1);

    
    ofColor sample = my_video.getPixelsRef().getColor(sampleX,sampleY);
    
    ofBackground(sample);
    ofSetColor(255,0,255);
    my_video.draw(0,0, mouseX, mouseY);
    
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 's'){
        if(my_video.isPlaying()){
            my_video.stop();
        }
        else{
            my_video.play();
        }
        
    }
    
    
    if(key == 'f'){
        ofToggleFullscreen();
        
    }

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