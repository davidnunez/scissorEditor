//
//  Link.h
//  scissorEditor
//
//  Created by David Nunez on 2/25/13.
//
//

#ifndef __scissorEditor__Link__
#define __scissorEditor__Link__

#include <iostream>
#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include <string>

class Link {
    public:

    float force;
    float theta;
    float strokeLength;

    ofVec2f s; // vector for stroke endpoint
    
    
    ofVec2f c1;
    ofVec2f l1;
    ofVec2f l2;
    ofVec2f l3;
    ofVec2f l4;

    
    float A;
    float B;
    float C;
    float a;
    float b;
    float c;

    float H;
    float I;
    float J;
    float h;
    float i;
    float j;
    
    float k;
    ofVec2f u;
    ofVec2f v;
    ofVec2f w;
    ofVec2f test;

    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    Link();


    private:
    
    ofxVectorGraphics output;

};

#endif /* defined(__scissorEditor__Link__) */

