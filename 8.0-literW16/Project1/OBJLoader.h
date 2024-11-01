#pragma once
#include "Object.h"



class OBJLoader:Object
{

public:

	OBJLoader(string PATH);
	~OBJLoader();


private:
	void OpenObj();




private:
	std::string m_sPATH;
	


};

