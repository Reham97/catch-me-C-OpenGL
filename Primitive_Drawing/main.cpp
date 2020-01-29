#include <iostream>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "Renderer.h"
#define GLEW_STATIC
const GLint Wi = 1024, Hi = 768;
GLuint keypressed;
double mouseXpos;
double mouseYpos;
bool InitGraphics();
void SpecialKeyPressed(GLFWwindow*, int, int, int, int);
void MouseClicked(GLFWwindow*, int, int, int);



int main( void )
{
	InitGraphics();
	return 0;
}

/** 
Creates the main window and initializes OpenGL stuff.
*/
bool InitGraphics()
{
	Renderer *renderer = new Renderer(); //All drawing code goes here
	GLFWwindow* window;
	
	// ******************** Initialise GLFW ******************** //
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //If requesting an OpenGL version below 3.2, GLFW_OPENGL_ANY_PROFILE

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( Wi, Hi, "Red triangle", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, &SpecialKeyPressed);
	glfwSetMouseButtonCallback(window, &MouseClicked);

	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); 

	

	// ******************** Initialize OpenGL ******************** //
	renderer->Initialize();

	do{ // Loop

		if (keypressed != -1)
		{
			renderer->HandleKeyboardInput(keypressed);
			keypressed = -1;
		}


		if (mouseXpos != -1 &&mouseYpos!=-1)
		{
			renderer->HandleMouseclick(mouseXpos, mouseYpos);
			mouseXpos = mouseYpos - 1;
		}

	
		
		if (renderer->Game() == true)
		{
			return false;
		}
			renderer->Draw();
			renderer->update();


			// Swap buffers
			glfwSwapBuffers(window); //Displaying our finished scene
			glfwPollEvents(); //try to comment it
		

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
    // Deleting renderer object will deallocate it's memory and call it's destructor (which calls the renderer's Cleanup method)
    delete renderer;
    return true;

}

void SpecialKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		keypressed = key;
	}


}


void MouseClicked(GLFWwindow* window, int buttin, int action, int mods)
{
	if (action == GLFW_MOUSE_BUTTON_LEFT)
	{
		glfwGetCursorPos(window, &mouseXpos, &mouseYpos);
	}
}