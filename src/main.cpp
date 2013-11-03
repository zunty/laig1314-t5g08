/* 
 * G0_Base: projeto inicial de CGra
 * 
 */

#include <iostream>
#include <exception>
#include<stdio.h>
#include<conio.h>
#include <math.h>
#include "TPinterface.h"
#include "GraphScene.h"
#include "CGFapplication.h"

using std::cout;
using std::exception;

int main(int argc, char* argv[]) {


	CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);
		GraphScene yaf = GraphScene("grapho.yaf");
		app.setScene(new GraphScene(yaf));
		app.setInterface(new CGFinterface());
		app.setInterface(new TPinterface());
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Error: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Unexpected error: " << ex.what();
		return -1;
	}
	return 0;
}