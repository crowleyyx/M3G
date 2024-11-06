#include "OBJLoader.h"



OBJLoader::OBJLoader(string PATH)
{
	m_sPATH = PATH;
	readObj();
};

OBJLoader::~OBJLoader(){};


void OBJLoader::getVertexPosition()
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

void OBJLoader::getTextureCoord()
{
		size_t uBegin= currentLine.find(' ');
		size_t uEnd = currentLine.find(' ', uBegin + 1);
		size_t vEnd = currentLine.find(' ', uEnd + 1);


		textureCoord tempCoord;

		tempCoord.uv_x= stof(currentLine.substr(uBegin + 1, uEnd + 1));
		tempCoord.uv_y= stof(currentLine.substr(uEnd + 1, vEnd));


		myObject.vTextureCoord.push_back(tempCoord);

};

void OBJLoader::getVertexNormal()
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

void OBJLoader::getIndices()
{
	size_t indexBegin		 = currentLine.find(' ');
	size_t indexEnd			 = currentLine.find('/');
	size_t textureCoord	  	 = currentLine.find('/', indexEnd + 1);
	size_t vertexNorm		 = currentLine.find(' ', textureCoord + 1);
	 
	Indices tempIndices;
	
	tempIndices.vertexIndex = stoi(currentLine.substr(indexBegin + 1, indexEnd));
	tempIndices.texIndex	= stoi(currentLine.substr(indexEnd + 1, textureCoord));
	tempIndices.normIndex	= stoi(currentLine.substr(textureCoord + 1, vertexNorm));

	myObject.vIndices.push_back(tempIndices);

	currentLine = currentLine.substr(vertexNorm, currentLine.length());

	 indexBegin			= currentLine.find(' ');
	 indexEnd			= currentLine.find('/');
	 textureCoord		= currentLine.find('/', indexEnd + 1);
	 vertexNorm			= currentLine.find(' ', textureCoord + 1);

	tempIndices.vertexIndex		= stoi(currentLine.substr(indexBegin + 1, indexEnd));
	tempIndices.texIndex	    = stoi(currentLine.substr(indexEnd + 1, textureCoord));
	tempIndices.normIndex		= stoi(currentLine.substr(textureCoord + 1, vertexNorm));

	myObject.vIndices.push_back(tempIndices);


	currentLine = currentLine.substr(vertexNorm, currentLine.length());

	indexBegin = currentLine.find(' ');
	indexEnd = currentLine.find('/');
	textureCoord = currentLine.find('/', indexEnd + 1);

	tempIndices.vertexIndex = stoi(currentLine.substr(indexBegin + 1, indexEnd));
	tempIndices.texIndex = stoi(currentLine.substr(indexEnd + 1, textureCoord));
	tempIndices.normIndex = stoi(currentLine.substr(textureCoord + 1, currentLine.length()));

	myObject.vIndices.push_back(tempIndices);




}

void OBJLoader::getMaterialKa()
{

	size_t Begin = currentLine.find(' ');
	size_t End = currentLine.find(' ', Begin + 1);
	myObject.m_Material.materialKa= stof(currentLine.substr(Begin + 1, End + 1));



}
void OBJLoader::getMaterialKs()
{

	size_t Begin = currentLine.find(' ');
	size_t End = currentLine.find(' ', Begin + 1);
	myObject.m_Material.materialKs = stof(currentLine.substr(Begin + 1, End + 1));



}


void OBJLoader::getMaterialKd()
{

	size_t Begin = currentLine.find(' ');
	size_t End = currentLine.find(' ', Begin + 1);
	myObject.m_Material.materialKd = stof(currentLine.substr(Begin + 1, End + 1));



}

void OBJLoader::getTextureAdress()
{
	size_t Begin = currentLine.find(' ');

	myObject.m_Material.textureAdress = currentLine.substr(Begin + 1, currentLine.length());

}


void OBJLoader::getMaterialInfo()
{
	string mtlName = currentLine.substr(currentLine.find(' ')+1, currentLine.length());

		reverse(m_sPATH.begin(), m_sPATH.end());

	string mtlPath = m_sPATH.substr(m_sPATH.find('\\'), m_sPATH.length());

		reverse(m_sPATH.begin(), m_sPATH.end());
		reverse(mtlPath.begin(), mtlPath.end());
	mtlPath += mtlName;

	ifstream fsMaterial(mtlPath);


	while (getline(fsMaterial, currentLine))
	{
		if (currentLine[0] == 'K' && currentLine[1] == 'a')
			getMaterialKa();					 
		if (currentLine[0] == 'K' && currentLine[1] == 's')
			getMaterialKs();					 
		if (currentLine[0] == 'K' && currentLine[1] == 'd')
			getMaterialKd();
		if (currentLine[0] == 'm' && currentLine[1] == 'a')
			getTextureAdress();

	}
	


}

void OBJLoader::readObj() {

	ifstream fsPATH(m_sPATH);


	if (!fsPATH.is_open())
	{
		cout << "Shit aint open" << endl;
	}
	
	while (getline(fsPATH, currentLine))
	{

		if (currentLine[0] == 'v' && currentLine[1] != 't' && currentLine[1] != 'n')
			getVertexPosition();

		if (currentLine[0] == 'v' && currentLine[1] == 't' && currentLine[1] != 'n')
			getTextureCoord();

		if (currentLine[0] == 'v' && currentLine[1] != 't' && currentLine[1] == 'n')
			getVertexNormal();

		if (currentLine[0] == 'f')
			getIndices();
		if (currentLine[0] == 'm'&&currentLine[1] == 't')
			getMaterialInfo();
		
	}

	

	cout << myObject.m_Material.materialKa << endl;
	cout << myObject.m_Material.materialKs << endl;
	cout << myObject.m_Material.materialKd << endl;
	cout << myObject.m_Material.textureAdress<< endl;



}

