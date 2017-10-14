/*
 * Screen.h
 *
 *  Created on: May 29, 2017
 *      Author: P3DR0
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace ParticleExplosion {

class Screen{
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32  * m_buffer1;
	Uint32  * m_buffer2;
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
public:
	Screen();
	virtual ~Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void boxBlur();
	void close();
};

} /*namespace ParticleExplosion*/

#endif /* SCREEN_H_ */
