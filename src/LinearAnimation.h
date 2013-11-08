#ifndef _LINEARANIMATION_H_
#define _LINEARANIMATION_H_

#include "Animation.h"
#include <iostream>


class LinearAnimation: public Animation
{
	vector<vector<float>> points;
	float x, y, z, dx, dy, dz, v, md, vecx, vecy, vecz, velocity, vx, vy, vz;
	unsigned long endtime;
	unsigned char doReset;
	unsigned int i;
	unsigned long Rtime;
	float span;
	bool check;
	void init(unsigned long t);

public:

	LinearAnimation(string id, float span, string type, vector<vector<float>> crtlpoints);
	void update(unsigned long t);
	void draw();
	void reset();
	vector<vector<float>> getControlPoints();
};


#endif