#pragma once

#include "ofMain.h"

#include "ofxSurfingImGui.h" // -> Adds all the add-on classes. You can also simplify picking what you want to use.

#include "ofxWindowApp.h" // not required

using namespace ofxSurfing; // used to simple call inside ofxSurfing_ImGui_LayoutManager/widgetsManager
using namespace ofxSurfingHelpers; // used to simple call inside ofxSurfing_ImGui_WidgetsButtons

//using namespace ImTypes; // used to simple call inside ofxSurfing_ImGui_WidgetsButtons
//using namespace SurfingWidgetTypes; // used to simple call inside ofxSurfing_ImGui_WidgetsButtons
//namespace ImTypes = SurfingWidgetTypes;

// TODO:
// auto-resize fails bc widgets refresh is no working on group tree but on window begin
// nested group spacing fails
// should pass the refresh widtgets object.. or simplify

class ofApp : public ofBaseApp{

	public:

		void setup();
		void draw();

		ofxSurfing_ImGui_Manager guiManager; 

		bool bOpen0 = true;
		bool bOpen1 = true;
		bool bOpen2 = true;

		void drawWindow0();
		void drawWindow1();
		void drawWindow2();
		void drawWidgets();

		// parameters
		ofParameterGroup params;
		ofParameter<bool> bEnable;
		ofParameter<bool> bPrevious;//to use as button. kind of void type
		ofParameter<bool> bNext;//to use as button. kind of void type
		ofParameter<bool> bMode1;
		ofParameter<bool> bMode2;
		ofParameter<bool> bMode3;
		ofParameter<bool> bMode4;
		ofParameter<float> lineWidth;
		ofParameter<float> separation;
		ofParameter<float> speed;
		ofParameter<int> shapeType;
		ofParameter<int> amount;
		ofParameter<int> size;
		ofParameterGroup params2;
		ofParameter<int> shapeType2;
		ofParameter<int> amount2;
		ofParameter<int> size2;
		ofParameterGroup params3;
		ofParameter<float> lineWidth3;
		ofParameter<float> separation3;
		ofParameter<float> speed3;
		ofParameter<int> shapeType3;

		// debug
		bool bCustom1;
		bool bCustom2;

		ofxWindowApp windowApp;
};
