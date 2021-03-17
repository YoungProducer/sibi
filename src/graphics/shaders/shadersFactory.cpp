#include "graphics/shaders/shadersFactory.h"

namespace Graphics
{
	GLuint ShaderFactory::compileShader(GLenum e_shaderType, std::string code)
	{
		GLuint shader = glCreateShader(e_shaderType);
		const char* shaderPath = code.c_str();
		glShaderSource(shader, 1, &shaderPath, NULL);

		glCompileShader(shader);

		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		if (status == GL_FALSE)
		{
			GLint infoLogLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar* infoLog = new GLchar[static_cast<int64_t>(infoLogLength) + 1];
			glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);

			const char* shaderType = NULL;
			switch (e_shaderType)
			{
			case GL_VERTEX_SHADER: shaderType = "vertex"; break;
			case GL_GEOMETRY_SHADER: shaderType = "geometry"; break;
			case GL_FRAGMENT_SHADER: shaderType = "fragment"; break;
			}

			fprintf(stderr, "Compile failure in %s shader:\n%s\n", shaderType, infoLog);

			delete[] infoLog;
		}

		return shader;
	}

	GLuint ShaderFactory::createShader(std::string vertexCode, std::string fragmentCode)
	{
		GLuint program = glCreateProgram();

		GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexCode);
		GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);

		GLint status;
		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint infoLogLength;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar* strInfoLog = new GLchar[infoLogLength + 1];
			glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
			fprintf(stderr, "Linker failure: %s\n", strInfoLog);
			delete[] strInfoLog;
		}

		//glValidateProgram(program);

		glDetachShader(program, vertex);
		glDetachShader(program, fragment);

		return program;
	}
}