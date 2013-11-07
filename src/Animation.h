#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "CGFApplication.h"
#include <stdio.h>

class Animation
{
	string id, type;
	float span;
	void init();

public:

	Animation(string id, float span, string type);

	virtual void update(unsigned long t);
	virtual void draw();
	virtual void reset();

	virtual ~Animation();

};

#endif