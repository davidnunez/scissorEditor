//
//  Linkage.h
//  scissorEditor
//
//  Created by David Nunez on 2/25/13.
//
//

#ifndef __scissorEditor__Linkage__
#define __scissorEditor__Linkage__

#include <iostream>
#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include <string>
#include "Link.h"

class Linkage {
public:
    float force;
    float strokeLength;
    float theta;
    float a1;
    float a2;
    
    Link link1;
    Link link2;
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    Linkage();
};




#endif /* defined(__scissorEditor__Linkage__) */
