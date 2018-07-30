//
//  ofxYAML.h
//  ofxYAML
//
//  Created by Michael Baisch on 14.04.17.
//
//

#ifndef ofxYAML_hpp
#define ofxYAML_hpp

#include "ofMain.h"
#include "yaml.h"

using namespace YAML;

class ofxYAML: public Node {
    
public:
    void load(string path);

};

// Converting OF data types
namespace YAML {
    
    // Vector templates
    template<typename T, typename SubT>
    struct convertVector2 {
        static Node encodeVector2(const T& rhs) {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            return node;
        }
        
        static bool decodeVector2(const Node& node, T& rhs) {
            if (node.size() != 2) { return false; }
            
            if (node.IsSequence()) {    // [0, 1]
                rhs.x = node[0].as<SubT>();
                rhs.y = node[1].as<SubT>();
                return true;
            }
            else if (node.IsMap() && node["x"] && node["y"]) { // {x: 0, y: 1}
                rhs.x = node["x"].as<SubT>();
                rhs.y = node["y"].as<SubT>();
                return true;
            }
            return false;
        }
    };
    template<typename T, typename SubT>
    struct convertVector3 {
        static Node encodeVector3(const T& rhs) {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            node.push_back(rhs.z);
            return node;
        }
        
        static bool decodeVector3(const Node& node, T& rhs) {
            if (node.size() != 3) { return false; }
            
            if (node.IsSequence()) {
                rhs.x = node[0].as<SubT>();
                rhs.y = node[1].as<SubT>();
                rhs.z = node[2].as<SubT>();
                return true;
            }
            else if (node.IsMap() && node["x"] && node["y"] && node["z"]) {
                rhs.x = node["x"].as<SubT>();
                rhs.y = node["y"].as<SubT>();
                rhs.z = node["z"].as<SubT>();
                return true;
            }
            return false;
        }
    };
    template<typename T, typename SubT>
    struct convertVector4 {
        static Node encodeVector4(const T& rhs) {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            node.push_back(rhs.z);
            node.push_back(rhs.w);
            return node;
        }
        
        static bool decodeVector4(const Node& node, T& rhs) {
            if(!node.IsSequence() || node.size() != 4) {
                return false;
            }
            
            rhs.x = node[0].as<SubT>();
            rhs.y = node[1].as<SubT>();
            rhs.z = node[2].as<SubT>();
            rhs.w = node[3].as<SubT>();
            return true;
        }
    };
    
    
    // glm vectors
    template<typename T>
    struct convert<glm::tvec2<T>> {
        static Node encode(const glm::tvec2<T>& rhs) {
            return convertVector2<glm::tvec2<T>, T>().encodeVector2(rhs);
        }
        
        static bool decode(const Node& node, glm::tvec2<T>& rhs) {
            return convertVector2<glm::tvec2<T>, T>().decodeVector2(rhs);
        }
    };
    template<typename T>
    struct convert<glm::tvec3<T>> {
        static Node encode(const glm::tvec3<T>& rhs) {
            return convertVector3<glm::tvec3<T>, T>().encodeVector3(rhs);
        }
        
        static bool decode(const Node& node, glm::tvec3<T>& rhs) {
            return convertVector3<glm::tvec3<T>, T>().decodeVector3(node, rhs);
        }
    };
    template<typename T>
    struct convert<glm::tvec4<T>> {
        static Node encode(const glm::tvec4<T>& rhs) {
            return convertVector4<glm::tvec3<T>, T>().encodeVector4(rhs);
        }
        
        static bool decode(const Node& node, glm::tvec4<T>& rhs) {
            return convertVector4<glm::tvec4<T>, T>().decodeVector4(node, rhs);
        }
    };
    
    
    // OF Vectors
    template<>
    struct convert<ofVec2f> {
        static Node encode(const ofVec2f& rhs) {
            return convertVector2<ofVec2f, float>().encodeVector2(rhs);
        }
        
        static bool decode(const Node& node, ofVec2f& rhs) {
            return convertVector2<ofVec2f, float>().decodeVector2(node, rhs);
        }
    };
    template<>
    struct convert<ofVec3f> {
        static Node encode(const ofVec3f& rhs) {
            return convertVector3<ofVec3f, float>().encodeVector3(rhs);
        }
        static bool decode(const Node& node, ofVec3f& rhs) {
            return convertVector3<ofVec3f, float>().decodeVector3(node, rhs);
        }
    };
    template<>
    struct convert<ofVec4f> {
        static Node encode(const ofVec4f& rhs) {
            return convertVector4<ofVec4f, float>().encodeVector4(rhs);
        }
        static bool decode(const Node& node, ofVec4f& rhs) {
            return convertVector4<ofVec4f, float>().decodeVector4(node, rhs);
        }
    };
    
    
}


#endif /* ofxYAML_hpp */
