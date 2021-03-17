#include "graphics/shaders/shader.h"

namespace Graphics
{
	Shader::Shader(std::string vertexPath, std::string fragmentPath)
		: vertexPath(vertexPath),
		fragmentPath(fragmentPath)
	{
		vertexCode = FileSystem::readFile(vertexPath);
		fragmentCode = FileSystem::readFile(fragmentPath);

		shaderId = ShaderFactory::createShader(vertexCode, fragmentCode);
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderId);
	}

	void Shader::bind()
	{
		glUseProgram(shaderId);
	}

	void Shader::unbind()
	{
		glUseProgram(0);
	}
}