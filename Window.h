#pragma once
#include <stdio.h>
#include <glew.h>
#include <glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);}
	bool* getsKeys() { return keys; }
	GLfloat getXChange();
	GLfloat getYChange();
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	GLfloat getrotay() { return rotay; }
	GLfloat getrotax() { return rotax; }
	GLfloat getrotaz() { return rotaz; }


	GLfloat getangulocabeza() { return anguloCabeza; }
	GLfloat getangulomandibula() { return anguloMandibula; }
	GLfloat getanguloPiernaDelanteDer() { return anguloPiernaDelanteDer; }
	GLfloat getanguloPiernaDelanteIzq() { return anguloPiernaDelanteIzq; }
	GLfloat getanguloPiernaAtrasDer() { return anguloPiernaAtrasDer; }
	GLfloat getanguloPiernaAtrasIzq() { return anguloPiernaAtrasIzq; }
	//Esto

	~Window();
private: 
	GLFWwindow *mainWindow;
	GLint width, height;

	//Cambiar nombre variables
	GLfloat rotax,rotay,rotaz, anguloCabeza, anguloMandibula, anguloPiernaDelanteDer, anguloPiernaDelanteIzq, anguloPiernaAtrasDer, anguloPiernaAtrasIzq;
	
	bool keys[1024];
	GLint bufferWidth, bufferHeight;
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	bool mouseFirstMoved;
	void createCallbacks();
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
	static void ManejaMouse(GLFWwindow* window, double xPos, double yPos);
};

