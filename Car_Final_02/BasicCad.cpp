#include"BasicCad.h"
#include"texture.h"
#define P_PI 3.14159265359

GLuint BasicCad::MakeGround(const float& length, const float& width, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;

	//front
	//glBegin(GL_QUADS);
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, z);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(0, y, z);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0, z);
	//glEnd();

	////Back
	//glBegin(GL_QUADS);
	//glNormal3f(0.0f, 0.0f, -1.0f);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 0, 0);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, 0);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(0, y, 0);
	//glEnd();

	//// left
	//glBegin(GL_QUADS);
	//glNormal3f(-1.0f, 0.0f, 0.0f);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, z);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(0, y, z);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(0, y, 0);
	//glEnd();

	//// right
	//glBegin(GL_QUADS);
	//glNormal3f(1.0f, 0.0f, 0.0f);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 0, z);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0, 0);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, 0);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z);
	//glEnd();

	//Top

	glBegin(GL_QUADS);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-x, 0, -z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, 0, -z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0, z);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(-x, 0, z);


	glEnd();

	glEndList();

	return dp_list;
}