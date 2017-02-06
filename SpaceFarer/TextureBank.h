#pragma once
#include <string>
#include "SFML\Graphics\Texture.hpp"

#define GET_TEXTURE(aName) TextureBank::GetInstance()->GetTexture(aName)

struct TextureData
{
	std::string		myName;
	sf::Texture		myTexture;
};

class TextureBank
{
public:
	static	TextureBank*		GetInstance();
	
	void						Load();
	sf::Texture*				GetTexture(const std::string& aName);
	
private:
	TextureBank() = default;
	void						AddTexture(const std::string& aName, const std::string& aFilePath);


	static	TextureBank*		myInstancePtr;
	std::vector<TextureData>	myTextures;
	sf::Texture					myErrorTexture;
};

