#ifndef _GRAPHSCENE_H_
#define _GRAPHSCENE_H_

#include "NodeScene.h"

class GraphScene: public CGFscene
{
public:	

	void setLights(Lighting* lights);
	void setCameras(Camera* cameras);

	GraphScene(char *filename);
	void init();
	void display();
	void update(unsigned long t);
	~GraphScene();

private:
	
	FileReading* f;
	NodeScene* root_node;
	vector<CGFlight*> lights; 
	vector<CGFcamera*> cameras;

};



#endif