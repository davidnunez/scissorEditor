#include "testApp.h"
#include "ofxVectorGraphics.h"
#include <string>

ofVec2f c1,p1,p3,l1,l2;
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
    myfont.loadFont("SourceCodePro-Regular.ttf", 12);

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
    a = 270.0f;
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