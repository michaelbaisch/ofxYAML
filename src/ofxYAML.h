//
//  ofxYAML.h
//  ofxYAML
//
//  Created by Michael Baisch on 14.04.17.
//
//

#ifndef ofxYAML_hpp
#define ofxYAML_hpp

#include "ofUtils.h"
#include "yaml.h"

using namespace YAML;

class ofxYAML: public Node {
    
public:
    void load(string path);

};


#endif /* ofxYAML_hpp */
