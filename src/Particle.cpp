/*
 * Particle.cpp
 *
 *  Created on: May 29, 2017
 *      Author: P3DR0
 */

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include "Particle.h"

namespace ParticleExplosion {

Particle::Particle(): m_x(0), m_y(0) {
	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.024 * rand()) / RAND_MAX;
	m_speed *= m_speed;

}

Particle::~Particle(){
}

void Particle::update(int m_interval) {
	m_direction += m_interval * 0.00038;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * m_interval;
	m_y += yspeed * m_interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}
	if (rand() < RAND_MAX / 100) {
		init();
	}
}

}/*namespace ParticleExplosion*/
