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

	////Top
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-x, y, -z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, -z);

	glEnd();

	glEndList();

	return dp_list;

	
}