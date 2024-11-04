#include "OBJLoader.h"



OBJLoader::OBJLoader(string PATH) {
	m_sPATH = PATH;
};

OBJLoader::~OBJLoader(){

};


void OBJLoader::FindVertexPosition()
{
	if (currentLine[0] == 'v' && currentLine[1] != 't' && currentLine[0] != 'n')
	{
		
		size_t xBegin = currentLine.find(' ');
		size_t xEnd = currentLine.find(' ', xBegin + 1);
		size_t yEnd = currentLine.find(' ', xEnd + 1);
		size_t zEnd = currentLine.find(' ', yEnd + 1);

		vertexPosition tempPosition;

		tempPosition.x = stof(currentLine.substr(xBegin + 1, xEnd + 1));
		tempPosition.y = stof(currentLine.substr(xEnd + 1, yEnd));
		tempPosition.z = stof(currentLine.substr(yEnd + 1, zEnd));

		myObject.VertexCoord.push_back(tempPosition);
			
	}


};


