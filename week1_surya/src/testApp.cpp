#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    myMovie.loadMovie("photobooth2.mov");
  //  myMovie.play();
    frameByframe = true;
    
    // 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.listDevices();
    
    int bufferSize = 256;
	
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    myMovie.update();
	//lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.25, 0.0, 1.0, true);
    //cout<<smoothedVol<<"\n";
	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	// maintaing buffer size
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
}

//--------------------------------------------------------------
void testApp::draw(){
    int frames = myMovie.getTotalNumFrames();
    
    
    if(frameByframe){
        
        myMovie.setFrame((int)frames*scaledVol);
    }
	
	//ofNoFill();
    ofBackground(255, 255, 255);

    unsigned char *pixels = myMovie.getPixels();
    
    int nChannels = myMovie.getPixelsRef().getNumChannels();
    
    //Getting RGB colour information
    for (int i = 0; i < 640; i+=4){
        for (int j = 0; j < 426; j+=4){
            unsigned char r = pixels[(j * 640 + i)*nChannels];
            unsigned char g = pixels[(j * 640 + i)*nChannels+1];
            unsigned char b = pixels[(j * 640 + i)*nChannels+2];
            float val = 1 - ((float)r / 255.0f);
            float valg = 1 - ((float)r / 255.0f);
            float valb = 1 - ((float)r / 255.0f);
            
            //setting colour 
            ofColor colourPicker = myMovie.getPixelsRef().getColor(i,j);
            ofSetColor(colourPicker);
            ofCircle(i,j,scaledVol*val*20);

            //Different circle options
            
            //ofCircle(645 + i,j,scaledVol*val*20);
            //            ofSetCircleResolution(500);
            //            ofCircle(0 + i,0+j,scaledVol*val*10);
            //            ofSetColor(0,255,0, scaledVol*255);
            //            ofSetCircleResolution(100);
            //            ofCircle(10 + i,0+j,scaledVol*valr*10);
            //            ofSetColor(0,0,255, scaledVol*255);
            //            ofSetCircleResolution(100);
            //            ofCircle(20 + i,0+j,scaledVol*valb*10);
        }
    }
    

    
}
void testApp::audioIn(float * input, int bufferSize, int nChannels){
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//calculating rms
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	curVol /= (float)numCounted;
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch(key){
        case 'f':
            //frameByframe=!frameByframe;
           // myMovie.setPaused(frameByframe);
            ofToggleFullscreen();
            break;
        case OF_KEY_LEFT:
            myMovie.previousFrame();
            break;
        case OF_KEY_RIGHT:
            myMovie.nextFrame();
            break;
        case '0':
            myMovie.firstFrame();
            break;
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