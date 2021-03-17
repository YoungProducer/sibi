#include <stdio.h>

#include "application/window.h"
#include "graphics/shaders/shader.h"
#include "graphics/shapes/triangle.h"

const float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, 0.75f, 0.0f, 1.0f
};

GLuint inidicies[] = {
	0, 1, 2,
	0, 2, 3
};

std::vector<GLfloat> vertex1{
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

std::vector<uint32_t> indices1{
	0, 1, 2,
};

std::vector<GLfloat> vertex2{
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, 0.75f, 0.0f, 1.0f
};

int main()
{
	Application::Window window = Application::Window("test program", 600, 600);
	Graphics::Shader customShader = Graphics::Shader("res/custom.vert", "res/custom.frag");
	Graphics::Triangle triangle1 = Graphics::Triangle(vertex1, indices1);
	Graphics::Triangle triangle2 = Graphics::Triangle(vertex2, indices1);

	std::vector<Graphics::Shape*> shapes;
	shapes.push_back(&triangle1);
	shapes.push_back(&triangle2);

	//GLuint VBO, VAO, EBO;
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);
	//glBindVertexArray(VAO);
	//
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inidicies), inidicies, GL_STATIC_DRAW);
	//
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	//glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	//
	//glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	while (!window.getIsClosed())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		window.clear();

		customShader.bind();
        //glBindVertexArray(VAO);

		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		for (int i = 0, length = shapes.size(); i < length; i++)
		{
			shapes[i]->render();
		}

		customShader.unbind();

		window.update();
	}

	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteBuffers(1, &EBO);

	glfwTerminate();

	return 0;
}
