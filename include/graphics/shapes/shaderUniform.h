#pragma once

namespace Graphics
{
	class Shader;

	class ShaderUniform
	{
	public:
		static void setUniform1f(Shader* shader, const char* name, float value);
		static void setUniform2f(Shader* shader, const char* name);
	};
}
