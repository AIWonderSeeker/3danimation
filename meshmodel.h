#pragma once
class MeshModel : public ModelerView
{
public:
	MeshModel(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) { }

	virtual void draw();

};

ModelerView* createMeshModel(int x, int y, int w, int h, char *label);


