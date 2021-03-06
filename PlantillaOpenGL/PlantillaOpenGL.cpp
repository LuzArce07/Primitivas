// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include <math.h>

using namespace std;

void dibujarTriangulos() { 

	//Rutina de Dibujo
	glBegin(GL_TRIANGLES); //necesita 3 vertices como minimo

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
	glBegin(GL_TRIANGLE_STRIP); //Necesita de tres vertices y si añades un 4to, se grafica apartir de los vertices mas proximos
	
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

void dibujarPoligono() {
	glBegin(GL_POLYGON); //necesita 3 vertices como minimo 

	glColor3f(1, 1, 1);

	glVertex3f(-0.8, 0.7, 0);
	glColor3f(0, 0, 0);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(0.5, 0.9, 0);
	glVertex3f(0, 0.5, 0); 
	glVertex3f(0.2, 0.8, 0);
	glVertex3f(0.5, 0.9, 0); 
	
	glEnd();

}

void techo() {
	glBegin(GL_TRIANGLES);

	glColor3f(0, 0, 0);

	glVertex3f(0.2, -0.4, 0);
	glVertex3f(0.7, -0.4, 0);
	glVertex3f(0.45, -0.1, 0);

	glEnd();
}

void dibujarCasita() { //con puerta y 2 ventanas
	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);
	
	glVertex3f(0.2, -0.8, 0);
	glVertex3f(0.2, -0.4, 0);
	glVertex3f(0.7, -0.4, 0);
	glVertex3f(0.7, -0.8, 0);

	glEnd();
}

void puerta() {
	glBegin(GL_QUADS);

	glColor3f(1, 0.3, 1);

	glVertex3f(0.4, -0.8, 0);
	glVertex3f(0.4, -0.65, 0);
	glVertex3f(0.5, -0.65, 0);
	glVertex3f(0.5, -0.8, 0);

	glEnd();
}

void ventanas() {
	glBegin(GL_QUADS);

	glColor3f(0, 0, 0);

	//ventana
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.5, -0.6, 0);
	glVertex3f(0.6, -0.6, 0);
	glVertex3f(0.6, -0.5, 0);

	//otra ventana
	glVertex3f(0.3, -0.5, 0);
	glVertex3f(0.3, -0.6, 0);
	glVertex3f(0.4, -0.6, 0);
	glVertex3f(0.4, -0.5, 0);



	glEnd();
}

void dibujarArbol() { 
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.8, 0);

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.5, 0.1 * sin((double)i * 3.14159 / 180.0) + 0, 0);
	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.6, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.1, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.5, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.1, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.4, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.1, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.5, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.2, 0);
	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.6, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.3, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.5, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.3, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.4, 0.1 * sin((double)i * 3.14159 / 180.0) + -0.3, 0);

	}
	

	glEnd();
}


void tronco() {
	glBegin(GL_QUADS);

	glColor3f(0.5, 0.2, 0);

	glVertex3f(-0.6, -0.8, 0);
	glVertex3f(-0.6, -0.39, 0);
	glVertex3f(-0.4, -0.39, 0);
	glVertex3f(-0.4, -0.8, 0);

	glEnd();
}

void dibujarSol() {
	glBegin(GL_POLYGON);
	glColor3f(1, 0.8, 0);

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2 * cos((double)i * 3.14159 / 180.0) + -0.7, 0.2 * sin((double)i * 3.14159 / 180.0) + 0.6, 0);
	}

	glEnd();
}

void dibujarNubes() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + 0.7, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);
		
	}
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + 0.6, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}
	
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + 0.5, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + 0.4, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}

	

	glEnd();
}

void dibujarNubes2() {
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + 0, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.1, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}

	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1 * cos((double)i * 3.14159 / 180.0) + -0.2, 0.1 * sin((double)i * 3.14159 / 180.0) + 0.7, 0);

	}

	glEnd();
}

void pasto() {
	glBegin(GL_QUADS);

	glColor3f(0.4, 0.8, 0);

	glVertex3f(-1, -1, 0);
	glVertex3f(-1, -0.8, 0);
	glVertex3f(1, -0.8, 0);
	glVertex3f(1, -1, 0);

	glEnd();
}

void dibujar() { 
	
	/*dibujarTriangulos();
	dibujarPuntos();
	dibujarLineas();
	dibujarLineaContinua();
	dibujarTrianguloContinuo();
	dibujarPoligono();*/
	dibujarSol();
	dibujarNubes();
	dibujarNubes2();
	techo();
	dibujarCasita();
	ventanas();
	puerta();
	dibujarArbol();
	tronco();
	pasto();
	

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
		glClearColor(0.2, 0.8, 1, 1);
		
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

