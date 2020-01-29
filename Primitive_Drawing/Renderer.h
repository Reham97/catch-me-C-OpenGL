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
#include "snake.h"
#include<Windows.h>
#pragma once

class Renderer
{
	bool gameover;
	const int width = 20;
	const int hight = 20;
	float fruitX, fruitY, score;
	int tailX[100], tailY[100];
	int nTail;
	mat4 ModelMatrix[100];
	mat4 updatetranslate;
	int W;
	int clock;
	double time;
	double x, y;
	double x2, y2;
	GLuint VBO, VAO, VBO2, VAO2, VBO3, VAO3;
	GLuint programID;
	GLuint MatrixID;
	mat4 ModelMatrix1, ModelMatrix2, ModelMatrix3;
	mat4 ViewMatrix;
	mat4 ProjectionMatrix;
	mat4 scaleMat1, translateMat1, scaleMat2, translateMat2, scaleMat3, translateMat3;
	GLuint mvpMatrixID;
	mat4 MVP_matrix;

public:
	Renderer();
	~Renderer();

	void Initialize();
	void Draw();
	void update();
	void Cleanup();
	bool Game();
	void checkfood();

	void HandleKeyboardInput(int);
	void HandleMouseclick(double, double);
	void HandleMouseMove(double, double);


};
