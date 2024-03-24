#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	rotax = 0.0f;
	rotay = 0.0f;
	rotaz = 0.0f;
	anguloCabeza = 0.0f;
	anguloMandibula = 0.0f;
	anguloPiernaDelanteDer = 0.0f;
	anguloPiernaDelanteIzq = 0.0f;
	anguloPiernaAtrasDer = 0.0f;
	anguloPiernaAtrasIzq = 0.0f;
	
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicializaci n de GLFW
	if (!glfwInit())
	{
		printf("Fall  inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Practica XX: Nombre de la pr ctica", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tama o de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall  inicializaci n de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas
							 
							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se est  usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
	return 0;
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}

GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	
	if (key == GLFW_KEY_E)
	{
		theWindow->rotax += 10.0;
	}
	if (key == GLFW_KEY_R)
	{
		theWindow->rotay += 10.0; //rotar sobre el eje y 10 grados
	}
	if (key == GLFW_KEY_T)
	{
		theWindow->rotaz += 10.0;
	}

	//Cambio
	if (key == GLFW_KEY_Z)
	{
		if (theWindow->anguloCabeza < 45.0)
			theWindow->anguloCabeza += 5.0;
	}
	if (key == GLFW_KEY_X)
	{
		if (theWindow->anguloCabeza > -45.0)
			theWindow->anguloCabeza -= 5.0;
	}



	if (key == GLFW_KEY_C)
	{
		if (theWindow->anguloMandibula < 45.0)
			theWindow->anguloMandibula += 5.0;
	}
	if (key == GLFW_KEY_V)
	{
		if (theWindow->anguloMandibula > -10.0)
			theWindow->anguloMandibula -= 5.0;
	}


	if (key == GLFW_KEY_J)
	{
		if (theWindow->anguloPiernaDelanteIzq < 45.0f)
			theWindow->anguloPiernaDelanteIzq += 5.0;
	}
	if (key == GLFW_KEY_H)
	{
		if (theWindow->anguloPiernaDelanteIzq > 0.0)
			theWindow->anguloPiernaDelanteIzq -= 5.0;
	}
	if (key == GLFW_KEY_G)
	{
		if (theWindow->anguloPiernaDelanteDer < 45.0)
			theWindow->anguloPiernaDelanteDer += 5.0;
	}
	if (key == GLFW_KEY_F)
	{
		if (theWindow->anguloPiernaDelanteDer > 0.0)
			theWindow->anguloPiernaDelanteDer -= 5.0;
	}

	if (key == GLFW_KEY_I)
	{
		if (theWindow->anguloPiernaAtrasIzq < 45.0)
			theWindow->anguloPiernaAtrasIzq += 5.0;

	}
	if (key == GLFW_KEY_O)
	{
		if (theWindow->anguloPiernaAtrasIzq > 0.0)
			theWindow->anguloPiernaAtrasIzq -= 5.0;

	}
	if (key == GLFW_KEY_L)
	{
		if (theWindow->anguloPiernaAtrasDer < 45.0)
			theWindow->anguloPiernaAtrasDer += 5.0;
	}
	if (key == GLFW_KEY_K)
	{
		if (theWindow->anguloPiernaAtrasDer > 0.0)
			theWindow->anguloPiernaAtrasDer -= 5.0;
	}


	//Cambiar hasta aqui	
	

	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		const char* key_name = glfwGetKeyName(GLFW_KEY_D, 0);
		//printf("se presiono la tecla: %s\n",key_name);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}
}

void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}


Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
