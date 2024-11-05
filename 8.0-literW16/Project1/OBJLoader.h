#pragma once
#include "Object.h"



class OBJLoader:Object
{

public:

	OBJLoader(string PATH);
	~OBJLoader();


public:
	void FindVertexPosition();
	void FindTextureCoord();
	void FindVertexNormal();



private:
	string m_sPATH;
	string currentLine;
	Object myObject;
	

	


};

