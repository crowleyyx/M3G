#include "OBJLoader.h"



OBJLoader::OBJLoader(string PATH): 
	m_sPATH(PATH)
{
};

OBJLoader::~OBJLoader(){};


void OBJLoader::FindVertexPosition()
{

		
		size_t xBegin = currentLine.find(' ');
		size_t xEnd = currentLine.find(' ', xBegin + 1);
		size_t yEnd = currentLine.find(' ', xEnd + 1);
		size_t zEnd = currentLine.find(' ', yEnd + 1);

		vertexPosition tempPosition;

		tempPosition.x = stof(currentLine.substr(xBegin + 1, xEnd + 1));
		tempPosition.y = stof(currentLine.substr(xEnd + 1, yEnd));
		tempPosition.z = stof(currentLine.substr(yEnd + 1, zEnd));

		myObject.vVertexCoord.push_back(tempPosition);
		

};

void OBJLoader::FindTextureCoord()
{
		size_t uBegin= currentLine.find(' ');
		size_t uEnd = currentLine.find(' ', uBegin + 1);
		size_t vEnd = currentLine.find(' ', uEnd + 1);


		textureCoord tempCoord;

		tempCoord.uv_x= stof(currentLine.substr(uBegin + 1, uEnd + 1));
		tempCoord.uv_y= stof(currentLine.substr(uEnd + 1, vEnd));


		myObject.vTextureCoord.push_back(tempCoord);

};

void OBJLoader::FindVertexNormal()
{

	size_t xBegin = currentLine.find(' ');
	size_t xEnd = currentLine.find(' ', xBegin + 1);
	size_t yEnd = currentLine.find(' ', xEnd + 1);
	size_t zEnd = currentLine.find(' ', yEnd + 1);

	vertexNormal tempVertexNormal;

	tempVertexNormal.x = stof(currentLine.substr(xBegin + 1, xEnd + 1));
	tempVertexNormal.y = stof(currentLine.substr(xEnd + 1, yEnd));
	tempVertexNormal.z = stof(currentLine.substr(yEnd + 1, zEnd));

	myObject.vVertexNormal.push_back(tempVertexNormal);

};


