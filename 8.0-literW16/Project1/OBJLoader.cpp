#include "OBJLoader.h"



OBJLoader::OBJLoader(string PATH) {
	m_sPATH = PATH;
};

OBJLoader::~OBJLoader(){

};

void OBJLoader::OpenObj()
{
	string line;

	//ifstream fsPATH(m_sPATH, std::ios::binary);

	ifstream fisier(m_sPATH, std::ios::binary);
	fisier.rdbuf();

	//if (!fsPATH.is_open()) {
	//	std::cerr << "Failed to open file: " << m_sPATH << std::endl;
	//}


	cout << "am ajuns aici";

	while (getline(fisier, line)) {
		
		std::cout << line << std::endl;
	}

};


