#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    
    static const int NUM = 500;
    std::vector<glm::vec3> positions; //座標
    std::vector<glm::vec3> dstPositions; //イージング用の移動先の座標
    std::vector<glm::vec3> sizes;//座標
    std::vector<glm::vec3> dstSizes;//イージング用の移動先の座標
    
    ofEasyCam cam;
    ofLight light;
    
    void dstPositionSetter();
    void dstScaleSetter();
    
    static const int scaleMax = 15;
    static const int scaleMin = 5;
};
