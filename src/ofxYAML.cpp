//
//  ofxYAML.cpp
//  ofxYAML
//
//  Created by Michael Baisch on 14.04.17.
//
//

#include "ofxYAML.h"

void ofxYAML::load(string path) {
    path = ofToDataPath(path);
    this->Node::operator=(LoadFile(path));
}
