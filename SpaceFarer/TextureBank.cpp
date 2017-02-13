#include "TextureBank.h"
#include <iostream>
#include <fstream>
#include "Engine\json.hpp"


TextureBank& TextureBank::GetInstance()
{
	static TextureBank instance;
	return instance;
}


sf::Texture * TextureBank::GetTexture(const std::string & aName)
{
	for (unsigned i = 0; i < myTextures.size(); ++i)
	{
		if (myTextures[i].myName == aName)
		{
			return &myTextures[i].myTexture;
		}
	}
	std::cout << "Could not find a texture with the name " << aName << "." << std::endl;
	return &myErrorTexture;
}

TextureBank::TextureBank()
{
	myErrorTexture.loadFromFile("sprites/Trash/error.png");
}

void TextureBank::AddTexture(const std::string & aName, const std::string & aFilePath)
{
	TextureData tempTD;
	tempTD.myName = aName;
	if (!tempTD.myTexture.loadFromFile("sprites/"+aFilePath))
	{
		std::cout << "Failed loading of file: " << aName << " Path: " << aFilePath << std::endl;
		return;
	}
	else
	{
		myTextures.push_back(tempTD);
	}
}

void TextureBank::LoadTextures(const std::string & aFilePath)
{
	std::ifstream inStream(aFilePath);

	jsonWrapper::json jsonElement;

	jsonElement << inStream;
	
	for (auto it = jsonElement.begin(); it != jsonElement.end(); ++it)
	{
		std::string name = *it;
		int cutOff = name.find_first_of('-');
		std::string path = name.substr(cutOff + 1);
		name = name.substr(0, cutOff);
		AddTexture(name, path);
	}
}
