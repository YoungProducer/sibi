#pragma once

#include <string>
#include "engine.h"

namespace Graphics
{
	class ShaderFactory
	{
	public:
		static GLuint compileShader(GLenum e_shaderType, std::string code);
		static GLuint createShader(std::string vertexCode, std::string fragmentCode);
	};
}
