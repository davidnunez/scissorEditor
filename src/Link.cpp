//
//  Link.cpp
//  scissorEditor
//
//  Created by David Nunez on 2/25/13.
//
//

#include "Link.h"
#include "ofxVectorGraphics.h"
#include <string>


void Link::update() {
    s.set(0, -1);
    s.rotate(theta).scale(strokeLength);
    
    
    
    l1.set(0, -1);
    l1.rotate(theta).scale(force);
    
    // a is set as a variable
    b = force;
    A = abs(theta*2);
    
    B = ofRadToDeg(asin((sin(ofDegToRad(A)))*b/a));
    C = 180-A-B;
    c = sqrt(a*a + b*b - 2*a*b*cos(ofDegToRad(C)));
    
    
    l2.set(0, -1);
    l2.rotate(-theta).scale(c);
    
    
    // Calculating Midpoint
    J = (180-abs(theta*2))/2;
    I = 180-90-J;
    i = 2*tan(ofDegToRad(I))/a;
    
    u  = l2-l1;
    u.normalize();
    u.scale(a/2);
    u = u + l1;
    
    k = a*tan(ofDegToRad(theta))/2;
};
void Link::draw() {
    

    
    
    // DRAW pivot points on guide
    output.changeColor(1.0f, 1.0f, 1.0f);
    output.circle(l1.x, l1.y, 5);
    output.circle(l2.x, l2.y, 5);
    
    // draw midpoint
    output.changeColor(255, 0, 0);
    output.circle(u.x,u.y, 3);

    ofVec2f midpointPerp = (l2-l1).getPerpendicular().scale(k) + u;
    
    output.line(u.x,u.y, midpointPerp.x, midpointPerp.y);
    
    output.changeColor(255,255,255);
    output.line(l1.x,l1.y, midpointPerp.x, midpointPerp.y);
    output.line(l2.x,l2.y, midpointPerp.x, midpointPerp.y);
    
    
    
    // draw virtual link
    output.changeColor(1.0f, 1.0f, 1.0f);
    output.line(l1.x,l1.y, l2.x, l2.y);
    
    

};


Link::Link() {
}
