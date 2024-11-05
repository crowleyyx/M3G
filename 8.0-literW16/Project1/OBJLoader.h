#pragma once
#include "Object.h"



class OBJLoader:Object
{

public:

	OBJLoader(string PATH);
	~OBJLoader();


public:
	void FindVertexPosition();




private:
	string m_sPATH;
	string currentLine;
	Object myObject;
	

	


};

