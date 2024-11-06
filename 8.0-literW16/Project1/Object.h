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

		int vertexIndex;              
		int texIndex;  
		int normIndex; 

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

	struct Material {
		float materialKa;
		float materialKd;
		float materialKs;
		float materialNS;
		float materialNi;
		float materiald;
		string textureAdress;

	};

	
public:

	vector<vertexPosition>		vVertexCoord;
	vector<textureCoord>		vTextureCoord;
	vector<Indices>				vIndices;
	vector<vertexNormal>		vVertexNormal;
	Material					m_Material;

	


};

