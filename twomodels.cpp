// The moving arm model.

#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include "plyloader.h"
#include "modelerglobals.h"
#include "animationcheck.h"
#if _MSC_VER >= 1300

#include <iostream>

#else //  _MSC_VER >= 1300

#include <iostream.h>
#include "meshmodel.h"

#endif // _MSC_VER >= 1300

using namespace std;

double x_slider_value;
double y_slider_value;
double cylinder_turn_slider_value;
double h1_slider_value;
double h2_slider_value;


class TWOModel : public ModelerView
{
public:
	TWOModel(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) {}


	virtual void draw();
};


ModelerView* createModel(int x, int y, int w, int h, char *label)
{
	return new TWOModel(x, y, w, h, label);
}

void TWOModel::draw()
{
	ModelerView::draw();
	//cout << "run_mesh is : " << run_mesh << '\n';


	// switch between mesh model and movingarm model by press t button on keyboard
	if (run_mesh) {
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_RED);
		glPushMatrix();

		vector< vector<double> >::iterator row;
		vector<double> triangle;
		for (auto& row : _face_real) {
			triangle.push_back(row.x);
			triangle.push_back(row.y);
			triangle.push_back(row.z);
			if (triangle.size() == 9) {
				drawTriangle(triangle[0], triangle[1], triangle[2], triangle[3], triangle[4], triangle[5], triangle[6], triangle[7], triangle[8]);
				triangle.clear();
			}
		}

		glPopMatrix();
	}
	else {
		// draw the floor rolling ball
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_CYAN);
		glPushMatrix();
		glTranslated(VAL(X), VAL(Y), VAL(Z));

		glTranslated(-0.5, 0, -0.5);
		drawSphere(0.5);
		glTranslated(1, 0, 0);
		drawSphere(0.5);
		glTranslated(0, 0, 1);
		drawSphere(0.5);
		glTranslated(-1, 0, 0);
		drawSphere(0.5);

		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_YELLOW);


		// draw base box
		glPushMatrix();
		glTranslated(-0.5, 0, -1.5);
		glScaled(2, 1, 2);
		drawBox(1, 0.5, 1);
		glPopMatrix();

		// draw arm extender (long slim cylinder)
		glPushMatrix();
		glTranslated(0.5, 0, -0.5);
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_RED);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(H1), 0.3, 0.3);


		// draw big cylinder 
		glTranslated(0.0, 0.0, VAL(H1));
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_MAGENTA);
		glRotated(VAL(Cylinder_TURN), 0.0, 0.0, 1.0);
		drawCylinder(1, 1.0, 0.9);

		// draw second layer arm extender (long slim cylinder)
		glTranslated(0.0, 0.0, 1);
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_GREEN);
		drawCylinder(VAL(H2), 0.3, 0.3);

		// draw second layer big cylinder 
		glTranslated(0.0, 0.0, VAL(H2));
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_MAGENTA);
		glRotated(VAL(Cylinder_TURN), 0.0, 0.0, 1.0);
		drawCylinder(1, 0.8, 0.7);


		// draw lower arm (long box)*/
		glTranslated(-0.25, -0.25, 1);
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_BLUE);
		glRotated(VAL(Lower_Arm_TILT), 1.0, 1.0, 0.0);
		drawBox(0.5, 0.5, 1);

		//draw upper arm (long box)
		glTranslated(0, 0, 1);
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_YELLOW);
		glRotated(VAL(Upper_Arm_TILT), 1.0, 1.0, 0.0);
		drawBox(0.4, 0.4, 0.8);



		glPopMatrix();

		glPopMatrix();
		if (animation_check) {
			x_slider_value = VAL(X) + 0.005;
			y_slider_value = VAL(Y) + 0.005;
			h1_slider_value = VAL(H1) + 0.001;
			h2_slider_value = VAL(H2) + 0.001;
			cylinder_turn_slider_value = VAL(Cylinder_TURN) + 1;

			CHANGE(X, x_slider_value);
			CHANGE(Y, y_slider_value);
			CHANGE(H1, h1_slider_value);
			CHANGE(H2, h2_slider_value);
			CHANGE(Cylinder_TURN, cylinder_turn_slider_value);
		}
	}

}


int main()
{
	ModelerControl controls[NCONTROLS];
	controls[X] = ModelerControl("X", -5, 5, 0.1f, -2);
	controls[Y] = ModelerControl("Y", -5, 5, 0.1f, -2);
	controls[Z] = ModelerControl("Z", -5, 5, 0.1f, 0);
	controls[H1] = ModelerControl("H1", 0, 2.5, 0.1f, 0);
	controls[H2] = ModelerControl("H2", 0, 2.5, 0.1f, 0);
	controls[Cylinder_TURN] = ModelerControl("Cylinder_TURN", -90, 90, 1, 0);
	controls[Lower_Arm_TILT] = ModelerControl("Lower_Arm_TILT", -90, 90, 1, 0);
	controls[Upper_Arm_TILT] = ModelerControl("Upper_Arm_TILT", -90, 90, 1, 0);


	ModelerApplication::Instance()->Init(&createModel, controls, NCONTROLS);
	return ModelerApplication::Instance()->Run();
}
