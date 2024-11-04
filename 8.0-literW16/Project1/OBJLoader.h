#pragma once
#include "Object.h"



class OBJLoader:Object
{

public:

	OBJLoader(string PATH);
	~OBJLoader();


private:
	void FindVertexPosition();




private:
	string m_sPATH;
	string currentLine;
	Object myObject;
	

	


};

