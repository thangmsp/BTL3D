#include"Car.h"

Car::Car(Texture* t_car1, Texture* t_car2, Texture* t_car3, Texture* t_car4, Texture* t_car5, float x, float y, float z, float w, float l, float h)
{
	this->texture1 = t_car1;
	this->texture2 = t_car2;
	this->texture3 = t_car3;
	this->texture4 = t_car4;
	this->texture5 = t_car5;

	this->angle_ = 0.0;
	this->rotate_x = 0.0;
	this->rotate_y = 0.0;
	this->rotate_z = 0.0;

	rect_.x = x;
	rect_.y = y;
	rect_.z = z;


	car3 = MakeCar3(l, w, h);
	car4 = MakeCar4(l, w, h);
	car2 = MakeCar2(l, w, h);
	car1 = MakeCar1(l, w, h);
	car5 = MakeCar5(l, w, h);
}
void Car::CarMove(float angle, float detal_moving)
{
	angle = (angle * P_PI) / 180;
	this->rect_.x += detal_moving * sin(angle);
	this->rect_.z += detal_moving * -cos(angle);
}
void Car::Rotate(float angle, float x, float y, float z)
{
	this->angle_ = angle;
	this->rotate_x = x;
	this->rotate_y = y;
	this->rotate_z = z;
}
void Car::CreateCar()
{
	glPushMatrix();

	glTranslatef(rect_.x, rect_.y, rect_.z); // ở đây, nó xác định vị trí trước sau đó nó mới quay, nên là vị trí xuất hiện của nó ở đâu nó q ở đấy
	glRotatef(angle_, rotate_x, -rotate_y, rotate_z);// nhưng nếu m cho nó quay trước thì nó chỉ quay quanh tọa tộ gốc 0,0,0,

	glEnable(GL_TEXTURE_2D);


	//face 1
	texture1->Bin();
	glCallList(car1);
	texture1->UnBin();

	//face 2
	texture2->Bin();
	glCallList(car2);
	texture2->UnBin();

	//face 3
	texture3->Bin();
	glCallList(car3);
	texture3->UnBin();

	//face 4
	texture4->Bin();
	glCallList(car4);
	texture4->UnBin();
	
	//face 5
	texture5->Bin();
	glCallList(car5);
	texture5->UnBin();

	glDisable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
}
GLuint Car::MakeCar1(const float length, const float width, const float height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;
	//front
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x, 0, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0, z);


	glEnd();

	glEndList();

	return dp_list;
}

GLuint Car::MakeCar2(const float length, const float width, const float height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;

	////Back
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f);  glVertex3f(x, 0, -z);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(-x, 0, -z);
	glTexCoord2f(0.0f, 1.0f);  glVertex3f(-x, y, -z);
	glTexCoord2f(1.0f, 1.0f);  glVertex3f(x, y, -z);

	glEnd();

	glEndList();

	return dp_list;
}
GLuint Car::MakeCar3(const float length, const float width, const float height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;


	//// left
	glBegin(GL_QUADS);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x, 0, -z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-x, 0, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-x, y, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-x, y, -z);


	glEnd();

	glEndList();

	return dp_list;
}
GLuint Car::MakeCar4(const float length, const float width, const float height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;


	//// right
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 0, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0, -z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, -z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z);
	glEnd();


	glEndList();

	return dp_list;
}
GLuint Car::MakeCar5(const float length, const float width, const float height)
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
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y, -z);


	glEnd();

	glEndList();

	return dp_list;
}