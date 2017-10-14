//===================================== =======================================
// Name        : main.cpp
// Author      : Peter Gillespie
// Version     : v1
// Copyright   : Your copyright notice
// Description : Particle Explosion simulation using SDL
//============================================================================
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Particle.h"
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace ParticleExplosion;

int main() {
	srand(time(NULL));
	Screen screen;

	if (screen.init() == false) {
		cout << "Error Initializing SDL." << endl;
	}

	Swarm swarm;

	const int WCENTER = Screen::SCREEN_WIDTH / 2;
	const int HCENTER = Screen::SCREEN_HEIGHT / 2;

	while (true) {
		//game loop
		//draw particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = (1 + cos(elapsed * 0.0006)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0003)) * 128;
		unsigned char blue = (1 + cos(elapsed * 0.0009)) * 128;

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * WCENTER;
			int y = particle.m_y * WCENTER + HCENTER;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//draw screen
		screen.update();

		//check for messages and events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
