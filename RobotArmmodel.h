#pragma once
class RobotArmModel : public ModelerView
{
public:
	RobotArmModel(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) { }

	virtual void draw();

};

ModelerView* createRobotArmModel(int x, int y, int w, int h, char *label);
