#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    totalFrames1 = totalFrames2 = totalFrames3 = 0;
    currentRow1 = currentRow2 = currentRow3 = 0;

    
    
    if(!player1.loadMovie("01_snow.mp4")){
        ofLogError("Movie load failed!");
    }
    else {
        player1.play();
        accumulation1.allocate(
                              player1.getWidth(), //WIDTH
                              player1.getHeight(), //HEIGHT
                              player1.getPixelsRef().getImageType());//PIX TYPE
        
        slitResult1.allocate(
                               player1.getWidth(), //WIDTH
                               player1.getHeight(), //HEIGHT
                               player1.getPixelsRef().getImageType());//PIX TYPE
    }
    
    
    if(!player2.loadMovie("02_plant.mp4")){
        ofLogError("Movie load failed!");
    }
    else {
        player2.play();
        accumulation2.allocate(
                               player2.getWidth(), //WIDTH
                               player2.getHeight(), //HEIGHT
                               player2.getPixelsRef().getImageType());//PIX TYPE
        
        slitResult2.allocate(
                             player2.getWidth(), //WIDTH
                             player2.getHeight(), //HEIGHT
                             player2.getPixelsRef().getImageType());//PIX TYPE
    }
    
    if(!player3.loadMovie("03_sun.mp4")){
        ofLogError("Movie load failed!");
    }
    else {
        player3.play();
        accumulation3.allocate(
                               player3.getWidth(), //WIDTH
                               player3.getHeight(), //HEIGHT
                               player3.getPixelsRef().getImageType());//PIX TYPE
        
        slitResult3.allocate(
                             player3.getWidth(), //WIDTH
                             player3.getHeight(), //HEIGHT
                             player3.getPixelsRef().getImageType());//PIX TYPE
    }
    


}

//--------------------------------------------------------------
void testApp::update(){
    player1.update();
    player2.update();
    player3.update();

    if(player1.isFrameNew()){
        for(int y = 0; y < player1.getHeight(); y++){
            for (int x = 0; x < player1.getWidth(); x++){
         
                //first grab the colors
                ofFloatColor currentAverage = accumulation1.getColor(x, y);
                ofFloatColor newPixel = player1.getPixelsRef().getColor(x, y);
                
                //store the total average in a vector, since float colors are clamped to [0 - 1] range
                ofVec3f currentAccumulation = totalFrames1 * ofVec3f(currentAverage.r,currentAverage.g,currentAverage.b);
                currentAverage.r = (newPixel.r + currentAccumulation.x) / (totalFrames1 + 1);
                currentAverage.g = (newPixel.g + currentAccumulation.y) / (totalFrames1 + 1);
                currentAverage.b = (newPixel.b + currentAccumulation.z) / (totalFrames1 + 1);
                
                //reset the modified current average into the array
                accumulation1.setColor(x,y,currentAverage);
            }
        }
        totalFrames1++;
        accumulation1.reloadTexture();
        
        
        for (int x = 0; x < player1.getWidth(); x++){
            slitResult1.setColor(x, currentRow1, player1.getPixelsRef().getColor(x, currentRow1));
            
        }
        
        currentRow1 = (currentRow1 + 1) % int(player1.getHeight());
        slitResult1.reloadTexture();
        
    }
    
    if(player2.isFrameNew()){
        for(int y = 0; y < player2.getHeight(); y++){
            for (int x = 0; x < player2.getWidth(); x++){
                
                //first grab the colors
                ofFloatColor currentAverage = accumulation2.getColor(x, y);
                ofFloatColor newPixel = player2.getPixelsRef().getColor(x, y);
                
                //store the total average in a vector, since float colors are clamped to [0 - 1] range
                ofVec3f currentAccumulation = totalFrames2 * ofVec3f(currentAverage.r,currentAverage.g,currentAverage.b);
                currentAverage.r = (newPixel.r + currentAccumulation.x) / (totalFrames2 + 1);
                currentAverage.g = (newPixel.g + currentAccumulation.y) / (totalFrames2 + 1);
                currentAverage.b = (newPixel.b + currentAccumulation.z) / (totalFrames2 + 1);
                
                //reset the modified current average into the array
                accumulation2.setColor(x,y,currentAverage);
            }
        }
        totalFrames2++;
        accumulation2.reloadTexture();
        
        
        for (int x = 0; x < player2.getWidth(); x++){
            slitResult2.setColor(x, currentRow2, player2.getPixelsRef().getColor(x, currentRow2));
            
        }
        
        currentRow2 = (currentRow2 + 1) % int(player2.getHeight());
        slitResult2.reloadTexture();
        
    }
    
    if(player3.isFrameNew()){
        for(int y = 0; y < player3.getHeight(); y++){
            for (int x = 0; x < player3.getWidth(); x++){
                
                //first grab the colors
                ofFloatColor currentAverage = accumulation3.getColor(x, y);
                ofFloatColor newPixel = player3.getPixelsRef().getColor(x, y);
                
                //store the total average in a vector, since float colors are clamped to [0 - 1] range
                ofVec3f currentAccumulation = totalFrames3 * ofVec3f(currentAverage.r,currentAverage.g,currentAverage.b);
                currentAverage.r = (newPixel.r + currentAccumulation.x) / (totalFrames3 + 1);
                currentAverage.g = (newPixel.g + currentAccumulation.y) / (totalFrames3 + 1);
                currentAverage.b = (newPixel.b + currentAccumulation.z) / (totalFrames3 + 1);
                
                //reset the modified current average into the array
                accumulation3.setColor(x,y,currentAverage);
            }
        }
        totalFrames3++;
        accumulation3.reloadTexture();
        
        for (int x = 0; x < player3.getWidth(); x++){
            slitResult3.setColor(x, currentRow3, player3.getPixelsRef().getColor(x, currentRow3));
            
        }
        
        currentRow3 = (currentRow3 + 1) % int(player3.getHeight());
        slitResult3.reloadTexture();
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    player1.draw(0, 0, 360, 200);
    player2.draw(360, 0, 360, 200);
    player3.draw(720, 0, 360, 200);
    
    accumulation1.draw(0, 200, 360, 200);
    accumulation2.draw(360, 200, 360, 200);
    accumulation3.draw(720, 200, 360, 200);
 
    
    slitResult1.draw(0, 400, 360, 200);
    slitResult2.draw(360, 400, 360, 200);
    slitResult3.draw(720, 400, 360, 200);
    

    
    
    
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