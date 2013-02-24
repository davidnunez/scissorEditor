#include "testApp.h"
#include "ofxVectorGraphics.h"

ofVec2f c1,p1,p3;
float theta;

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();
    theta = 30.0f;
    
    c1.set(0, 0);
}

//--------------------------------------------------------------
void testApp::update(){

    p1.set(0, -1);
    p3.set(0, -1);
    p1.rotate(theta/2).scale(500);
    p3.rotate(-theta/2).scale(500);

    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofColor cyan = ofColor::fromHex(0x00abec);
	ofColor magenta = ofColor::fromHex(0xec008c);
	ofColor yellow = ofColor::fromHex(0xffee00);
	ofColor deepblue = ofColor::fromHex(0x1E134F);
	ofBackgroundGradient(deepblue * 20, deepblue * 1);
    
    // DRAW GUIDES
    ofPushMatrix();
    ofTranslate(500, 600);
    
    output.changeColor(0.3f, 0.3f, 0.3f);
    
    output.changeColor(0.5f, 0.5f, 0.5f);
    output.line(c1.x, c1.y, p1.x, p1.y);
    output.line(c1.x, c1.y, p3.x, p3    .y);

    
    output.changeColor(1.0f, 1.0f, 1.0f);
    output.circle(c1.x, c1.y, 5);

    
    ofPopMatrix();


    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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