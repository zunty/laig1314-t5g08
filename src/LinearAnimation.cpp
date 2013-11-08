#include "LinearAnimation.h"

#define VM 0.01

LinearAnimation::LinearAnimation( string id, float span, string type, vector<vector<float>> points ): Animation(id, span, type)
{
	this->points = points;

	x = 0;
	y = 0;
	z = 0;

	i = 100;

	check = false;
	reset();
}

void LinearAnimation::init(unsigned long t)
{
	unsigned int d = 0;
	if(i != 100)
		d = i;
	else
		d = 0;

	vecx = points[d][0] - x;
	vecy = points[d][1] - y;
	vecz = points[d][2] - z;

	vx = (points[d][0] * VM) / 50;
	vy = (points[d][1] * VM) / 50;
	vz = (points[d][2] * VM) / 50;

	velocity = sqrt(pow(vx, 2) + pow(vy, 2) + pow(vz, 2));

	md = sqrt(pow(vecx, 2) + pow(vecy, 2) + pow(vecz, 2));

	endtime = t + (md / velocity);

	doReset = false;
}

void LinearAnimation::update(unsigned long t)
{
	if (doReset)
		init(t);

	else
	{
		//cout << "ENTROU\n\n";

		if(t < endtime)
		{
			//cout << "ENTROUHHHH\n\n";

			x += VM * vecx;
			y += VM * vecy;
			z += VM * vecz;

			cout << "X: " << x << endl;
			cout << "Y: " << y << endl;
			cout << "Z: " << z << endl;
			Rtime = t;
		}
		else
		{
			Rtime = t;
			i++;
			check = true;
		}

		//cout << "ENTROU\n\n";
	}
}

void LinearAnimation::draw()
{
	//cout << "VELHO\n";


	if( i == 100)
	{
		glTranslatef(x, y, z);
		i = 0;
	}

	else
	{
		if(check == true)
		{
			//cout << "VELHO\n";

			//cout << "ENTROU\n\n";
			glTranslatef(x, y, z);

			//cout << "ENTROU\n\n";
			check = false;
			//cout << "ENTROU\n\n";
			init(Rtime);

			//cout << "ENTROU\n\n";
			glutSolidTeapot(1);

			//cout << "ENTROU\n\n";
			glEnd();	

			//cout << "VELHO\n";		
		}

		else
		{
			glTranslatef(x, y, z);
			glEnd();
		}

	}

}

void LinearAnimation::reset()
{
	doReset = true;
}

vector<vector<float>> LinearAnimation::getControlPoints()
{
	return points;
}

