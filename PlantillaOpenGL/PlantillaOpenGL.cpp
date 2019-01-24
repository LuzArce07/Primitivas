// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarTriangulos() {

	//Rutina de Dibujo
	glBegin(GL_TRIANGLES);

	//--------X, Y, Z---------------------------------
	glColor3f(1, 0, 0);

	glVertex3f(0, 1, 0); //Vertice de arriba
	glVertex3f(-1, -1, 0); //vertice izquierda
	glVertex3f(1, -1, 0); //vertice derecha

	//Cuadrado morado
	//Colores con .0f
	//138, 43, 226

	glColor3f(0.5, 0.3, 1);

	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0);

	glColor3f(0.5, 0.3, 1);

	glVertex3f(0.5, 0.5, 0);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);

	glEnd();

}

void dibujarPuntos() {

	glBegin(GL_POINTS);

	//punto 1
	glColor3f(1, 1, 1);

	glVertex3f(0.5f, 0.1f, 0.0f);

	//punto 2
	glColor3f(0, 0, 0);

	glVertex3f(0.55f, 0.1f, 0.0f);

	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);
	
	glColor3f(1, 1, 1);

	glVertex3f(0, 0, 0);
	glColor3f(0, 0, 0); //interpolacion de colores en los vertices
	glVertex3f(0, 0.4, 0);

	glVertex3f(0.2, 0.5, 0);
	glVertex3f(-0.2, 0.5, 0);

	glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(0, 0, 0);

	glVertex3f(0, 0, 0);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0.3, -0.2, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0, 0, 0);

	glEnd();

}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	
	glColor3f(1, 1, 1);

	glVertex3f(0, 0, 0);
	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, -0.2, 0);

	glColor3f(0, 0, 0);
	glVertex3f(0.2, -0.4, 0);

	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.4, -0.4, 0);


	glEnd();

}

void dibujar() { 

	//dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	//dibujarLineaContinua();
	dibujarTrianguloContinuo();
}

void actualizar() {

}

int main()
{

	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//Si no se pudo iniciar glfw
	//terminamos ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW
	//Entonces inicializamos la ventana
	window = glfwCreateWindow(1024,768,"Ventana",NULL,NULL);

	//Si no podemos iniciar la ventana 
	//Entonces terminamos ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, activamos funciones modernas
	//Esto solo va a funcionar si ya establecido el contexto
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {

		cout << glewGetErrorString(errorGlew);

	}

	//Variable para la version de OPENGL
	const GLubyte *versionGL = glGetString(GL_VERSION);
	//Imprimir la variable
	cout << "Versión OPENGL: " << versionGL; //Salida de C++

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establece region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(0.2, 0.2, 1, 1);
		
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

