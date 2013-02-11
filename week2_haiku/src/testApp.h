#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoPlayer player1, player2, player3;
    ofImage accumulation1, accumulation2, accumulation3;
    int totalFrames1, totalFrames2, totalFrames3;
		
    ofImage slitResult1, slitResult2, slitResult3;
    int currentRow1, currentRow2, currentRow3;
};
