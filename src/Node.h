#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Primitives.h"
#include "Transform.h"

using namespace std;

class Node
{
	string id, appearanceref, animationref;
	bool display_list;
	vector<Scale*> scales;
	vector<Translate*> translations;
	vector<Rotation*> rotations;
	vector<Patch*> patches;
	vector<Plane*> planes;
	vector<Rectangle*> rectangles;
	vector<Triangle*> triangles;
	vector<Cylinder*> cylinders;
	vector<Shpere*> spheres;
	vector<Torus*> torus;
	vector<string> noderefs;
	vector<Transform*> transforms;
	
	
public:

	Node(string id, string appearanceref_id, string animationref, vector<string> noderefs, vector<Scale*> scales, vector<Translate*> translations, vector<Rotation*> rotations, vector<Patch*> patches, vector<Plane*> planes,  vector<Rectangle*> rectangles, vector<Triangle*> triangles, vector<Cylinder*> cylinders, vector<Shpere*> spheres, vector<Torus*> torus, vector<Transform*> transforms, bool display_list);

	//GETS
	string getId();
	string getAppearancesref();
	string getAnimationref();
	vector<string> getNoderefs();
	vector<Scale*> getScales();
	vector<Transform*> getTransforms();
	vector<Translate*> getTranslations();
	vector<Rotation*>  getRotations();
	vector<Patch*> getPatches();
	vector<Plane*> getPlanes();
	vector<Rectangle*>	getRectangles();
	vector<Triangle*> getTriangles();
	vector<Cylinder*> getCylinders();
	vector<Shpere*>	 getSpheres();
	vector<Torus*>	getTorus();
	bool getDisplayList();

	void print();
};

#endif