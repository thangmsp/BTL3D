#include "Header.h"
#include "BasicCad.h"

#include "Texture.h"
#include "Car.h"
#pragma comment(lib, "legacy_stdio_definitions.lib")
#define PI 3.14159265359
#define  DIS_CAM_TO_MODE 10

GLuint obj;

Texture* t1;
Texture* t2;
Texture* t3;
Texture* t4;
Texture* t5;
Texture* t_ground;

Car* car;


char texture_name[100] = { "text01.bmp" }; // lưu trữ tên file texture
char texture_name_car1[100] = { "car4.bmp" };
char texture_name_car2[100] = { "car3.bmp" };
char texture_name_car3[100] = { "car1.bmp" };
char texture_name_car4[100] = { "car2.bmp" };
char texture_name_car5[100] = { "car5.bmp" };

float g_x = 5.0;
float g_z = 0.0;
float g_y = 5.0;




float g_x_origin = 0.0;
float g_angle = 0.0;

bool g_is_rotate = false;


float angle = 0.0;
float deltaAngle = 0.0f;
int xOrigin = -1;
float detal_moving = 0.0;
float angle_car = 0.0;



void MouseButton(int type, int state, int x, int y)
{
    if (type == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            g_is_rotate = true;
            deltaAngle = 0.0;
            xOrigin = x;
        }
        else
        {
            angle += deltaAngle;
            xOrigin = -1;
            g_is_rotate = false;
        }
    }
}

void MouseMove(int x, int y)
{
    if (g_is_rotate)
    {
        deltaAngle += (x - xOrigin) * 0.0005f;
        g_x = 10 * sin(angle + deltaAngle);
        g_z = 10 * cos(angle + deltaAngle);
    }
}


void OnKeyUp(unsigned char ch, int x, int y)
{
    switch (ch)
    {
    case 'w':
        g_x += 1.2;
        break;
    case 's':
        g_x -= 1.2;
        break;
    case 'a':
        g_y += 0.2;
        break;
    case 'd':
        g_y -= 0.2;
        break;

    default:
        break;
    }
}

void OnKeyDown(unsigned char ch, int x, int y)
{
    switch (ch)
    {
    case 'w':
        //detal_moving = 0.1;
        break;
    case 's':
        //detal_moving -= 0.1;
        break;
    case 'a':
        //angle_car -= 3;
        break;
    case 'd':
        //angle_car = 3;
        break;
    default:
        break;
    }
}
// phải chỉnh lại thêm 1 tí ms chính xác đc
void OnSpecialKeyDown(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        detal_moving = 0.003;
        //angle_car -= 3;
        break;
    case GLUT_KEY_DOWN:
        //angle_car += 3;
        detal_moving = -0.003;
        break;
    case GLUT_KEY_LEFT:
        //detal_moving = 0.01;
        angle_car -= 3;
        std::cout << angle_car << std::endl;
        break;
    case GLUT_KEY_RIGHT:
        //detal_moving = -0.01;
        angle_car += 3;
        //TocDo_X += 0.2;

        std::cout << angle_car << std::endl;
        break;
    case GLUT_KEY_PAGE_DOWN:
        g_z += 0.2;
        break;
    case GLUT_KEY_PAGE_UP:
        g_z -= 0.2;

        break;
    default:
        break;
    }
}

void OnSpecialKeyUp(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_UP:
    {
        detal_moving = 0;
        break;
    }
    case GLUT_KEY_DOWN:
    {
        detal_moving = 0;
        break;
    }
    case GLUT_KEY_LEFT:

        break;
    case GLUT_KEY_RIGHT:

        break;
    default:
        break;
    }
}
void ReShape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = width / height;
    gluPerspective(45.0, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

void Init()
{
    /*glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);*/

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    //veground();
    g_x = 10 * sin(angle);
    g_z = 10 * cos(angle);
    t_ground = new Texture(texture_name, GL_TEXTURE_2D);


    t1 = new Texture(texture_name_car1, GL_TEXTURE_2D);
    t2 = new Texture(texture_name_car2, GL_TEXTURE_2D);
    t3 = new Texture(texture_name_car3, GL_TEXTURE_2D);
    t4 = new Texture(texture_name_car4, GL_TEXTURE_2D);
    t5 = new Texture(texture_name_car5, GL_TEXTURE_2D);

    car = new Car(t1, t2, t3, t4, t5, 0.4, 0, 4, 1.3, 0.7, 1.5);


}
void RenderScene()
{
    if (detal_moving != 0.0 || angle_car != 0.0)
    {
        if (angle_car >= 360)
        {
            angle_car -= 360;
        }
        if (angle_car <= -360)
        {
            angle_car += 360;
        }
        car->CarMove(angle_car, detal_moving);

    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /*gluLookAt(g_x, g_y, g_z,
        20.0, 0.0, 0.0,
        0.0f, 1.0f, 0.0f);*/
    gluLookAt(g_x, g_y, g_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //gluLookAt(20.0, 30.0, -40.0, 20.0, 0.0, 0.0, 0.0, 1.0, 0.0);//mấy số trong này là gì thế
    /*

    15.0, 10.0, 60 : đây là tọa độ của camera ( x,e,z)

     10.0, 0.0, 0.0 : tọa độ của điểm mà camera nhìn vào
     0.0, 1.0, 0.0 : cái này t k biết

    */
    GLuint ground = BasicCad::MakeGround(5.5, 5.5, 0);
    //GLuint ground = BasicCad::MakeGround(GROUND_SIZE, GROUND_SIZE, 0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glEnable(GL_TEXTURE_2D);
    //face 1
    t_ground->Bin();
    glCallList(ground);
    t_ground->UnBin();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    car->CreateCar();
    car->Rotate(angle_car, 0.0, 1.0, 0.0);
    glFlush();
    glutPostRedisplay();
}
int main(int a, char** b)
{
    glutInit(&a, b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Opengl Study");

    Init();
    glutReshapeFunc(ReShape);
    glutDisplayFunc(RenderScene);

    glutIdleFunc(RenderScene);
    glutKeyboardFunc(OnKeyDown);
    //glutKeyboardUpFunc(OnKeyUp);
    glutSpecialFunc(OnSpecialKeyDown);
    glutSpecialUpFunc(OnSpecialKeyUp);

    glutMouseFunc(MouseButton);
    glutMotionFunc(MouseMove);

    glutMainLoop();
    return 0;
}