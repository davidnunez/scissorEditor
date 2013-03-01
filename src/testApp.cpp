#include "testApp.h"
#include "ofxVectorGraphics.h"
#include <string>
#include "Linkage.h"
#include <vector>
using namespace std;
ofTrueTypeFont myfont;


vector<Linkage> linkages;
int selectedLinkage = -1;
//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    myfont.loadFont("SourceCodePro-Regular.ttf", 12);
    Linkage linkage;

    linkage.strokeLength = 500.0f;
    linkage.theta = 20.0f;
    linkage.a1 = 270.0f;
    linkage.a2 = 270.0f;
    linkage.x = 500.0f;
    linkage.y = 400.0f;
    linkages.push_back(linkage);
    
    // GUI Setup    
    gui = new ofxUICanvas(30,30,320,320);
    gui->addWidgetDown(new ofxUILabel("MIT 6.S080 Linkage Studies by David Nunez", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider("theta", 0.0f, 180.0f, 20.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("stroke", 0.0f, 1000.0f, 500.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("a", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));

    gui->addWidgetDown(new ofxUISlider("a1", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("a2", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));

    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");

    
   
    cout << linkages.size();
    
}

//--------------------------------------------------------------
void testApp::update(){

    //linkage2.strokeLength = linkage.strokeLength;
    //linkage2.theta = linkage.theta;
    //linkage2.a1 = linkage.a1;
    //linkage2.a2 = linkage.a2;
    
    
    for (int i = 0; i < linkages.size(); i++) {
        linkages[i].update();
    }
    //linkage2.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofColor cyan = ofColor::fromHex(0x00abec);
	ofColor magenta = ofColor::fromHex(0xec008c);
	ofColor yellow = ofColor::fromHex(0xffee00);
	ofColor deepblue = ofColor::fromHex(0x1E134F);
    ofColor lightSkin = ofColor::fromHex(0x484BA1);
	ofBackgroundGradient(deepblue * 1, lightSkin * 0.7);

    
    for (int i = 0; i < linkages.size(); i++) {
        ofPushMatrix();
        ofTranslate(linkages[i].x, linkages[i].y);
        ofRotate(linkages[i].theta*i);

        linkages[i].draw();

        ofPopMatrix();
        
        
    }
    
 


    std::stringstream s;
    s << "Linkages: " << linkages.size() << '\n';
    for (int i = 0; i < linkages.size(); i++) {
        s << "x:" << linkages[i].x;
        s << "y:" << linkages[i].y << '\n';
        
    }
    s << "Selected: " << selectedLinkage << '\n';
//    s << "theta: " << linkage.link1.theta << '\n';
//    s << "A: " << linkage.link1.A << '\n';
//    s << "B: " << linkage.link1.B << '\n';
//    s << "C: " << linkage.link1.C << '\n';
//    s << "a: " << linkage.link1.a << '\n';
//    s << "b: " << linkage.link1.b << '\n';
//    s << "c: " << linkage.link1.c << '\n';
    
    
   myfont.drawString(s.str(), 700,100);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == '-')  {
        //linkage.link1.theta -= 1;
        linkages.pop_back();
    }
    if (key == '+') {
        Linkage linkage2;
        linkage2.x = linkages[0].x;
        linkage2.y = linkages[0].y;
        linkage2.strokeLength = linkages[0].strokeLength;
        linkage2.theta = linkages[0].theta;
        linkage2.a1 = linkages[0].a1;
        linkage2.a2 = linkages[0].a2;
        
        linkages.push_back(linkage2);
    
        
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (selectedLinkage != -1) {
        linkages[selectedLinkage].x = x;
        linkages[selectedLinkage].y = y;
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < linkages.size(); i++) {
        if (linkages[i].selected(x, y)) {
            selectedLinkage = i;
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    selectedLinkage = -1;
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
	//gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}

void testApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.widget->getName() == "theta")
    {
        
        
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        
        for (int i = 0; i < linkages.size(); i++) {

            linkages[i].theta = slider->getScaledValue();
        }
    }

    if(e.widget->getName() == "stroke")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        for (int i = 0; i < linkages.size(); i++) {

        linkages[i].strokeLength = slider->getScaledValue();

        }
    }
    if(e.widget->getName() == "a1")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
     
        for (int i = 0; i < linkages.size(); i++) {

            linkages[i].a1 = slider->getScaledValue();
        }

    }

    if(e.widget->getName() == "a2")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        for (int i = 0; i < linkages.size(); i++) {

            linkages[i].a2 = slider->getScaledValue();
        }
        
    }
    
    if (e.widget->getName() == "a")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        for (int i = 0; i < linkages.size(); i++) {

            linkages[i].a1 = slider->getScaledValue();
            linkages[i].a2 = slider->getScaledValue();
        }
        
    }




}