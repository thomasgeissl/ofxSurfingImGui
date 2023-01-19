ofxSurfingImGui
=============================

<h1>

A [DearImGui](https://github.com/ocornut/imgui) **Toolkit**  
for **openFrameworks** projects.  

</h1>

## WORK IN PROGRESS!

( _Some examples, testing or new incoming widgets, complementary docs and more projects are now moved to [ofxSurfingImGuiExtra](https://github.com/moebiussurfing/ofxSurfingImGuiExtra)._ )  

[Examples Screenshots](https://github.com/moebiussurfing/ofxSurfingImGui/blob/a2eb866717cb829cea049fa3c4c0fd68da6ec1df/Examples/README.md)  

# FEATURES

- Easy **Setup** and **Layout**.
- **Multiple instances** around classes and **ofxAddons**.
- **ofParameter Helpers**.
  - RAW **ImGui Widgets** ported to **oF ofParameters**.
  - Added custom useful widgets: 
      - Dropdown (Combo) lists with index selector and vector of names.
      - Matrix buttons to an index / int param.
      - Bundled widgets like arrows linked to int params browsing.
- Useful methods and **Snippets** to **Speed-Up layout** and simple **Workflow**.
- A **Layout Presets Engine**.
- Some **Docking Helpers**.
- Cool **Themes**.
- Extra **Mouse Control** 
  - Wheel for Tweaking. _+Ctrl_ to Finetune.
  - Right button to reset to params center.
    - _+Ctrl_ to reset to min.
    - _+Alt_ to reset to max.
- Powerful **Log System**.
- Floating **Notifier System**.

<details>
  <summary>MORE IMGUI WIDGETS</summary>
  <p>

- Big Toggles and Buttons
- Vertical and Horizontal Sliders
- Range Sliders
- Styled Knobs
- Tree folders
- Inactive, hidden or locked styles
- Floating tooltip, labels and values
- DearWidgets
- Gradient Color Designer
- Matrix Selectors
- Dropdown / Combos selectors
- Progress bars and waiting spinners
- Files Browser
- Curve Editors
- Bubbles Notifier System
- Profile Plotters
  
  </p>
  </details>
    
## EXAMPLE CODE

### ofApp.h

```.cpp
#include "ofxSurfingImGui.h"

ofxSurfingGui ui;
ofParameter<bool> bGui{ "Show", true };

ofParameter<bool> bEnable{ "Enable", false };
ofParameter<float> speed{ "Speed", .5f, 0.f, 1.f  };
ofParameterGroup params{ "Group" };
..
```

### ofApp.cpp

```.cpp
void ofApp::draw() 
{
    ui.Begin();
    {
        /* Put windows here */

        if (ui.BeginWindow(bGui))
        {
            /* Put widgets here */

            ui.AddGroup(params);
            ui.AddSpacing();
            ui.Add(bEnable, OFX_IM_TOGGLE);
            ui.Add(speed, OFX_IM_HSLIDER_MINI);

            ui.EndWindow();
        }
    }
    ui.End();
}
```

## DEPENDENCIES

* [ofxImGui](https://github.com/Daandelange/ofxImGui/)  
  - THE **AWESOME** [@Daandelange](https://github.com/Daandelange)'s **FORK**.
  - You **MUST USE THIS ONE**! 
* [ofxSurfingHelpers](https://github.com/moebiussurfing/ofxSurfingHelpers)

[data.zip](https://github.com/moebiussurfing/ofxSurfingImGui/blob/a2eb866717cb829cea049fa3c4c0fd68da6ec1df/assets.zip) assets like some font files to put into each project `OF_APP/bin/`.  

<details>
  <summary>NOTE ABOUT THE FONTS</summary>

The font file for the currently used theme is **JetBrainsMono-Bold.ttf**. If that font is not located, then it will search for a legacy font called **telegrama_render.otf**. If none of that fonts are located (then `/data` can also be empty), it will work too, but using the default bundled font from **ImGui**.  

</details>

<details>
  <summary>WHY ANOTHER ofxImGui FORK?</summary>
  <p>

- What's new on the [@Daandelange FORK](https://github.com/Daandelange/ofxImGui/) vs [legacy](https://github.com/jvcleave/ofxImGui) **ofxImGui** ? 
  
  - Multi context / instances: 
    
    - Several windows from different add-ons without colliding.  
  
  - Easy to update to future **NEW ImGui** versions.  
    Currently this fork is linked to the [develop branch](https://github.com/jvcleave/ofxImGui/tree/develop) on the original **ofxImGui** from **@jvcleave**.  
    And will be probably merged into the master branch.  
    
    </p>
    </details>

* [ofxWindowApp](https://github.com/moebiussurfing/ofxWindowApp) / _Not required. Only for some examples._


## CURRENT SYSTEMS

- **Windows 10** / **VS 2022** / 
    * GitHub [patch-release](https://github.com/openframeworks/openFrameworks/tree/patch-release) branch.
    * Last official Release: [0.11.2](https://openframeworks.cc/download/)
- **macOS 11.6.7 Big Sur** / **Xcode 13.2.1** / **oF 0.11.2**


<br>

# AUTHOR

An add-on by **moebiusSurfing**.  
*( ManuMolina ) 2021-2023*  

## THANKS

_**SUPER THANKS** to [@Daandelange](https://github.com/Daandelange) for **HIS AWESOME ofxImGui FORK**._  
_All source snippets and widgets from other authors are linked into header files as credits. Thanks!_  
_Thanks to [@alptugan](https://github.com/alptugan) for **macOS** testing._  

## LICENSE

**MIT License**