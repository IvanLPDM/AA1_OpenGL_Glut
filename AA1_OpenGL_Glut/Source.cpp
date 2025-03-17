#include <GL/glut.h>

//Variables
    //Cube
        float cubeY = 0.0f; 
        float cubeSpeed = 0.01f; 
    //Sphere

    //Piramide
        float base = 0.3;
        float heigth = 0.5;
        float slices = 4;
        float stacks = 4;
        float angle = 0;

// Función para inicializar la configuración de OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Establece el color de fondo en negro
    glEnable(GL_DEPTH_TEST);  

   
}

void update(int value) {
    angle += 1.0f;  // Incrementa el ángulo
    if (angle > 360.0f) angle -= 360.0f;

    cubeY += cubeSpeed;

    if (cubeY > 0.8f || cubeY < -0.3f) {
        cubeSpeed = -cubeSpeed;
    }

    glutPostRedisplay();  
    glutTimerFunc(16, update, 0);  
}

// Función para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Limpiar Buffer


    // Dibuja el cubo
    glPushMatrix();  //Empezar a crear matriz
    glTranslatef(0.0f, cubeY, 0.0f);  // Mueve el cubo
    glTranslatef(-0.5f, 0.0f, 0.0f);  // Mueve el cubo
    glColor3f(1.0f, 0.0f, 0.0f);  // Establece el color 
    glutSolidCube(0.4f);  // Dibuja un cubo de tamaño x
    glPopMatrix();  //Cerrar matriz y restaurar

    // Dibuja la esfera
    glPushMatrix();  //Empezar a crear matriz
    glTranslatef(0.0f, 0.0f, 0.0f);
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

    glFlush();  //Final
}

// Función principal para inicializar y ejecutar el programa
int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 1200);  // Tamaño de la ventana
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Base");

    init();
    glutDisplayFunc(display);  
    glutTimerFunc(16, update, 0);  // Iniciar update

    glutMainLoop();  // Inicia el ciclo principal de GLUT
    return 0;
}