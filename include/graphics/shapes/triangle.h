#pragma once

#include <vector>
#include "shape.h"

namespace Graphics
{
	class Triangle : public Shape
	{
	public:
		Triangle(const std::vector<GLfloat>& vertices, const std::vector<uint32_t>& indices);
		~Triangle();

	public:
		void render() override;

	private:
		GLuint VBO;
		GLuint VAO;
		GLuint EBO;
	};
}