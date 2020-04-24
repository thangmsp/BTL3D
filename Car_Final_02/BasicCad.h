#pragma once
#include<gl/glut.h>
#include"texture.h"
#define P_PI 3.14159265359
class BasicCad
{
public:
    BasicCad(void);
    ~BasicCad(void);
    static GLuint MakeGround(const float& length, const float& width, const float& height);
    void MakeGround(Texture* texture, float x, float y, float z, float w, float l, float h);
 
};