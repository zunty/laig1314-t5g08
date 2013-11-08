#include "GraphScene.h"


GraphScene::GraphScene( char *filename )
{
	f = new FileReading(filename);
	root_node = new NodeScene(f->root_node_id, f->appearances, f->animations, f->textures, f->nodes);
}

void GraphScene::init()
{
	//f->print();
	//f->printNodes();

	setUpdatePeriod(50);
}

void GraphScene::display()
{
	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw axis
	axis.draw();

	root_node->draw();
	
	// ---- END Background, camera and axis setup

	// ---- END feature demos

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

void GraphScene::update( unsigned long t )
{
	for(unsigned int i = 0; i < f->animations.size(); i++)
	{
		f->animations[i]->update(t);
	}
}

GraphScene::~GraphScene()
{

}
