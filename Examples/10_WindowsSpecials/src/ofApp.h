#pragma once

#include "ofMain.h"

/*

	This example shows one of the extra engines of the ofxSurfingImGui Toolkit,
	It's called "Windows Special Organizer".
	Many grouped windows can be arranged linked together and distributed horizontally or vertically.
    Also, there's an "Align Windows Engine" to align/cascade windows layout.

*/


#include "ofxSurfingImGui.h"

class ofApp : public ofBaseApp
{
public:
    
    void setup();
    void draw();
	void keyPressed(int key);

	//-

    // Parameters
    
    ofParameterGroup params_0;
    ofParameter<bool> bEnable0;
    ofParameter<bool> bPrevious0;
    ofParameter<bool> bNext0;
    ofParameter<float> speed0;

	ofParameterGroup params_1;
    ofParameter<bool> bEnable1;
    ofParameter<float> lineWidth1;
    ofParameter<float> separation1;
    ofParameter<int> shapeType1;
    ofParameter<int> size1;

    ofParameterGroup params_2;
    ofParameter<bool> bEnable2;
    ofParameter<int> shapeType2;
    ofParameter<int> amount2;
    ofParameter<int> size2;

    ofParameterGroup params_3;
    ofParameter<bool> bEnable3;
    ofParameter<float> lineWidth3;
    ofParameter<float> separation3;
    ofParameter<float> speed3;
    ofParameter<int> shapeType3;

	//-

	// Gui

	ofxSurfing_ImGui_Manager guiManager;

	void setup_ImGui();

    ofParameter<bool> bGui;
    void draw_MainWindow();

	void draw_SurfingWidgets_0();
	void draw_SurfingWidgets_1();
	void draw_SurfingWidgets_2();
	void draw_SurfingWidgets_3();
};
