#include <GL/glut.h>

//Variables
    //Cube

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
    value += 1.0f;  // Incrementa el ángulo
    if (value > 360.0f) value -= 360.0f;

    glutPostRedisplay();  
    glutTimerFunc(16, update, 0);  
}

// Función para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Limpiar Buffer


    // Dibuja el cubo
    glPushMatrix();  //Empezar a crear matriz
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
    glColor3f(0.0f, 1.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);  // Rotar para q apunte hacia arriba
    glutSolidCone(base, heigth, slices, stacks);
    glPopMatrix();  //Cerrar matriz y restaurar

    glFlush();  //Final
}

// Función principal para inicializar y ejecutar el programa
int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);  // Tamaño de la ventana
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Base");

    init();
    glutDisplayFunc(display);  

    glutMainLoop();  // Inicia el ciclo principal de GLUT
    return 0;
}