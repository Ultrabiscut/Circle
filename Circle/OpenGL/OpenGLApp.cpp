#include<Windows.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include <cmath>
#include <math.h>
#include "OpenGLApp.h"


OpenGLApp::OpenGLApp()
{
}


OpenGLApp::~OpenGLApp()
{
}


bool OpenGLApp::Initialize()	//initialize your opengl scene
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return true;
}	
bool OpenGLApp::Shutdown()	//shut down your scene
{
	return true;
}

//used to setup your opengl camera and drawing area
void OpenGLApp::SetupProjection(int width, int height){
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// you need 3 things to create a frustum
	// 1. Field of view (52.0f here)
	// 2. aspect ratio of screen (width/height of window)
	// 3. near and far plane (1, and 1000)
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_windowWidth = width;
	m_windowHeight = height;
}

void OpenGLApp::Prepare(float dt)
{

}
void OpenGLApp::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -10.0f);

	glColor3f(0.5f, 0.0f, 1.0f);

	glBegin(GL_LINE_LOOP);
		float x;
		float y;
	
		for (int angle = 0; angle < 360; angle++)
		{
			x = 3.0 * cos(angle);
			y = 3.0 * sin(angle);

			glVertex3f(x, y, 0.0f);
		}
	glEnd();


	//make this funciton call if you want to see the grid
	DrawGrid();
}

void OpenGLApp::DrawGrid()
{
	//increase the size of drawn points
	glPointSize(5.0f);

	glBegin(GL_LINES);
	//change the color to blue
	glColor3f(1.0f, 1.0, 1.0f);

	//vertical
	for (float x = 8; x >= -8; x--)
	{
		glVertex3f(x, 5.0f, 0.0f);
		glVertex3f(x, -5.0f, 0.0f);
	}
	//horizontal
	for (float y = 5; y >= -5; y--)
	{
		glVertex3f(8.0f, y, 0.0f);
		glVertex3f(-8.0f, y, 0.0f);
	}

	glEnd();
	
	//we are going to draw below
	glBegin(GL_POINTS);

		//change color to white
		glColor3f(0.0f, 0.0f, 1.0f);

		//draw the points on the y-axis
		for (float y = 5; y >= -5; y--)
		{
			glVertex3f(0.0f, y, 0.0f);
		}

		//draw the points on the x-axis
		for (float x = 8; x >= -8; x--)
		{
			glVertex3f(x, 0.0, 0.0f);
		}

		//set the color to red
		glColor3f(1.0f, 0.0f, 0.0f);
		//draw the orgin
		glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

}
