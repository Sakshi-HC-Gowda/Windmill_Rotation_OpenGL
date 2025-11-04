#include <GL/freeglut.h>
#include <math.h>

float angle = 0.0f;   // rotation angle
float speed = 1.0f;   // rotation speed
int direction = 1;    // 1 for clockwise, -1 for anticlockwise

// Function to draw a circle
void drawCircle(float x, float y, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180;
        glVertex2f(x + r * cos(theta), y + r * sin(theta));
    }
    glEnd();
}

// Function to draw a single blade
void drawBlade() {
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.2f, -0.05f);
    glEnd();
}

// Function to draw a cloud
void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int j = 0; j < 3; j++) {
        drawCircle(x + j * 0.08f, y, 0.06f);
    }
}

// Function to draw a simple tree
void drawTree(float x, float y) {
    // Trunk
    glColor3f(0.36f, 0.25f, 0.20f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.02f, y - 0.1f);
    glVertex2f(x + 0.02f, y - 0.1f);
    glVertex2f(x + 0.02f, y);
    glVertex2f(x - 0.02f, y);
    glEnd();

    // Leaves
    glColor3f(0.0f, 0.5f, 0.0f);
    drawCircle(x, y + 0.05f, 0.07f);
}

// Function to draw a small house
void drawHouse(float x, float y) {
    // Base
    glColor3f(0.8f, 0.5f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y - 0.1f);
    glVertex2f(x + 0.1f, y + 0.05f);
    glVertex2f(x - 0.1f, y + 0.05f);
    glEnd();

    // Roof
    glColor3f(0.6f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.12f, y + 0.05f);
    glVertex2f(x + 0.12f, y + 0.05f);
    glVertex2f(x, y + 0.15f);
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Ground
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    // Sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.8f, 0.8f, 0.1f);

    // Clouds
    drawCloud(-0.8f, 0.8f);
    drawCloud(0.0f, 0.7f);
    drawCloud(0.6f, 0.85f);

    // Trees
    drawTree(-0.6f, -0.1f);
    drawTree(-0.4f, -0.1f);
    drawTree(0.6f, -0.1f);

    // House
    drawHouse(0.4f, -0.3f);

    // Windmill pole (broader)
    glColor3f(0.5f, 0.25f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.8f);
    glVertex2f(0.05f, -0.8f);
    glVertex2f(0.05f, 0.2f);
    glVertex2f(-0.05f, 0.2f);
    glEnd();

    // Hub
    glColor3f(0.8f, 0.0f, 0.0f);
    drawCircle(0.0f, 0.2f, 0.05f);

    // Rotating blades
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 4; i++) {
        drawBlade();
        glRotatef(90, 0.0f, 0.0f, 1.0f);
    }
    glPopMatrix();

    glFlush();
}

// Timer for animation
void update(int value) {
    angle += direction * speed;
    if (angle > 360) angle -= 360;
    if (angle < 0) angle += 360;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Keyboard control
void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        direction = -1; // anticlockwise
        speed = 1;
        break;
    case GLUT_KEY_RIGHT:
        direction = 1; // clockwise
        speed = 1;
        break;
    case GLUT_KEY_DOWN:
        speed = 0; // stop
        break;
    case GLUT_KEY_UP:
        speed = 1; // resume
        break;
    }
}

// Initialization
void init() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // light sky blue
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 700);
    glutCreateWindow("Windmill Scene - Computer Graphics Project");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
