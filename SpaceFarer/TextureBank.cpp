#include "TextureBank.h"
#include <iostream>

TextureBank* TextureBank::myInstancePtr = nullptr;

TextureBank * TextureBank::GetInstance()
{
	if (!myInstancePtr)
	{
		myInstancePtr = new TextureBank();
	}
	return myInstancePtr;
}

void TextureBank::Load()
{
	myErrorTexture.loadFromFile("sprites/Trash/error.png");

	AddTexture("player", "player.png");
	AddTexture("cursor", "cursor.png");
	AddTexture("frame", "frame.png");
	AddTexture("guiBar", "GuiBar.png");
	AddTexture("smallStar", "smallStar.png");
	AddTexture("alienGreen", "Trash/alien.png");
	AddTexture("alienBlue", "Trash/alienBlue.png");
	AddTexture("asteroid", "Trash/asteroid.png");
	AddTexture("shot", "Trash/shot.png");
	AddTexture("star", "Trash/Star.png");
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
