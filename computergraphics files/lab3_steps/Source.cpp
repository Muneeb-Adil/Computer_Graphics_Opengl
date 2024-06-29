////STEP:01     screen color changes
//#include <GL/glut.h>
//#include <iostream>
//#include <random>
//#include <tuple>
//
//// Function to generate a random RGB color as float values from 0 to 1
//std::tuple<float, float, float> getRandomRGBColor() {
//    // Obtain a random seed from the system
//    std::random_device rd;
//
//    // Mersenne Twister 19937 generator
//    std::mt19937 gen(rd());
//
//    // Distribution for RGB color values (0.0 to 1.0)
//    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
//
//    // Generate random values for R, G, and B components
//    float r = dis(gen);
//    float g = dis(gen);
//    float b = dis(gen);
//
//    // Return the RGB color as a tuple
//    return std::make_tuple(r, g, b);
//}
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//
//    glFlush();
//
//}
//
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//// mouse even callback
//void Mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//
//        Display();
//        changeWindowColor(r, g, b, 1.0);
//
//    }
//
//}
//
//// keyboard event callback
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 'b' or key == 'B') {
//
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//
//        Display();
//        changeWindowColor(r, g, b, 1.0);
//
//    }
//    else if (key == 'q' or key == 'Q') {
//        exit(0);
//    }
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(100,150);
//    glutInitWindowSize(640,480);
//
//
//    glutCreateWindow("Step1: Add Reshape, Mouse and Keyboard Handler routine to Lab 01");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//    glutMouseFunc(Mouse);
//    glutKeyboardFunc(keyboard);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//}




////STEP:02    points on screen,with different screen colors
//#include <GL/glut.h>
//#include <iostream>
//#include <random>
//#include <tuple>
//
//// Function to generate a random RGB color as float values from 0 to 1
//std::tuple<float, float, float> getRandomRGBColor() {
//    // Obtain a random seed from the system
//    std::random_device rd;
//
//    // Mersenne Twister 19937 generator
//    std::mt19937 gen(rd());
//
//    // Distribution for RGB color values (0.0 to 1.0)
//    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
//
//    // Generate random values for R, G, and B components
//    float r = dis(gen);
//    float g = dis(gen);
//    float b = dis(gen);
//
//    // Return the RGB color as a tuple
//    return std::make_tuple(r, g, b);
//}
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//
//    glFlush();
//
//}
//
//
//void DisplayPoint(int x, int y) {
//
//    // glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 1000, 0, 1000);
//
//    // Draw
//
//    glPointSize(10.0);
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    glBegin(GL_POINTS);
//
//    glVertex2f(x, 1000 - y);
//
//    glEnd();
//
//
//    glFlush();
//
//
//}
//
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//// reshape event callback
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 1000, 0, 1000);
//}
//
//// mouse event callback
//void Mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//        // std::cout << x << " " << y << "\n"; 
//
//        DisplayPoint(x, y);
//
//    }
//
//}
//
//// keyboard event callback
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 'b' or key == 'B') {
//
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//
//        Display();
//        changeWindowColor(r, g, b, 1.0);
//
//    }
//    else if (key == 'q' or key == 'Q') {
//        exit(0);
//    }
//    else if (key == 'c' or key == 'C') {
//
//        Display();
//
//    }
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(100,150);
//    glutInitWindowSize(640,480);
//
//
//    glutCreateWindow("STEP 2: Placing Dots with Mouse");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//    glutMouseFunc(Mouse);
//    glutKeyboardFunc(keyboard);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//}




////STEP:03           screen points like brush
//#include <GL/glut.h>
//#include <iostream>
//#include <random>
//#include <tuple>
//#include <vector>
//
//// Brush properties
//int brushSize = 10;
//float brushColor[3] = { 0.9294, 0.1294, 0.5333 };
//
//// Store points for the brush stroke
//std::vector<std::pair<int, int>> points;
//
//
//// Function to generate a random RGB color as float values from 0 to 1
//std::tuple<float, float, float> getRandomRGBColor() {
//    // Obtain a random seed from the system
//    std::random_device rd;
//
//    // Mersenne Twister 19937 generator
//    std::mt19937 gen(rd());
//
//    // Distribution for RGB color values (0.0 to 1.0)
//    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
//
//    // Generate random values for R, G, and B components
//    float r = dis(gen);
//    float g = dis(gen);
//    float b = dis(gen);
//
//    // Return the RGB color as a tuple
//    return std::make_tuple(r, g, b);
//}
//
//
//
//// Function to draw the brush stroke
//void drawBrushStroke() {
//    glColor3fv(brushColor);
//    glPointSize(brushSize);
//    glBegin(GL_POINTS);
//    for (const auto& point : points) {
//        glVertex2i(point.first, point.second);
//    }
//    glEnd();
//}
//
//// Function to handle mouse motion
//void mouseMotion(int x, int y) {
//    points.push_back(std::make_pair(x, y));
//    glutPostRedisplay();
//}
//
//// Function to handle window resizing
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, width, height, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// Function to display the scene
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawBrushStroke();
//    glFlush();
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//
//// keyboard event callback
//void keyboard(unsigned char key, int x, int y) {
//    if (key == '+') {
//
//        brushSize += 10;
//
//    }
//    else if (key == '-') {
//        brushSize -= 10;
//        if (brushSize <= 10) {
//            brushSize = 10;
//        }
//
//    }
//    else if (key == 'b') {
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//        brushColor[0] = r; // Red
//        brushColor[1] = g; // Green
//        brushColor[2] = b; // Blue
//
//    }
//    else if (key == 'q' or key == 'Q') {
//        exit(0);
//    }
//    else if (key == 'c' or key == 'C') {
//
//        points.clear();
//        glutPostRedisplay();
//
//    }
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Step 03: Free Hand Drawing with Fat Brush");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMotionFunc(mouseMotion); // Register the mouse motion callback function
//    glutKeyboardFunc(keyboard);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//    return 0;
//}





////STEP:04  viewport and worldwindow
//#include <GL/glut.h>
//
//float minX = -10, minY = -10, maxX = 10, maxY = 10;
//int VP_Bottom = 0, VP_Left = 0, VP_Width = 640, VP_Height = 480;
//
//
//void drawAxis() {
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//    glBegin(GL_LINES);
//    glVertex2f(minX, 0);
//    glVertex2f(maxX, 0);
//    glEnd();
//
//    glBegin(GL_LINES);
//    glVertex2f(0, minY);
//    glVertex2f(0, maxY);
//    glEnd();
//
//}
//
//void myDisplay(void) {
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(VP_Bottom, VP_Left, VP_Width, VP_Height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(minX, maxX, minY, maxY);
//    drawAxis();
//    glFlush();
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(VP_Width, VP_Height);
//    glutCreateWindow("Step 04: Using both ViewPort and World Window");
//
//    glutDisplayFunc(myDisplay);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//    return 0;
//}





////STEP:05      mountain on screen with different colors on mountains
//#include <GL/glut.h>
//#include <iostream>
//#include <random>
//#include <tuple>
//
//// Function to generate a random RGB color as float values from 0 to 1
//std::tuple<float, float, float> getRandomRGBColor() {
//    // Obtain a random seed from the system
//    std::random_device rd;
//
//    // Mersenne Twister 19937 generator
//    std::mt19937 gen(rd());
//
//    // Distribution for RGB color values (0.0 to 1.0)
//    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
//
//    // Generate random values for R, G, and B components
//    float r = dis(gen);
//    float g = dis(gen);
//    float b = dis(gen);
//
//    // Return the RGB color as a tuple
//    return std::make_tuple(r, g, b);
//}
//
//
//// Function to handle window resizing
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//}
//
//// Function to display the scene
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glFlush();
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//void drawMountains(float r, float g, float b) {
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(r, g, b);
//
//    float P1 = -10.0;
//    float P2 = -5.0;
//    float P3 = -7.5;
//
//    for (int i = 0; i < 5; i++) {
//
//
//        glBegin(GL_TRIANGLES);
//        glVertex2f(P1, 0.0);
//        glVertex2f(P2, 0.0);
//        glVertex2f(P3, 5);
//        glEnd();
//
//        P1 += 5.0;
//        P2 += 5.0;
//        P3 += 5.0;
//
//        glFlush();
//    }
//
//
//}
//
//
//// keyboard event callback
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 'm' or key == 'M') {
//
//        drawMountains(0.9294, 0.1294, 0.5333);
//
//    }
//    else if (key == 'b') {
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//        drawMountains(r, g, b);
//
//
//    }
//    else if (key == 'q' or key == 'Q') {
//        exit(0);
//    }
//    else if (key == 'c' or key == 'C') {
//        display();
//
//    }
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Step 5: Adding Keyboard Interaction");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//    return 0;
//}







////STEP:06   not working
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <GL/glut.h>
//#include <iostream>
//#include <random>
//#include <tuple>
//
//// Function to generate a random RGB color as float values from 0 to 1
//std::tuple<float, float, float> getRandomRGBColor() {
//    // Obtain a random seed from the system
//    std::random_device rd;
//
//    // Mersenne Twister 19937 generator
//    std::mt19937 gen(rd());
//
//    // Distribution for RGB color values (0.0 to 1.0)
//    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
//
//    // Generate random values for R, G, and B components
//    float r = dis(gen);
//    float g = dis(gen);
//    float b = dis(gen);
//
//    // Return the RGB color as a tuple
//    return std::make_tuple(r, g, b);
//}
//
//
//// Function to handle window resizing
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//}
//
//// Function to display the scene
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glFlush();
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//void drawMountains(float r, float g, float b) {
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(r, g, b);
//
//    float P1 = -10.0;
//    float P2 = -5.0;
//    float P3 = -7.5;
//
//    for (int i = 0; i < 5; i++) {
//
//
//        glBegin(GL_TRIANGLES);
//        glVertex2f(P1, 0.0);
//        glVertex2f(P2, 0.0);
//        glVertex2f(P3, 5);
//        glEnd();
//
//        P1 += 5.0;
//        P2 += 5.0;
//        P3 += 5.0;
//
//        glFlush();
//    }
//
//
//}
//
//
//// keyboard event callback
//void keyboard(unsigned char key, int x, int y) {
//    if (key == 'm' or key == 'M') {
//
//        drawMountains(0.9294, 0.1294, 0.5333);
//
//    }
//    else if (key == 'b') {
//        std::tuple<float, float, float> randomColor = getRandomRGBColor();
//
//        // Access individual R, G, and B components from the tuple
//        float r = std::get<0>(randomColor);
//        float g = std::get<1>(randomColor);
//        float b = std::get<2>(randomColor);
//
//        drawMountains(r, g, b);
//
//
//    }
//    else if (key == 'q' or key == 'Q') {
//        exit(0);
//    }
//    else if (key == 'c' or key == 'C') {
//        display();
//
//    }
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Step 6: Adding Background Music");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    // Load the background music
//    sf::Music backgroundMusic;
//    if (!backgroundMusic.openFromFile("background_music.wav")) {
//        return -1;
//    }
//
//    backgroundMusic.setLoop(true); // Make the music loop
//    backgroundMusic.play(); // Start playing the music
//
//
//    glutMainLoop();
//    return 0;
//}





//STEP:07   TEXT on screen
#include <GL/glut.h>
#include <string>

void drawText(std::string text, int x, int y) {
    glRasterPos2f(x, y);
    int Len = text.length();
    for (int i = 0; i < Len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// changing background color
void changeWindowColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void display() {
    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.9294, 0.1294, 0.5333);
    drawText("Lab # 3", 250, 400);
    drawText("Computer Graphics using OpenGL :)", 250, 420);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("STEP 7: Writing Text to the Screen");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);

    glutMainLoop();
    return 0;
}
