# ofxYAML

A wrapper for [yaml-cpp](https://github.com/jbeder/yaml-cpp).

Tested with [OpenFrameworks](http://openframeworks.cc) (0.10.0).
Works with both macOS Sierra (Xcode 9.4) and Windows (VS 2017).

<br />

### Usage

You can use the OF Project Generator to add this addon in your project.

```cpp
#include "ofxYAML.h"
```

Place your yaml file in the bin/data folder and access it with:

```cpp
yaml.load("config.yaml");

int framerate = yaml["frameRate"].as<int>();
bool verticalSync = yaml["verticalSync"].as<bool>();
string title = yaml["title"].as<string>();
```
