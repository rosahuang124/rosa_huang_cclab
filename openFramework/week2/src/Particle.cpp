//
//  Particle.cpp
//  w2ParticlePractice
//
//  Created by Rosa on 11/12/16.
//
//

#include "Particle.hpp"


Particle::Particle(ofVec2f pos){
    mPosition = pos;
    mVelocity = ofVec2f(ofRandom(2.f, -2.f), ofRandom(1.f, -1.f));
    mAcceleration = ofVec2f(0, 0);
    mLifeSpan = INITIAL_LIFE_SPAN;
}


void Particle::resetForces(){
    
    mAcceleration *= 0;
}

void Particle::applyForce(ofVec2f force){
    
    mAcceleration += force;

}

void Particle::update(float multiplier){
    
    //apply accelaration to velovity
    mVelocity += mAcceleration;
    mPosition += mVelocity * multiplier;
  
    
    //decrease the particle life
    if (mLifeSpan > 0) {
        mLifeSpan -= 1.0f;
    }

}

void Particle::draw(){
    
    if (mLifeSpan > BLINKING_LIFE_SPAN) {
        //new born partivle will be brighter
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    } else {
        //do some sparkle!
        ofSetColor(ofRandom(0, mLifeSpan/INITIAL_LIFE_SPAN * 255));
    }
    

    
    ofDrawRectangle(mPosition,  5.0f * ofMap(mLifeSpan, 0, 200.0f, 0, 3.0),  5.0f * ofMap(mLifeSpan, 0, 200.0, 0, 3.0));

}
