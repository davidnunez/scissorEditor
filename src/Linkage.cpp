//
//  Linkage.cpp
//  scissorEditor
//
//  Created by David Nunez on 2/25/13.
//
//

#include "Linkage.h"
ofxVectorGraphics output;


Linkage::Linkage() {
    
}

void Linkage::update() {
    force = sin(ofGetElapsedTimef()) * (strokeLength/2) + strokeLength/2;
    link1.force = force;
    link2.force = force;
    
    link1.theta = -theta/2;
    link2.theta = theta/2;
    
    link1.strokeLength = strokeLength;
    link2.strokeLength = strokeLength;
    
    link1.a = a1;
    link2.a = a2;
    
    
    
    link1.update();
    link2.update();
    
}

void Linkage::draw() {
    // origin point
    output.noFill();
    output.circle(0, 0, 5);
    output.circle(0, 0, 10);
    
    output.fill();
    
    // DRAW GUIDE
    output.changeColor(0.2f, 1.0f, 0.2f);
    output.line(0, 0, link1.s.x, link1.s.y);
    output.line(0, 0, link2.s.x, link2.s.y);
    
    
    link1.draw();
    link2.draw();
}

bool Linkage::selected(float x2, float y2) {
    cout << "ofdist: " << ofDist(x, y, x2, y2);
    return ofDist(x, y, x2, y2) < 10;
    
}
