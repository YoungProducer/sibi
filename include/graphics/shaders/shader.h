#pragma once

#include <string>
#include "engine.h"
#include "shadersFactory.h"
#include "utils/file.h"

namespace Graphics
{
	class Shader
	{
	public:
		Shader(std::string vertexPath, std::string fragmentPath);
		~Shader();

	public:
		void bind();
		void unbind();

	private:
		std::string vertexPath;
		std::string fragmentPath;
		std::string vertexCode;
		std::string fragmentCode;

		GLuint shaderId;
	};
}