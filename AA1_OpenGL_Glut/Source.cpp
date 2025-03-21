#include <GL/glut.h>
#include <math.h>

//Constantes
#define M_PI 3.141592f

//Variables
    //Cube
        float cubeY = 0.0f; 
        float cubeSpeed = 0.01f; 
    //Sphere
        float size = 1;
    //Piramide
        float base = 0.3;
        float heigth = 0.5;
        float slices = 4;
        float stacks = 4;
        float angle = 0;
    //Ball
        float angle_ball = 0;
        float radius_ball = 1;
        float vel_ball = 1;
        float rotation_ball = 0;

// Funci�n para inicializar la configuraci�n de OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Establece el color de fondo en negro
    glEnable(GL_DEPTH_TEST);  

}

void update(int value) {
    angle += 1.0f;  // Incrementa el �ngulo
    if (angle > 360.0f) angle -= 360.0f;

    cubeY += cubeSpeed;

    if (cubeY > 0.8f || cubeY < -0.3f) 
    {
        cubeSpeed = -cubeSpeed;
    }

    angle_ball += vel_ball;

    if (angle_ball >= 360.0f) 
    {
        angle_ball -= 360.0f;
    }

    rotation_ball += 1.0f;  
    if (rotation_ball > 360.0f) rotation_ball -= 360.0f;

    glutPostRedisplay();  
    glutTimerFunc(16, update, 0);  
}

void resetScene() {
    angle = 0;
    cubeY = 0;
    size = 1;
    angle_ball = 0;
    rotation_ball = 0;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '+':  // mueve el cubo hacia arriba
        size += 0.1f;
        break;
    case '-':  // mueve el cubo hacia abajo
        size -= 0.1f;
        break;
    case 'r':  // resetear la escena
        resetScene();
        break;
    default:
        break;
    }
    glutPostRedisplay();  // Actualiza la ventana
}

void drawObjects()
{
    // Dibuja el cubo
    glPushMatrix();  //Empezar a crear matriz
    glTranslatef(0.0f, cubeY, 0.0f);  // Mueve el cubo
    glTranslatef(-0.5f, 0.0f, 0.0f);  // Mueve el cubo
    glColor3f(1.0f, 0.0f, 0.0f);  // Establece el color 
    glutSolidCube(0.4f);  // Dibuja un cubo de tama�o x
    glPopMatrix();  //Cerrar matriz y restaurar

    // Dibuja la esfera
    glPushMatrix();  //Empezar a crear matriz
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(size, size, size);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidSphere(0.2f, 40, 40);
    glPopMatrix();  //Cerrar matriz y restaurar

    ////Piramide
    glPushMatrix();  //Empezar a crear matriz
    glTranslatef(0.5f, -0.2f, 0.0f);
    glRotatef(angle, 0, 1, 0);  // Rotar para q apunte hacia arriba
    glColor3f(0.0f, 1.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);  // Rotar para q apunte hacia arriba
    glutWireCone(base, heigth, slices, stacks);
    glPopMatrix();  //Cerrar matriz y restaurar

    // Dibujar la esfera en movimiento
    glPushMatrix();
    float x = radius_ball * cos(angle_ball * M_PI / 180.0f);
    float z = radius_ball * sin(angle_ball * M_PI / 180.0f);
    glTranslatef(x, 0.0f, z);  // Mover la esfera en un c�rculo
    glRotatef(rotation_ball, 0.0f, 0.0f, 1);
    glColor3f(1.0f, 1.0f, 0.0f);  // Azul
    glutWireSphere(0.1f, 20, 20);
    glPopMatrix();
}


// Funci�n para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Limpiar Buffer

    //Perspectiva
    glViewport(0, 0, 600, 1200);  // Mitad izquierda de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 10.0);  // Proyecci�n en perspectiva

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.5, 2.0,  
        0.0, 0.0, 0.0,  
        0.0, 1.0, 0.0); 

    drawObjects();  // Dibujar los objetos

    //Ortografica
    glViewport(600, 0, 600, 1200);  // Mitad derecha de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10, 10);  // Proyecci�n ortogr�fica

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.2, 0.0, 
        0.0, 0.0, 0.0,
        0.0, 0.0, -1.0);

    drawObjects();

    glFlush();  //Final
}

// Funci�n principal para inicializar y ejecutar el programa
int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 1200);  // Tama�o de la ventana
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Base");

    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);  
    glutTimerFunc(16, update, 0);  // Iniciar update

    glutMainLoop();  // Inicia el ciclo principal de GLUT
    return 0;
}