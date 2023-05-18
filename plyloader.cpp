#include "plyloader.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iterator>

#if _MSC_VER >= 1300

#include <iostream>

#else //  _MSC_VER >= 1300

#include <iostream.h>

#endif // _MSC_VER >= 1300
using namespace std;

static std::size_t countWInS(std::string const& _str)
{
	std::stringstream stream(_str);
	return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}


bool plyloader::load(
	const std::string& _filename,
	vector<Point>& _vertices,
	vector<Point>& _face_real,
	vector<Face>& _indices)
{

	ifstream f_op(_filename, std::ios::in);
	
	if (!f_op) {
		cerr << "Error: couldn't read ply file " << _filename << endl;
		return false;
	}


	string line;
	int nb_V = 0;
	int nb_F = 0;
	while (!f_op.eof())
	{
		getline(f_op, line);

		// reading data related to vertices number, face number
		if (std::sscanf(line.c_str(), "element vertex %d", &nb_V) == 1) { std::cout << "No. of Vertices: " << nb_V << std::endl; }

		if (std::sscanf(line.c_str(), "element face %d", &nb_F) == 1) { std::cout << "No. of Faces: " << nb_F << std::endl; }

		/*cout << line << endl;*/

		if (line == "end_header")
			break;
	}

	_vertices.clear();
	_indices.clear();
	_face_real.clear();
	_vertices.reserve(nb_V);
	_indices.reserve(nb_F);
	_face_real.reserve(nb_F);

	double x = 0.0f, y = 0.0f, z = 0.0f, s = 0.0f, t = 0.0f;

	while (!f_op.eof())											// Start reading  data related to vertices and faces
	{
		getline(f_op, line);
	/*	cout << line << endl;*/

		std::size_t nw = countWInS(line);

		if (nw == 3)
		{
			if (std::sscanf(line.c_str(), "%lf %lf %lf", &x, &y, &z) == 3)
			{
				//vector<float> temp_v{ x, y, z };
				Point p = { x,y,z};
				_vertices.push_back(p);						//	store vertex 
			}
		}
		else if (nw == 4)
		{
			if (std::sscanf(line.c_str(), "%lf %lf %lf %lf", &x, &y, &z, &s) == 4)
			{

				Face i = { y, z ,s };
				_indices.push_back(i);						//	store indices
			}
		}
	}

	// get real position value for each vertices in indices(triangle),add in to _face_real in order
	for (auto& p : _indices) {
		_face_real.push_back(_vertices[p.x]);
		_face_real.push_back(_vertices[p.y]);
		_face_real.push_back(_vertices[p.z]);
	}


	f_op.close();

	return true;

}