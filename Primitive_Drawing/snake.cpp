#include "snake.h"


snake::snake()
{
}


snake::~snake()
{
}

/*
void snake::initial(static const GLfloat vertices[])
{
	x = 0.0f;
	y = 0.0f;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	

}
mat4 snake::transformation()
{
	scaleMat = scale(0.1f, 0.1f, 0.0f);
	translateMat = glm::translate(x, y, 0.0f);
	ModelMatrix = translateMat * scaleMat; //Scale is applied first
	return ModelMatrix;
}
void snake::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	

}*/