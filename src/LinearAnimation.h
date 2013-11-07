#ifndef _LINEARANIMATION_H_
#define _LINEARANIMATION_H_

#include "Animation.h"

class LinearAnimation: public Animation
{
	void init(unsigned long t);
	unsigned long startTime;
	unsigned char doReset;
	vector<vector<float>> crtlpoints;

public:

	LinearAnimation(string id, float span, string type, vector<vector<float>> crtlpoints);

	void update(unsigned long t);
	void draw();
	void reset();

};


#endif