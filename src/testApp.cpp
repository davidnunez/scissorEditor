#include "testApp.h"
#include "ofxVectorGraphics.h"
#include <string>
#include "Linkage.h"

ofTrueTypeFont myfont;

Linkage linkage;
Linkage linkage2;


//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    myfont.loadFont("SourceCodePro-Regular.ttf", 12);

    
    // GUI Setup    
    gui = new ofxUICanvas(30,30,320,320);
    gui->addWidgetDown(new ofxUILabel("MIT 6.S080 Linkage studies by David Nunez", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider("theta", 0.0f, 180.0f, 20.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("stroke", 0.0f, 1000.0f, 500.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("a", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));

    gui->addWidgetDown(new ofxUISlider("a1", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("a2", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));

    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");
    
    
    linkage.strokeLength = 500.0f;
    linkage.theta = 20.0f;
    linkage.a1 = 270.0f;
    linkage.a2 = 270.0f;
    linkage2.strokeLength = linkage.strokeLength;
    linkage2.theta = linkage.theta;
    linkage2.a1 = linkage.a1;
    linkage2.a2 = linkage.a2;
    
}

//--------------------------------------------------------------
void testApp::update(){

    linkage2.strokeLength = linkage.strokeLength;
    linkage2.theta = linkage.theta;
    linkage2.a1 = linkage.a1;
    linkage2.a2 = linkage.a2;
    
    
    
    linkage.update();
    linkage2.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor cyan = ofColor::fromHex(0x00abec);
	ofColor magenta = ofColor::fromHex(0xec008c);
	ofColor yellow = ofColor::fromHex(0xffee00);
	ofColor deepblue = ofColor::fromHex(0x1E134F);
	ofBackgroundGradient(deepblue * 1, deepblue * 0.1);

    ofPushMatrix();
    ofTranslate(500, 600);
    linkage.draw();


    ofRotate(linkage.theta); //

    //linkage2.draw();
    ofPopMatrix();
    std::stringstream s;
    s << "theta: " << linkage.link1.theta << '\n';
    s << "A: " << linkage.link1.A << '\n';
    s << "B: " << linkage.link1.B << '\n';
    s << "C: " << linkage.link1.C << '\n';
    s << "a: " << linkage.link1.a << '\n';
    s << "b: " << linkage.link1.b << '\n';
    s << "c: " << linkage.link1.c << '\n';
    
    
   // myfont.drawString(s.str(), 700,100);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == '-')  {
        linkage.link1.theta -= 1;
    }
    if (key == '+') {
       linkage.link1.theta += 1;
    }
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


void testApp::exit()
{
	gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}

void testApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.widget->getName() == "theta")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        linkage.theta = slider->getScaledValue();
    }

    if(e.widget->getName() == "stroke")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        linkage.strokeLength = slider->getScaledValue();
    }

    if(e.widget->getName() == "a1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        linkage.a1 = slider->getScaledValue();

    }

    if(e.widget->getName() == "a2")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        linkage.a2 = slider->getScaledValue();
        
    }
    
    if (e.widget->getName() == "a")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        linkage.a1 = slider->getScaledValue();
        linkage.a2 = slider->getScaledValue();
        
        
    }




}