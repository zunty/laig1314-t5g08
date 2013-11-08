#ifndef _INCREMENTANIMATED_OBJECT_H_
#define _INCREMENTANIMATED_OBJECT_H_

#include <vector>
#include <iostream>
using namespace std;

class IncrementAnimatedObject
{
	public:
		IncrementAnimatedObject(unsigned long milli_secs);
		void update(unsigned long t);
		void draw();
		void reset();

	private:
		vector<vector<double>> points;
		double  x, y, z, dx, xy, dz, v, md, vecx, vecy, vecz, velocity, vx, vy, vz;
		unsigned long endtime;
		unsigned char doReset;
		unsigned int i;
		unsigned long Rtime;
		bool check;
		void init(unsigned long t);
		
};

#endif