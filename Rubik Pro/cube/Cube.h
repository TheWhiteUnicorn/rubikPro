#pragma once
#include "..\res\res.hpp"
class Cube
{
public:
	//
	Cube();
	Cube(color(&edg)[6][3][3]);
	~Cube();
	const color*** get_edges();


	void reset();
	void rotate(char* direction);
private:
	void initEdges();
	color*** edges;
};

