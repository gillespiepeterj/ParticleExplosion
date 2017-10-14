/*
 * Swarm.cpp
 *
 *  Created on: May 29, 2017
 *      Author: P3DR0
 */

#include "Swarm.h"

namespace ParticleExplosion {

Swarm::Swarm(): m_lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}


Swarm::~Swarm(){
	delete[] m_pParticles;
}

void Swarm::update(int elapsed) {
	int m_interval = elapsed - m_lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(m_interval);
	}

	m_lastTime = elapsed;
}

} /*namespace ParticleExplosion*/
