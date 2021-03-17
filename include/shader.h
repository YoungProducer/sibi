#pragma once

#include <string>
#include "engine.h"
#include "utils/create_shader.h"

struct ShaderPair {
	GLuint vertex;
	GLuint fragment;
};

class Shader {
public:
	Shader(std::string strName, std::string strVrtexPath, std::string strFragmentPath);
	ShaderPair create();

protected:
	std::string name;
	std::string vertexPath;
	std::string fragmentPath;
};