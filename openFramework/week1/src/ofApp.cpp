#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set window's title
    ofSetWindowTitle("openFramework w1 Homework");

    ofSetCircleResolution(20);
    
    //initialize variables
    circleX = 0;
    circleY = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    circleX += 2;
    circleY += 2;
    
    
    // make the circle come back to screen
    if(circleX > ofGetWindowWidth()){
        circleX = 0;
    }
    
    if(circleY > ofGetWindowHeight()){
        circleY = 0;
    }
    
    
    //make the rect follow the mouse
    if(rectX < mouseX){
        rectX += 3;
    }else if (rectX > mouseX){
        rectX -= 3;
    }
    
    if(rectY < mouseY){
        rectY += 3;
    }else if (rectY > mouseY){
        rectY -= 3;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(100, 215, 255);
    
    ofSetColor(255, 255, 105);
    ofDrawCircle(circleX, circleY, 50);
    
    ofSetColor(190, 145, 255);
    ofDrawRectangle(rectX, rectY, 60, 60);
    
    //making bg with mouse drag
    ofSetColor(255, 255, 255, 100);
    ofDrawRectangle(200, 150, rectWidth, rectHeight);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   
    rectWidth = x;
    rectHeight = y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    bgX = x;
    bgY = y;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
