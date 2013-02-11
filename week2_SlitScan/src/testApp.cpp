#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    if(!player.loadMovie("fingers.mov")) {
        ofLogError("Load movie failed");
    }
    else{
        accumulation.allocate(player.getWidth(), player.getHeight(), OF_IMAGE_COLOR);
        player.play();
        
    }
    
    currentRow = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
    if(player.isFrameNew()){
        for (int x = 0; x < player.getWidth(); x++){
            accumulation.setColor(x, currentRow, player.getPixelsRef().getColor(x, currentRow));
        
        }
        
        currentRow = (currentRow + 1) % int(player.getHeight());
        accumulation.reloadTexture();
       
    }
    accumulation.saveImage("accumulationImage.png");
}

//--------------------------------------------------------------
void testApp::draw(){
    player.draw(0,0);
    accumulation.draw(player.getWidth(),0);

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