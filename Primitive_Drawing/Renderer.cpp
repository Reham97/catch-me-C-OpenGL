
#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	Cleanup();
}

bool Renderer::Game()
{
	return gameover;
}
void Renderer::HandleKeyboardInput(int key)
{
	mat4 model2;

	switch (key)
	{
	case GLFW_KEY_UP:
		y = y + 0.1f;
		x2 = 0.0;
		y2 = 0.1;
		updatetranslate = translate(0.0f, 0.1f, 0.0f);
		ModelMatrix[0] = updatetranslate*ModelMatrix[0];
		printf("%f      %f      %f \n", x, y, score);
		break;

	case GLFW_KEY_DOWN:
		y = y - 0.1f;
		x2 = 0.0;
		y2 = -0.1;
		updatetranslate = translate(0.0f, -0.1f, 0.0f);
		ModelMatrix[0] = updatetranslate*ModelMatrix[0];
		printf("%f      %f      %f \n", x, y, score);
		break;

	case GLFW_KEY_RIGHT:
		x = x + 0.1f;
		x2 = 0.1;
		y2 = 0.0;
		updatetranslate = translate(0.1f, 0.0f, 0.0f);
		ModelMatrix[0] = updatetranslate*ModelMatrix[0];
		printf("%f      %f      %f \n", x, y, score);
		break;

	case GLFW_KEY_LEFT:
		x = x - 0.1f;
		x2 = -0.1;
		y2 = 0.0;
		updatetranslate = translate(-0.1f, 0.0f, 0.0f);
		ModelMatrix[0] = updatetranslate*ModelMatrix[0];
		printf("%f      %f      %f \n", x, y, score);
		break;
	}


	
	/*

	int prevX = tailX[0];
	int prevY = tailY[0];
	mat4 model = ModelMatrix[0];

	int prev2X, prev2Y;
	mat4 modell;

	tailX[0] = x;
	tailY[0] = y;
	ModelMatrix[0] = model2;
	for (int i = 1; i < nTail; i++)
	{
	prev2X = tailX[i];
	prev2Y = tailY[i];
	modell = ModelMatrix[i];
	tailX[i] = prevX;
	tailY[i] = prevY;
	ModelMatrix[i] = model;
	prevX = prev2X;
	prevY = prev2Y;
	model = modell;
	}
	/*if (x >= W || x <= 0 || y >= W || y <= 0)
	{
	gameover = true;
	}

	for (int i = 0; i < nTail; i++)
	{
	if (tailX[i] == x && tailY[i] == y)
	gameover = true;
	}
	*/

	checkfood();
}

void Renderer::checkfood()
{
	int xx, yy;
	xx = x / fruitX;;
	yy = y / fruitY;
	float a, b;
	a = x, b = y;
	if ((a == fruitX) && (b == fruitY))
	{
		float OLDX, OLDY;
		OLDX = fruitX;
		OLDY = fruitY;
		score = score + 10.0f;
		fruitX = 20.0f;
		fruitY = 20.0f;
		while (fruitX >= 4.0f || fruitY >= 4.0f || fruitX <= 0.0f || fruitY <= 0.0f)
		{
			fruitX = rand() % width;
			fruitY = rand() % width;
		}
		//nTail++;
		printf("%f      %f      %f \n", fruitX, fruitY, score);
		ModelMatrix3 = translate(-OLDX, -OLDY, 0.0f)*ModelMatrix3;
		ModelMatrix3 = translate(fruitX, fruitY, 0.0f)*ModelMatrix3;

	}
}
void Renderer::HandleMouseclick(double x_axis, double y_axis)
{
	//printf("%f,%f \n", x_axis, y_axis);
}

void Renderer::update()
{

}


void Renderer::Initialize()
{
	clock = 0;
	x2 = 0.0;
	y2 = 0.0;
	W = 4;
	nTail = 1;
	gameover = false;

	fruitX = (rand() % W);
	fruitY = (rand() % W);
	printf("%f      %f \n", fruitX, fruitY);

	score = 0;

	x = 2.0f;
	y = 2.0f;

	time = glfwGetTime();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(0.0f, 0.4f, 0.4f, 1.0f);
	//snake
	static const GLfloat vertices[] =
	{
		-0.1f, 0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.1f, 0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.1f, -0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,


		-0.1f, -0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,

		-0.1f, 0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.1f, -0.1f, 0.0f,
		1.0f, 1.0f, 1.0f,
	};
	//morb3
	static const GLfloat vertices2[] =
	{
		0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,

		1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f, 1.0f,

		0.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,

		0.0f, 0.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f, 1.0f,
	};
	//fruit
	static const GLfloat vertices3[] =
	{
		-0.1f, 0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

		0.1f, 0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

		0.1f, -0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

		-0.1f, -0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

		-0.1f, 0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

		0.1f, -0.1f, 0.0f,
		0.6f, 0.6f, 0.6f,

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO3);
	glGenBuffers(1, &VBO3);
	glBindVertexArray(VAO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);



	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	//MatrixID = glGetUniformLocation(programID, "ModelMatrix");
	mvpMatrixID = glGetUniformLocation(programID, "MVP");
	ViewMatrix = glm::lookAt(glm::vec3(2, 2, 10), glm::vec3(2.0, 2.0, 0), glm::vec3(0, 1, 0));
	ProjectionMatrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f);

	scaleMat1 = scale(0.5f, 0.5f, 0.0f);
	scaleMat2 = scale(4.0f, 4.0f, 0.0f);
	scaleMat3 = scale(0.5f, 0.5f, 0.0f);
	translateMat1 = glm::translate(2.0f, 2.0f, 0.0f);

	ModelMatrix[0] = translateMat1 *scaleMat1; //Scale is applied first

	ModelMatrix2 = scaleMat2; //Scale is applied first

	translateMat3 = glm::translate(fruitX, fruitY, 0.0f);
	ModelMatrix3 = translateMat3*scaleMat3;

	glUseProgram(programID);
}

void Renderer::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < nTail; i++)
	{
		glBindBuffer(GL_ARRAY_BUFFER, VAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		MVP_matrix = ProjectionMatrix*ViewMatrix*ModelMatrix[i];
		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_matrix[0][0]);
		glDrawArrays(GL_TRIANGLES, 0, 6);

	}


	glBindBuffer(GL_ARRAY_BUFFER, VAO2);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	MVP_matrix = ProjectionMatrix*ViewMatrix*ModelMatrix2;
	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_matrix[0][0]);
	glDrawArrays(GL_LINES, 0, 8);


	glBindBuffer(GL_ARRAY_BUFFER, VAO3);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	MVP_matrix = ProjectionMatrix*ViewMatrix*ModelMatrix3;
	glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, &MVP_matrix[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);







	glDisableVertexAttribArray(0);
}

void Renderer::Cleanup()
{
	glDeleteVertexArrays(1, &VAO); //the one we didn't used (will be discussed later)
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(programID);
}