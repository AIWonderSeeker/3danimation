//
//#include "modelerview.h"
//#include "modelerapp.h"
//#include "modelerdraw.h"
//#include <FL/gl.h>
//
//#include "modelerglobals.h"
//
//
//#include "plyloader.h"
//
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <iterator>
//#include "common.h"
//
//#if _MSC_VER >= 1300
//
//#include <iostream>
//
//#else //  _MSC_VER >= 1300
//
//#include <iostream.h>
//#include "meshmodel.h"
//
//#endif // _MSC_VER >= 1300
//using namespace std;
//
//
//
//
//class MeshModel : public ModelerView
//{
//public:
//	char *label;
//public:
//	MeshModel(int x, int y, int w, int h, char *label)
//		: ModelerView(x, y, w, h, label) { }
//
//	virtual void draw();
//};
//
//
//ModelerView* createMeshModel(int x, int y, int w, int h, char *label)
//{
//	return new MeshModel(x, y, w, h, label);
//}
//
//
// void MeshModel::draw()
//{
//	ModelerView::draw();
//
//	setAmbientColor(.1f, .1f, .1f);
//	setDiffuseColor(COLOR_RED);
//	glPushMatrix();
//
//	vector< vector<double> >::iterator row;
//	vector<double> triangle;
//	for (auto& row : _face_real) {
//		cout << "triangle vertice is" << " ";
//		cout << row.x << " ," << row.y << ", " << row.z << endl;
//		triangle.push_back(row.x);
//		triangle.push_back(row.y);
//		triangle.push_back(row.z);
//		if (triangle.size() == 9) {
//			drawTriangle(triangle[0], triangle[1], triangle[2], triangle[3], triangle[4], triangle[5], triangle[6], triangle[7], triangle[8]);
//			triangle.clear();
//		}
//	}
//
//	glPopMatrix();
//}
//

//int main()
//{
//	/* Initialize the controls*/
//	 //Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
//	 //stepsize, defaultvalue)
//	ModelerControl controls[NUMCONTROLS];
//	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
//	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
//	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
//	controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
//	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
//
//ModelerApplication::Instance()->Init(&createMeshModel, controls, NUMCONTROLS);
//return ModelerApplication::Instance()->Run();
//}
