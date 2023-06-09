#ifndef TEXTURE_H
#define TEXTURE_H

#include<string>
#include<unordered_map>

#include "glad/glad.h"
#include "stb_image/stb_image.h"

#include <assimp/scene.h>

class Texture;


class Texture
{
private:
	unsigned int texture_id;
	std::string texture_path;
	unsigned char* texture_data;
	int width, height, channels;
	aiTextureType texture_type;
	
public:
	Texture() { /* Nothing */ }

	Texture(const std::string& path, aiTextureType type);

	~Texture();

	inline void bind(unsigned int textureUnit = 0) const
	{
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glBindTexture(GL_TEXTURE_2D, texture_id);
	}

	inline void unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	inline aiTextureType getType() const
	{
		return texture_type;
	}
};

#endif