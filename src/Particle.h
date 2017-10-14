/*
 * Particle.h
 *
 *  Created on: May 29, 2017
 *      Author: P3DR0
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace ParticleExplosion {

struct Particle{
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

public:
	Particle();
	virtual ~Particle();
	void update(int m_interval);

private:
	void init();
};

}/*namespace ParticleExplosion*/

#endif /* PARTICLE_H_ */
