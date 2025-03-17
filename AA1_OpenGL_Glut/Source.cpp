#include <GL/glut.h>

// Función para inicializar la configuración de OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Establece el color de fondo en negro
    glEnable(GL_DEPTH_TEST);  // Habilita el test de profundidad
}

// Función para dibujar la escena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    glFlush();  
}

// Función principal para inicializar y ejecutar el programa
int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);  // Tamaño de la ventana
    glutInitWindowPosition(100, 100);  // Posición de la ventana
    glutCreateWindow("OpenGL Base");  // Título de la ventana

    init();
    glutDisplayFunc(display);  

    glutMainLoop();  // Inicia el ciclo principal de GLUT
    return 0;
}