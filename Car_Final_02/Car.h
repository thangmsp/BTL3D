#pragma once
#include "Header.h"
#include "Texture.h"
#include "BasicCad.h"
class Car
{
private:
    Texture* texture1;
    Texture* texture2;
    Texture* texture3;
    Texture* texture4;
    Texture* texture5;
    Rect rect_;
    float angle_, rotate_x, rotate_y, rotate_z;
    GLuint car1, car2, car3, car4, car5;
public:
    Car(Texture* t_car1, Texture* t_car2, Texture* t_car3, Texture* t_car4, Texture* t_car5, float x, float y, float z, float w, float l, float h);
    ~Car();
    static GLuint MakeCar1(const float length, const float width, const float height);
    static GLuint MakeCar2(const float length, const float width, const float height);
    static GLuint MakeCar3(const float length, const float width, const float height);
    static GLuint MakeCar4(const float length, const float width, const float height);
    static GLuint MakeCar5(const float length, const float width, const float height);

    void setRect(float x, float y, float z)
    {
        this->rect_.x = x;
        this->rect_.y = y;
        this->rect_.z = z;
    }
    Rect getRect()
    {
        return rect_;
    }
    void Rotate(float angle, float x, float y, float z);
    void CreateCar();

    void CarMove(float angle, float delta_moving);
};