#pragma once
#include <glfw3.h>
#include <glfw3native.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Object
{
protected:
	struct Indices {

		int index;
	};

	struct textureCoord {

		float uv_x;
		float uv_y;
	};

	struct vertexPosition {

		float x;
		float y;
		float z;

	};

	struct vertexNormal {

		float x;
		float y;
		float z;
	};

public:

	vector<vertexPosition> VertexCoord;

	


};

