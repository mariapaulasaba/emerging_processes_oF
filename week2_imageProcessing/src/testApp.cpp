#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    if(!player.loadMovie("haiku.mp4")){
        ofLogError("Movie load failed!");
    }
    else {
        player.play();
        result.allocate(player.getWidth(), //WIDTH
                        player.getHeight(), //HEIGHT
                        player.getPixelsRef().getImageType());//PIX TYPE
        
    }
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
    
    
    
    if(player.isFrameNew()){
        for(int y = 0; y < player.getHeight(); y++){
        for (int x = 0; x < player.getWidth(); x++){

           // ofPixels pixels2 = player.getPixelsRef();
           // ofColor currentPixel = pixels2.getColor(x,y);
            
            
            ofColor currentPixel;
            ofColor newPixel;
            
            currentPixel = player.getPixelsRef().getColor(x, y);
          
            
            float brightness = currentPixel.getBrightness();
            
            newPixel.r = brightness;
            newPixel.g = brightness;
            newPixel.b = brightness;
            
            result.setColor(x, y, currentPixel);
            
            
      
      
            
            
            
            
            /*
            unsigned char *pixels = player.getPixels();
             
            int i = y * player.getWidth() + x;
            pixels[i*3 + 0] = 255 - pixels[i*3 + 0];
            pixels[i*3 + 1] = 255 - pixels[i*3 + 1];
            pixels[i*3 + 2] = 255 - pixels[i*3 + 2];
            
            result.setFromPixels(pixels, player.getWidth(), player.getHeight(), OF_IMAGE_COLOR);

            }*/
            
            
            }
        
            result.reloadTexture();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    
    player.draw(0, 0);
    
    
    result.draw(player.getWidth(),0);

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