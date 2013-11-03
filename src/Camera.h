#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Camera{

	string id;
	float near;
	float far;

public:

	Camera(string id, float near, float far);

	string getID();
	float getNear(); 
	float getFar();

	//Virtuals
	virtual float getAngle() = 0;
	virtual vector<float> getPos() = 0;
	virtual vector<float> getTarget() = 0;

	virtual float getLeft() = 0;
	virtual float getRight() = 0;
	virtual float getTop() = 0;
	virtual float getBottom() = 0;

	virtual void print();
};

class Perspective: public Camera{
	float angle;
	vector<float> pos;
	vector<float> target;
public:
	Perspective(string id, float near, float far, float angle, vector<float> pos, vector<float> target);
	
	float getAngle();
	vector<float> getPos();
	vector<float> getTarget();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	void print();
};

class Ortho: public Camera{
	float left;
	float right;
	float top;
	float bottom;
public:
	Ortho(string id, float near, float far, float left, float right, float top, float bottom);
	void print();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
	float getAngle();
	vector<float> getPos();
	vector<float> getTarget();

};