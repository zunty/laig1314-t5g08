#ifndef _LINEARANIMATION_H_
#define _LINEARANIMATION_H_

#include "Animation.h"

class LinearAnimation: public Animation
{
	void init();
	vector<vector<float>> crtlpoints;

public:

	LinearAnimation();

	void update();

	void draw();

	void reset();

};


#endif