#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);

	//-

	// debug custom types
	bCustom1 = 0; // inmediate customized when populating
	bCustom2 = 0; // constant. pre configured to customize after (ie: inside a group)

	//-

	// debug ImGui flags
	{
		int sz = (int)SurfingImGuiTypesGroups::OFX_IM_GROUP_NUM_TYPES - 2;
		typeFlags.set("typeFlags", 1, 0, 4);
		typeGroups.set("typeGroups", 0, 0, sz);
	}

	//-

	// windows
	bOpenMain = true;

	//-

	// prepare parameters

	params1.setName("paramsGroup1");
	params2.setName("paramsGroup2");
	params3.setName("paramsGroup3");

	bEnable.set("Enable", false);
	shapeType.set("shapeType", 0, -50, 50);

	params1.add(lineWidth1.set("lineWidth1", 0.5, 0, 1));
	params1.add(separation1.set("separation1", 50, 1, 100));
	params1.add(speed1.set("speed1", 0.5, 0, 1));
	params1.add(size1.set("size1", 100, 0, 100));
	params1.add(amount1.set("amount1", 10, 0, 25));

	params2.add(separation2min.set("sep2min", 25.f, 1, 100));
	params2.add(separation2max.set("sep2max", 75.f, 1, 100));
	params2.add(speed2.set("speed2", 0.5, 0, 1));
	params2.add(lineWidth2.set("lineWidth2", 0.5, 0, 1));
	params2.add(bEnable);

	params1.add(params2);

	//-

	params3.add(bMode1.set("Mode1", false));
	params3.add(bMode2.set("Mode2", false));
	params3.add(bMode3.set("Mode3", false));
	params3.add(bMode4.set("Mode4", false));
	params3.add(bModeA.set("ModeA", false));
	params3.add(bModeB.set("ModeB", false));
	params3.add(bModeC.set("ModeC", false));
	params3.add(bModeD.set("ModeD", false));
	params3.add(bPrevious.set("<", false));
	params3.add(bNext.set(">", false));
	params3.add(shapeType3.set("shapeType3", 0, -50, 50));
	params3.add(size3.set("size3", 100, 0, 100));
	params3.add(amount3.set("amount3", 10, 0, 25));
	params3.add(bEnable);

	params1.add(params3);

	//--

	guiManager.setAutoSaveSettings(true); // -> enables store/recall some settings from previous app session
	guiManager.setImGuiAutodraw(true); // -> required when only one ImGui instance
	guiManager.setup(); // this instantiates and configures ofxImGui inside the class object.

	//-

	// Queue widgets styles to customize when they will be drawn inside an ofParameterGroup
	// If the parameter widget is not added explicitly, will be populated with the default appearance.

	// NOTE:
	// This added style conf will be applied in all the appearances of the param widgets inside all groups.
	// We can overwrite this customization only draing the simple param "by hand".
	// ie:
	// guiManager.Add(bMode3, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 3, 2);+

	//-

	// settings
	params_AppSettings.add(bOpen1);
	params_AppSettings.add(bOpen2);
	params_AppSettings.add(typeGroups);
	params_AppSettings.add(typeFlags);
	params_AppSettings.add(bCustom1);
	params_AppSettings.add(bCustom2);
	params_AppSettings.add(bCustomGroups);

	ofxImGuiSurfing::loadGroup(params_AppSettings, path_AppSettings, true);

	//-

	// -> not checked on runtime! ONLY ON SETUP
	if (bCustom2) {
		SetupStyles();
	}
	else {
		ClearStyles();
	}
}

//--------------------------------------------------------------
void ofApp::SetupStyles() {

	guiManager.clear(); // Clear queued styles if there where previously added, We can do this and changes styles on runtime!

	//--

	// This is the important sugar:
	// We queue styles for the parameters that will be rendered after, on AddGroup methods on Draw()

	// Two widgets same line
	guiManager.AddStyle(bMode1, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, true, 2);
	guiManager.AddStyle(bMode2, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, false, 2);

	// Two widgets same line
	guiManager.AddStyle(bMode3, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, true, 2);
	guiManager.AddStyle(bMode4, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, false, 2, 10);

	guiManager.AddStyle(bModeA, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 1);
	guiManager.AddStyle(bModeB, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 1);
	guiManager.AddStyle(bModeC, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 1);
	guiManager.AddStyle(bModeD, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 1, 10);

	//// A. Two widgets same line small
	//guiManager.AddStyle(bPrevious, SurfingImGuiTypes::OFX_IM_BUTTON_SMALL, true, 2);
	//guiManager.AddStyle(bNext, SurfingImGuiTypes::OFX_IM_BUTTON_SMALL, false, 2, 10);

	// B. Two widgets same line big
	guiManager.AddStyle(bPrevious, SurfingImGuiTypes::OFX_IM_BUTTON_BIG, true, 2);
	guiManager.AddStyle(bNext, SurfingImGuiTypes::OFX_IM_BUTTON_BIG, false, 2, 10);

	guiManager.AddStyle(shapeType3, SurfingImGuiTypes::OFX_IM_STEPPER);
	guiManager.AddStyle(size3, SurfingImGuiTypes::OFX_IM_STEPPER);
	guiManager.AddStyle(amount3, SurfingImGuiTypes::OFX_IM_DRAG, false, 2, 10);

	// More widgets
	guiManager.AddStyle(lineWidth2, SurfingImGuiTypes::OFX_IM_STEPPER);
	guiManager.AddStyle(speed2, SurfingImGuiTypes::OFX_IM_DRAG);

	// Uncoment this to disable the mouse interaction for these widgets
	//guiManager.AddStyle(separation2min, SurfingImGuiTypes::OFX_IM_INACTIVE);
	//guiManager.AddStyle(separation2max, SurfingImGuiTypes::OFX_IM_INACTIVE, false, 10);

	//-

	//TODO: some styles fails
	// Custom group styles before draw

	guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_TREE_EX, ImGuiTreeNodeFlags_DefaultOpen); // ok
	//guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_HIDDEN_HEADER, ImGuiTreeNodeFlags_DefaultOpen); // ok
	//guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_TREE, ImGuiTreeNodeFlags_DefaultOpen); // ok
	
	//guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_SCROLLABLE, ImGuiTreeNodeFlags_DefaultOpen);
	//guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_HIDDEN_HEADER);
	//guiManager.AddGroupStyle(params1, SurfingImGuiTypesGroups::OFX_IM_GROUP_COLLAPSED);
	//guiManager.AddGroupStyle(params2, SurfingImGuiTypesGroups::OFX_IM_GROUP_TREE_EX);
	//guiManager.AddGroupStyle(params2, SurfingImGuiTypesGroups::OFX_IM_GROUP_DEFAULT);
	//guiManager.AddGroupStyle(params3, SurfingImGuiTypesGroups::OFX_IM_GROUP_DEFAULT);

	//guiManager.AddGroupStyle(params2, SurfingImGuiTypesGroups::OFX_IM_GROUP_TREE_EX, ImGuiTreeNodeFlags_DefaultOpen);
	//guiManager.AddGroupStyle(params3, SurfingImGuiTypesGroups::OFX_IM_GROUP_COLLAPSED, ImGuiTreeNodeFlags_DefaultOpen);
}

//--------------------------------------------------------------
void ofApp::ClearStyles() {
	guiManager.clear(); // TODO: -> call from beginWindow/group
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// The group of parameters will be customized tree/folder types
	// Notice that will be applied to all the nested groups inside this parent/root ofParameterGroup
	flags_typeFlags = ImGuiTreeNodeFlags_None;

	if (typeFlags == 0) { flagInfo = "ImGuiTreeNodeFlags_None"; }
	else if (typeFlags == 1) { flagInfo = "ImGuiTreeNodeFlags_DefaultOpen"; flags_typeFlags |= ImGuiTreeNodeFlags_DefaultOpen; } // to start closed
	else if (typeFlags == 2) { flagInfo = "ImGuiTreeNodeFlags_Framed"; flags_typeFlags |= ImGuiTreeNodeFlags_Framed; } // to draw dark tittle bar
	else if (typeFlags == 3) { flagInfo = "ImGuiTreeNodeFlags_Bullet"; flags_typeFlags |= ImGuiTreeNodeFlags_Bullet; } // bullet mark
	else if (typeFlags == 4) { flagInfo = "ImGuiTreeNodeFlags_NoTreePushOnOpen"; flags_typeFlags |= ImGuiTreeNodeFlags_NoTreePushOnOpen; } // no push
	else { flagInfo = "UNKNOWN"; }

	//-

	guiManager.begin();
	{
		if (bOpenMain) drawWindowMain();
		if (bOpen1) drawWindow1();
		if (bOpen2) drawWindow2();
	}
	guiManager.end();
}

//--------------------------------------------------------------
void ofApp::drawWindowMain() {

	// window main
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
		if (guiManager.bAutoResize) window_flags |= ImGuiWindowFlags_AlwaysAutoResize;

		// reset window
		{
			if (bReset0)
			{
				bReset0 = false;

				guiManager.bAutoResize = false; // avoid bug

				ImGuiCond flag = ImGuiCond_Always;
				pos0.x = 10;
				pos0.y = 10;
				ImGui::SetNextWindowPos(ImVec2(pos0.x, pos0.y));
				ImGui::SetNextWindowSize(ImVec2(200, (float)MAX_WINDOW_HEIGHT));

				bReset1 = true;
			}
		}

		//-

		ImGui::Begin("Show Windows");
		{
			if (ImGui::Button("Reset Layout", ofxImGuiSurfing::getWidgetsShapeBig()))
			{
				bReset0 = true;
			}

			ofxImGuiSurfing::AddSpacing();

			// round toggles
			AddToggleRoundedButton(bOpen1);
			AddToggleRoundedButton(bOpen2);

			ofxImGuiSurfing::AddSpacing();

			AddToggleRoundedButton(guiManager.bAutoResize, ImVec2(50, 30));

			ImGui::Dummy(ImVec2(0, 150)); // spacing

			//----

			ImGui::Text("DEBUG STYLES TYPES");

			ofxImGuiSurfing::AddSpacingSeparated();

			//-

			AddToggleRoundedButton(bCustom1);
			if (bCustom1) ImGui::TextWrapped("Customized style for some ofParams Widgets");
			else ImGui::TextWrapped("Default Style for ofParams Widgets");

			ofxImGuiSurfing::AddSpacingSeparated();

			//-

			// readed on setup only, cant be updated on runtime
			if (AddToggleRoundedButton(bCustom2))
			{
				if (bCustom2) {
					SetupStyles();
				}
				else {
					ClearStyles();
				}
			}
			if (bCustom2) ImGui::TextWrapped("Customized Style for Groups on Windows 1/2.");
			else ImGui::TextWrapped("Default Style for some Groups on Window1/2.");

			//-

			ofxImGuiSurfing::AddSpacingSeparated();

			AddToggleRoundedButton(bCustomGroups);
			if (bCustomGroups) ImGui::TextWrapped("Previously customized with Styles for Groups/Trees on Setup.");
			else ImGui::TextWrapped("Direct customize Styles for Groups/Trees on Draw:");

			ofxImGuiSurfing::Spacing();

			// To debug ImGui flags when rendering groups
			if (!bCustomGroups)
			{
				// test customize group/window folders and flags
				ofxImGuiSurfing::AddParameter(typeFlags);
				ImGui::Text(flagInfo.c_str());

				ofxImGuiSurfing::AddParameter(typeGroups);

				string groupInfo = ofxImGuiSurfing::getSurfingImGuiTypesGroupsName(typeGroups.get());
				ImGui::Text(groupInfo.c_str());
			}

			//-

			// get position
			if (bReset1)
			{
				auto posx = ImGui::GetWindowPos().x;
				auto posy = ImGui::GetWindowPos().y;
				float __w = ImGui::GetWindowWidth();
				float __h = ImGui::GetWindowHeight();
				pos1.x = posx + __w + PADDING_PANELS;
				pos1.y = posy;
			}

			//-

			// testing

			ofxImGuiSurfing::AddSpacingSeparated();

			AddToggleRoundedButton(bEnable, ImVec2(50, 30));
		}
		ImGui::End();
	}
}

//--------------------------------------------------------------
void ofApp::drawWindow1() {

	// window 1
	{
		// a window but using my ofxSurfing_ImGui_LayoutManager.h class helper

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
		if (guiManager.bAutoResize) window_flags |= ImGuiWindowFlags_AlwaysAutoResize;

		// reset window
		{
			if (bReset1)
			{
				bReset1 = false;
				ImGuiCond flag = ImGuiCond_Always;
				ImGui::SetNextWindowPos(ImVec2(pos1.x, pos1.y), flag);
				ImGui::SetNextWindowSize(ImVec2(200, (float)MAX_WINDOW_HEIGHT));

				bReset2 = true;
			}
		}

		guiManager.beginWindow(bOpen1, window_flags);
		{
			//--

			// using widgets

			// 0. Default bool param
			ofxImGuiSurfing::AddParameter(bEnable);
			ofxImGuiSurfing::AddSpacingBig();

			//-

			ofxImGuiSurfing::AddSpacingSeparated();
			ofxImGuiSurfing::AddSpacingBig();
			ImGui::TextWrapped("Here we render a container ofParameterGroup with two nested groups inside:");
			ofxImGuiSurfing::AddSpacing();

			//-

			// 2. Parameters inside an ofParameterGroup
			// queue params configs to populate after when drawing they container group
			{
				// A.
				if (!bCustomGroups) // Customized now on Draw
				{
					guiManager.AddGroup(params1, flags_typeFlags, SurfingImGuiTypesGroups(typeGroups.get()));
					//ofxImGuiSurfing::AddGroup(params1, flags_typeFlags, SurfingImGuiTypesGroups(typeGroups.get()));
				}
				else // Previously customized on Setup
				{
					guiManager.AddGroup(params1);
					//ofxImGuiSurfing::AddGroup(params1);
				}

				// B.
				//ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
				//flags |= ImGuiTreeNodeFlags_Framed; // uncomment to draw dark tittle bar
				//flags |= ImGuiTreeNodeFlags_DefaultOpen; // comment to start closed
				//ofxImGuiSurfing::AddGroup(params1, flags);

				ofxImGuiSurfing::AddSpacing();
			}

			//-

			ofxImGuiSurfing::AddSpacingSeparated();
			ofxImGuiSurfing::AddSpacingBig();
			ImGui::TextWrapped("Below here, the widgets are outside of the nested ofParameterGroups");
			ofxImGuiSurfing::AddSpacing();

			// 1. Single parameters (out of a paramGroup)
			// instant populate customized widgets

			////TODO: add knobs + labels
			//ofxImGuiSurfing::AddKnob(speed1);
			//ImGui::SameLine();
			//ofxImGuiSurfing::AddKnob(lineWidth1);
			//ImGui::SameLine();
			//ofxImGuiSurfing::AddKnob(separation1);
			////ofxImGuiSurfing::AddKnob(size1); //TODO: add int
			////guiManager.Add(speed1);

			// A
			if (bCustom1)
			{
				//guiManager.refresh();

				ImGui::Text("* bCustom1 = true");
				ImGui::Text("customized");
				ImGui::Dummy(ImVec2(0, 5)); // spacing

				// This is the defalut helpers ussage for the official ofxImGui Helpers:
				//ofxImGuiSurfing::AddParameter(lineWidth1); 
				// (Notice that this will be affected if there's an added conf (AddStyle) for this param)

				// 1.0.1
				//ofxImGuiSurfing::AddParameter(bMode4);
				// 1.0.2
				// This forces the style no matter if a conf is added (AddStyle) for this param
				guiManager.Add(bModeA, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG); // -> now this is the default bool 
				guiManager.Add(bModeA, SurfingImGuiTypes::OFX_IM_CHECKBOX); // -> deprecated check box as default bool

				// 1.1 Toggle full width
				guiManager.Add(bModeB, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG);

				// 1.2 A float param
				guiManager.Add(lineWidth1, SurfingImGuiTypes::OFX_IM_SLIDER); // force draw
				guiManager.Add(lineWidth1, SurfingImGuiTypes::OFX_IM_DRAG);
				guiManager.Add(lineWidth1, SurfingImGuiTypes::OFX_IM_STEPPER, false, 2, 20); // crashes?

				// 1.3 Three small toggle widgets in one row
				// with 20px vert spacing at end
				//guiManager.refresh(); // update sizes to current window shape
				guiManager.Add(bModeA, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, true, 3);
				guiManager.Add(bModeB, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, true, 3);
				guiManager.Add(bModeC, SurfingImGuiTypes::OFX_IM_TOGGLE_SMALL, false, 3, 2);
				guiManager.Add(bModeD);
			}

			// B
			// default ofxImGui styles
			else
			{
				ImGui::Text("* bCustom1 = false");
				ImGui::Text("default style");
				ImGui::Dummy(ImVec2(0, 5)); // spacing

				ofxImGuiSurfing::AddParameter(bModeA);
				ofxImGuiSurfing::AddParameter(bModeA);
				ofxImGuiSurfing::AddParameter(bModeB);

				ofxImGuiSurfing::AddParameter(lineWidth1);
				ofxImGuiSurfing::AddParameter(lineWidth1);
				ofxImGuiSurfing::AddParameter(lineWidth1);

				ofxImGuiSurfing::AddParameter(bModeA);
				ofxImGuiSurfing::AddParameter(bModeB);
				ofxImGuiSurfing::AddParameter(bModeC);
				ofxImGuiSurfing::AddParameter(bModeD);
			}

			//-

			// get position
			if (bReset2)
			{
				auto posx = ImGui::GetWindowPos().x;
				auto posy = ImGui::GetWindowPos().y;
				float __w = ImGui::GetWindowWidth();
				float __h = ImGui::GetWindowHeight();
				pos2.x = posx + __w + PADDING_PANELS;
				pos2.y = posy;
			}
		}
		guiManager.endWindow();
	}
}

//--------------------------------------------------------------
void ofApp::drawWindow2() {

	// window 2
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
		if (guiManager.bAutoResize) window_flags |= ImGuiWindowFlags_AlwaysAutoResize;

		// reset window
		{
			if (bReset2)
			{
				bReset2 = false;
				ImGuiCond flag = ImGuiCond_Always;
				ImGui::SetNextWindowPos(ImVec2(pos2.x, pos2.y), flag);
				ImGui::SetNextWindowSize(ImVec2(200, (float)MAX_WINDOW_HEIGHT));
			}
		}

		//-

		// A. without flags (default)
		guiManager.beginWindow(bOpen2, window_flags);
		{
			if (bCustom2) {
				ImGui::Text("* bCustom2 = true");
				ImGui::Text("customized");
				ImGui::Dummy(ImVec2(0, 5)); // spacing
			}
			else {
				ImGui::Text("* bCustom2 = false");
				ImGui::Text("default style");
				ImGui::Dummy(ImVec2(0, 5)); // spacing
			}

			//-

			// A. using global flags
			guiManager.AddGroup(params3, flags_typeFlags, SurfingImGuiTypesGroups(typeGroups.get()));

			//-

			/*
			// B. using custom flags
			{
				// group parameter with customized tree/folder type
				ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
				flags |= ImGuiTreeNodeFlags_Framed;
				flags |= ImGuiTreeNodeFlags_DefaultOpen;

				ofxImGuiSurfing::AddGroup(params3, flags);
			}
			*/

			//-

			// extra. 
			// Another widgets pack
			{
				static bool bMore = false;
				ofxImGuiSurfing::AddSpacingSeparated (); 
				ImGui::Text("MORE WIDGETS");
				ofxImGuiSurfing::AddSpaceY(5);
				ofxImGuiSurfing::ToggleRoundedButton("Draw", &bMore);
				ofxImGuiSurfing::AddSpacing();

				if (bMore) drawMoreWidgets();
			}
		}
		guiManager.endWindow();
	}
}

//--------------------------------------------------------------
void ofApp::drawMoreWidgets() {

	// All below these are pure params widgets without window/tree/group/container

	//-

	ImGui::Text("Range Sliders | ofParameters");

	AddRangeParam("separation3", separation2min, separation2max, "%.2f  %.2f", 1.0f);

	ofxImGuiSurfing::AddSpacing();

	//-

	// add an ofParameterGroup

	ImGui::Text("An ofParameterGroup | params2");

	//// Rememeber the "old" notation from original ofxGui:
	//auto mainSettings = ofxImGui::Settings();
	//ofxImGui::AddGroup(params2, mainSettings);

	//-

	// currently we can customize the tree/group types passing tree flags, 
	// and also these Surfing styles from "ofxSurfing_ImGui_WidgetsTypesConstants.h"

	// A. Custom flags
	//ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
	//flags |= ImGuiTreeNodeFlags_Framed; // uncomment to draw dark tittle bar
	//flags |= ImGuiTreeNodeFlags_DefaultOpen; // comment to start closed
	//guiManager.AddGroup(params2, flags, SurfingImGuiTypesGroups::OFX_IM_GROUP_DEFAULT);

	// B. Global flags
	// we will use the gui selectable debugger styles
	guiManager.AddGroup(params2, typeFlags, SurfingImGuiTypesGroups(typeGroups.get()));

	//-

	// spacing
	ofxImGuiSurfing::AddSpacingBig();

	//-

	// some custom widgets

	ImGui::Text("Range Sliders | int/float types");

	// range_slider.h
	static float v1 = 0;
	static float v2 = 1;
	static float v_min = 0;
	static float v_max = 1;
	static float v3 = 0;
	static float v4 = 1;
	ofxImGuiSurfing::RangeSliderFloat("Range 1", &v1, &v2, v_min, v_max, "%.1f  %.1f", 1.0f);
	ofxImGuiSurfing::RangeSliderFloat("Range 2", &v3, &v4, v_min, v_max);

	// float/int types
	// vanilla range slider
	static float begin = 10, end = 90;
	static int begin_i = 100, end_i = 1000;
	ImGui::DragFloatRange2("Range 3", &begin, &end, 0.25f, 0.0f, 100.0f, "Min: %.1f %%", "Max: %.1f %%");
	ImGui::DragIntRange2("Range 4", &begin_i, &end_i, 5, 0, 0, "%.0fcm", "%.0fcm");

	ofxImGuiSurfing::AddSpacingSeparated();

	//-

	if (bCustom1)
	{
		// A row of four big toggles
		ImGui::Text("* bCustom1 = true");
		ImGui::Text("customized");
		ImGui::Dummy(ImVec2(0, 5)); // spacing

		guiManager.Add(bModeA, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, true, 4);
		guiManager.Add(bModeB, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, true, 4);
		guiManager.Add(bModeC, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, true, 4);
		guiManager.Add(bModeD, SurfingImGuiTypes::OFX_IM_TOGGLE_BIG, false, 4);
	}
	else // default ofxImGui styles
	{
		ImGui::Text("* bCustom1 = false");
		ImGui::Text("default style");
		ImGui::Dummy(ImVec2(0, 5)); // spacing

		ofxImGuiSurfing::AddParameter(bModeA);
		ofxImGuiSurfing::AddParameter(bModeB);
		ofxImGuiSurfing::AddParameter(bModeC);
		ofxImGuiSurfing::AddParameter(bModeD);
	}
}

//--------------------------------------------------------------
void ofApp::exit()
{
	ofxImGuiSurfing::saveGroup(params_AppSettings, path_AppSettings, true);
}