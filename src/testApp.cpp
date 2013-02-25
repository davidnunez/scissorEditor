#include "testApp.h"
#include "ofxVectorGraphics.h"
#include <string>

ofVec2f c1,p1,p3,l1,l2, l3, l4;
float l1s;
float theta;
float strokeLength;

float A, B, C, D, E, F, a, b, c, d, e, f;



ofTrueTypeFont myfont;




//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    theta = 30.0f;
    
    c1.set(0, 0);

    strokeLength = 500;
    a = 270.0f;

    myfont.loadFont("SourceCodePro-Regular.ttf", 12);

    gui = new ofxUICanvas(0,0,320,320);
    gui->addWidgetDown(new ofxUILabel("6.S080 Linkage studies by David Nunez", OFX_UI_FONT_LARGE));
    
    
    gui->addWidgetDown(new ofxUISlider("theta", 0.0f, 180.0f, 20.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("stroke", 0.0f, 1000.0f, 500.0f, 200.0f, 16.0f));
    gui->addWidgetDown(new ofxUISlider("a", 0.0f, 1000.0f, 270.0f, 200.0f, 16.0f));
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");
}

//--------------------------------------------------------------
void testApp::update(){

    p1.set(0, -1);
    p3.set(0, -1);
    p1.rotate(-theta/2).scale(strokeLength);
    p3.rotate(theta/2).scale(strokeLength);
    
    
    
    l1s = sin(ofGetElapsedTimef()) * (strokeLength/2) + strokeLength/2;
    l1.set(0, -1);
    l1.rotate(-theta/2).scale(l1s);
    
    
    //a = p1.distance(p3);
    b = l1s;
    A = theta;
    
    B = ofRadToDeg(asin((sin(ofDegToRad(A)))*b/a));
    C = 180-A-B;
    c = sqrt(a*a + b*b - 2*a*b*cos(ofDegToRad(C)));
    
    l2.set(0, -1);
    l2.rotate(theta/2).scale(c);
    
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
    
    // DRAW GUIDES
    output.changeColor(0.5f, 0.5f, 0.5f);
    output.line(c1.x, c1.y, p1.x, p1.y);
    output.line(c1.x, c1.y, p3.x, p3.y);
    output.changeColor(1.0f, 1.0f, 1.0f);
    output.circle(c1.x, c1.y, 5);
    
    
    // DRAW LINKAGES

    output.circle(l1.x, l1.y, 5);
    output.circle(l2.x, l2.y, 5);
    output.line(l1.x,l1.y, l2.x, l2.y);

    ofPopMatrix();

    std::stringstream s;
    s << "theta: " << theta << '\n';
    s << "A: " << A << '\n';
    s << "B: " << B << '\n';
    s << "C: " << C << '\n';
    s << "a: " << a << '\n';
    s << "b: " << b << '\n';
    s << "c: " << c << '\n';
    
       
    myfont.drawString(s.str(), 700,100);

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == '-')  {
        theta -= 1;
    }
    if (key == '+') {
        theta += 1;
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
        theta = slider->getScaledValue();
    }

    if(e.widget->getName() == "stroke")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        strokeLength = slider->getScaledValue();
    }

    if(e.widget->getName() == "a")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        a = slider->getScaledValue();
    }






}