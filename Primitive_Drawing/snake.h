#include<iostream>
#include <gl/glew.h>
#include<gl/glfw3.h>

// translation
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
using namespace glm;
#include "shader.hpp"
#pragma once
class snake
{
	
public:
	GLuint programID;
	float x;
	float y;
	GLuint VBO, VAO;
	mat4 ModelMatrix;
	mat4 scaleMat;
	mat4 translateMat;
	GLuint mvpMatrixID;
	mat4 MVP_matrix;

	snake();
	~snake();
//	void initial(static const GLfloat vertices[]);
	//void draw();
	//mat4 transformation();

};

