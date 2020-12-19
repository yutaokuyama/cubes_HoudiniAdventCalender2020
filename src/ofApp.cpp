#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int range = 150;
    for(int i = 0;i<NUM;i++){
        glm::vec3 position(ofRandom(-range,range),
                           ofRandom(-range-100,range-100),
                           ofRandom(-range,range));

        glm::vec3 scale(ofRandom(scaleMin,scaleMax),
                        ofRandom(scaleMin,scaleMax),
                        ofRandom(scaleMin,scaleMax));
        
        positions.push_back(position);
        dstPositions.push_back(position);
        sizes.push_back(scale);
        dstSizes.push_back(scale);
    }
}

void ofApp::dstPositionSetter(){
    int offset = 10;
    for(auto& dstPosition: dstPositions){
        int seed = ofRandom(10);
        switch(seed){
            case 0:
                dstPosition += glm::vec3(ofRandom(-offset,offset),
                                         ofRandom(0,offset),
                                         ofRandom(-offset,offset));
                break;
            default:
                break;
        }
    }
}

void ofApp::dstScaleSetter(){
    int offset = 10;
    for(auto& dstScale: dstSizes){
        int seed = ofRandom(10);
        switch(seed){
            case 0:
                dstScale = glm::vec3(ofRandom(scaleMin,scaleMax),
                                         ofRandom(scaleMin,scaleMax),
                                         ofRandom(scaleMin,scaleMax));
                break;
            default:
                break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    dstPositionSetter();
    dstScaleSetter();
    for(int i=0;i<NUM;i++){
        positions[i] +=(dstPositions[i]-positions[i])/3.0;
        sizes[i] +=(dstSizes[i]-sizes[i])/3.0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    light.enable();
    cam.begin();
    ofDrawBox(positions[0], 10);
    for(int i = 0;i<NUM;i++){
        ofPushMatrix();
        ofTranslate(positions[i]);
        ofDrawBox(positions[i],sizes[i].x,sizes[i].y,sizes[i].z);
        ofPopMatrix();
    }

    cam.end();
    light.disable();
    ofDisableDepthTest();
    
}

//--------------------------------------------------------------
