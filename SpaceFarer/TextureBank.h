#pragma once
#include <string>
#include "SFML\Graphics\Texture.hpp"

#define GET_TEXTURE(aName) TextureBank::GetInstance().GetTexture(aName)

struct TextureData
{
	std::string		myName;
	sf::Texture		myTexture;
};

class TextureBank
{
public:
	static	TextureBank&		GetInstance();

	sf::Texture*				GetTexture(const std::string& aName);
	
private:
	TextureBank();
	void						AddTexture(const std::string& aName, const std::string& aFilePath);

	std::vector<TextureData>	myTextures;
	sf::Texture					myErrorTexture;
};

