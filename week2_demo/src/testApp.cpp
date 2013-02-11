#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    if(!player.loadMovie("IMG_0060_1.mov")){
        ofLogError("Video load failed");
    }
    else{
        player.play();
        
        accumulation.allocate(player.getWidth(), player.getHeight(), player.getPixelsRef().getImageType());
        
        ofLogNotice("Video loaded success!");
    }
    
    totalFrames = 0;
    
}



//--------------------------------------------------------------
void testApp::update(){
    player.update();
   
    
    //a running average of pixels
    // NewAverage(x,y) = OldAverage(x,y)+(Current(x,y) - OldAverage(x,y)) / FrameNum;
    if(player.isFrameNew()){
        totalFrames++;
        
        for (int unsigned y = 0; y < player.getHeight(); y++){
            for(int unsigned x = 0; x < player.getWidth(); x++){
            
                ofFloatColor currentAverage;
                ofFloatColor currentPixel;
                ofFloatColor newAverage;
        
                currentAverage = accumulation.getColor(x, y);
                currentPixel = player.getPixelsRef().getColor(x, y);
                newAverage = currentAverage + (currentPixel - currentAverage)/ totalFrames;
                
                accumulation.setColor(x, y, newAverage);
                
    }
   }
        accumulation.reloadTexture();
 }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //flipping videos
    //player.draw(player.getWidth(), player.getHeight(), -player.getWidth(), -player.getHeight());
    //player.draw(player.getWidth(), player.getHeight(), -player.getWidth(), player.getHeight());

    
    player.draw(0, 0);
    accumulation.draw(player.getWidth(), 0);
    
    
    
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