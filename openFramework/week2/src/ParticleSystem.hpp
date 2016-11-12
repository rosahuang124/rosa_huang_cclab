//
//  ParticleSystem.hpp
//  w2ParticlePractice
//
//  Created by Rosa on 11/12/16.
//
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include "ofMain.h" //file in project folder using""
#include "Particle.hpp"

class ParticleSystem {
public:
    
    ParticleSystem(ofVec2f postition);
    void update(ofVec2f force);
    void draw();
    
    vector<Particle> mParticleList; // vector is like an array container, vector can grow but array can't
    ofVec2f mPosition;
    int mEmitRate;
    const int SIZE_LIMIT = 500;
    bool mIsAddingParticles;
    
};


#endif /* ParticleSystem_hpp */
