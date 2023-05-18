
#include <vector>

using namespace std;

class plyloader
{
public:
	// data strucute to store a vertex
	struct Point
	{
		double x, y, z;
	};

	// data strucute to store a triangle
	struct Face
	{
		double x, y, z;
	};

public:
	// function to load file data into 3 global vectors , so data saved in memeory
	bool load(
		const std::string& _filename,
		vector<Point>& _vertices, 
		vector<Point>& _face_real, 
		vector<Face>& _indices);
};

// global vectors ,cpp files can access them directly
extern vector<plyloader::Point>  _vertices;
extern vector<plyloader::Point>  _face_real;
extern vector<plyloader::Face>  _indices;
