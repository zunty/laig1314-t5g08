#include "Camera.h"

Camera::Camera(string id, float near, float far){
	this->id = id;
	this->near = near;
	this->far = far;
}

Perspective::Perspective(string id, float near, float far, float angle, vector<float> pos, vector<float> target): Camera(id, near, far){
	this->angle = angle;
	this->pos = pos;
	this->target = target;
}

Ortho::Ortho(string id, float near, float far, float left, float right, float top, float bottom): Camera(id, near, far){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

void Camera::print(){}

void Perspective::print(){
	/*
	cout << "Perspective Camera" << endl << endl;
	cout << "Id: " << getID() << endl;
	cout << "Near: " << getNear() << endl;
	cout << "Far: " << getFar() << endl;
	cout << "Angle: " << angle << endl;
	cout << "Position: " << pos[0] << ", " << pos[1] << ", " << pos[2] << endl;
	cout << "target: " << target[0] << ", " << target[1] << ", " << target[2] << endl << endl;
	*/
}	

float Perspective::getAngle()
{
   return angle;
}

vector<float> Perspective::getPos()
{
	return pos;
}

vector<float> Perspective::getTarget()
{
	return target;
}

float Perspective::getLeft()
{
	return 0;
}

float Perspective::getRight()
{
	 return 0;
}

float Perspective::getTop()
{
	return 0;
}

float Perspective::getBottom()
{
   return 0;
}

void Ortho::print(){
	/*
	cout << "Ortho Camera" << endl << endl;
	cout << "Id: " << getID() << endl;
	cout << "Near: " << getNear() << endl;
	cout << "Far: " << getFar() << endl;
	cout << "Left: " << left << endl;
	cout << "Right: " << right << endl;
	cout << "Top: " << top << endl;
	cout << "Bottom: " << bottom << endl << endl;
	*/
}

float Ortho::getLeft()
{
	return left;		
}

float Ortho::getRight()
{
	return right;
}

float Ortho::getTop()
{
   return top;
}

float Ortho::getBottom()
{
	 return bottom;
}

float Ortho::getAngle()
{
	return 0;
}

vector<float> Ortho::getPos()
{
	vector<float> v;
	v.clear();
	return v;
}

vector<float> Ortho::getTarget()
{
	vector<float> v;
	v.clear();
	return v;
}
