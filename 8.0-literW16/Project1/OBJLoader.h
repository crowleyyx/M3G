#pragma once
#include "Object.h"



class OBJLoader:Object
{

public:

	OBJLoader(string PATH);
	~OBJLoader();

	void readObj();


private:
	void getVertexPosition();
	void getTextureCoord();
	void getVertexNormal();
	void getIndices();
	void getMaterialInfo();
	void getMaterialKa();
	void getMaterialKs();
	void getMaterialKd();
	void getTextureAdress();


private:
	string m_sPATH;
	string currentLine;
	Object myObject;

	

	


};

