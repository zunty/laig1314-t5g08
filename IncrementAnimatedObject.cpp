#include "IncrementAnimatedObject.h"
#include <GL/glut.h>
#include <stdio.h>

#define VM 0.01


IncrementAnimatedObject::IncrementAnimatedObject(unsigned long mili_secs)
{
	vector<double> p1;
	p1.push_back(5.0);
	p1.push_back(6.0);
	p1.push_back(7.0);

	vector<double> p2;
	p2.push_back(7.0);
	p2.push_back(3.0);
	p2.push_back(0.0);

	vector<double> p3;
	p3.push_back(4.0);
	p3.push_back(-2.0);
	p3.push_back(-5.0);

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	x = 0.0;
	y = 0.0;
	z = 0.0;

	i = 100;
	check = false;

	reset();
}

void IncrementAnimatedObject::reset()
{
	doReset = true;
}

void IncrementAnimatedObject::init(unsigned long t)
{
	vecx = points[i][0] - x;
	vecy = points[i][1] - y;
	vecz = points[i][2] - z;

	cout << "ENTROU\n\n";

	vx = (points[i][0] * VM) / 50;
	vy = (points[i][1] * VM) / 50;
	vz = (points[i][2] * VM) / 50;

	cout << "ENTROU\n\n";

	velocity = sqrt(pow(vx, 2) + pow(vy, 2) + pow(vz, 2));

	cout << "ENTROU\n\n";

	md = sqrt(pow(vecx, 2) + pow(vecy, 2) + pow(vecz, 2));

	cout << "ENTROU\n\n";

	endtime = t + (md / velocity);

	//cout << "ENTROU\n\n";

	doReset=false;
}


void IncrementAnimatedObject::update(unsigned long t)
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

void IncrementAnimatedObject::draw()
{
	//cout << "VELHO\n";

	glPushMatrix();

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
			glutSolidTeapot(1);
			glEnd();
		}
		
	}

	
	
	glPopMatrix();
}

