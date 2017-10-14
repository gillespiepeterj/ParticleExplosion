/*
 * Swarm.h
 *
 *  Created on: May 29, 2017
 *      Author: P3DR0
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace ParticleExplosion {

class Swarm{
private:
	Particle * m_pParticles;
	int m_lastTime;
public:
	const static int NPARTICLES = 5000;
	const Particle * const getParticles() { return m_pParticles; };
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
};

} /*namespace Particle Explosion*/

#endif /* SWARM_H_ */
