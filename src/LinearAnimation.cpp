#include "LinearAnimation.h"

LinearAnimation::LinearAnimation( string id, float span, string type, vector<vector<float>> crtlpoints ): Animation(id, span, type)
{
	this->crtlpoints = crtlpoints;
	reset();
}

void LinearAnimation::init(unsigned long t)
{
	startTime = t;
	doReset = false;
}

void LinearAnimation::update( unsigned long t )
{
	if(doReset)
		init(t);
	else
	{
		unsigned long span = t - startTime;
	}
}

void LinearAnimation::draw()
{

}

void LinearAnimation::reset()
{
	doReset = true;
}

