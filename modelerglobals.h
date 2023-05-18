#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE,NUMCONTROLS
};

enum RobotArmModelControls
{
	X, Y, Z, H1,H2,Cylinder_TURN, Lower_Arm_TILT, Upper_Arm_TILT, NCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_YELLOW	1.0f, 1.0f, 0.0f
#define COLOR_CYAN	    0.0f, 1.0f, 1.0f
#define COLOR_GRAY	    8.0f, 8.0f, 8.0f
#define COLOR_MAGENTA	1.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))
#define CHANGE(x,i) (ModelerApplication::Instance()-> SetControlValue(x, i))

#endif