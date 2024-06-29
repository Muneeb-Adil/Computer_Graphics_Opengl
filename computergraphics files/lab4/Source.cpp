////ARROW
//#include <gl/glut.h>
//
//class Canvas {
//public:
//    float x, y;
//    Canvas() {
//        this->x = 180;
//        this->y = 200;
//    }
//
//    void moveTo(float x, float y) {
//        this->x = x;
//        this->y = y;
//    }
//
//    void lineToRel(float dx, float dy) {
//        glBegin(GL_LINES);
//        glVertex2f(x, y);
//        x += dx;
//        y += dy;
//        glVertex2f(x, y);
//        glEnd();
//    }
//
//    void drawMarker() {
//        // Draw a marker at the current position (x, y)
//        glBegin(GL_POLYGON);
//        glVertex2f(x - 2, y - 2);
//        glVertex2f(x + 2, y - 2);
//        glVertex2f(x + 2, y + 2);
//        glVertex2f(x - 2, y + 2);
//        glEnd();
//    }
//
//    void arrow(float f, float h, float t, float w) {
//        lineToRel(-w - t / 2, -f); // down the left side
//        lineToRel(w, 0);
//        lineToRel(0, -h);
//        lineToRel(t, 0); // across
//        lineToRel(0, h); // back up
//        lineToRel(w, 0);
//        lineToRel(-w - t / 2, f);
//    }
//};
//
//int screenWidth = 640;
//int screenHeight = 440;
//Canvas CP;
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//
//    CP.moveTo(100, 200); // Move to the first data point
//
//    // Draw an arrow at the current position (x, y)
//    // CP.arrow(30, 60, 20, 10);
//
//    // Draw a marker at the CP
//    CP.drawMarker();
//
//    CP.lineToRel(-60, -80);
//    CP.drawMarker();
//
//    CP.lineToRel(50, 0);
//    CP.drawMarker();
//
//    CP.lineToRel(0, -50);
//    CP.drawMarker();
//
//    CP.lineToRel(30, 0);
//    CP.drawMarker();
//
//    CP.lineToRel(0, 50);
//    CP.drawMarker();
//
//    CP.lineToRel(40, 0);
//    CP.drawMarker();
//
//    CP.lineToRel(-60, 80);
//    CP.drawMarker();
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Arrow Lab - 4");
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//    glMatrixMode(GL_MODELVIEW);
//
//    glutDisplayFunc(display);
//
//    glutMainLoop();
//    return 0;
//}





////FIG:3.27
//#include <gl/glut.h>
//#include <Windows.h>
//#include <gl/glu.h>
//#include <gl/gl.h>
//#include <math.h>
//
//using namespace std;
//
//int screenWidth = 640;
//int screenHeight = 480;
//
//class GlintPoint
//{
//public:
//	int  x, y;
//};
//
//class Point2 {
//public:
//	float x, y;
//	void set(float dx, float dy) { x = dx; y = dy; }
//	void set(Point2& p) { x = p.x; y = p.y; }
//	Point2(float xx, float yy) { x = xx; y = yy; }
//	Point2() { x = y = 0; }
//};
//
//Point2 currPos;
//Point2 CP;
//
//void moveTo(Point2 p)
//{
//	CP.set(p);
//}
//void lineTo(Point2 p)
//{
//	glBegin(GL_LINES);
//	glVertex2f(CP.x, CP.y);
//	glVertex2f(p.x, p.y);
//	glEnd();
//	glFlush();
//	CP.set(p);
//}
//
//void myInit(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(1.0, 1.0, 1.0, 0.0); // background is white
//	glColor3f(0.0, 0.0, 1.0); // drawing color is blue
//}
//
//void rosette(int N, float radius)
//{
//	Point2* pointlist = new Point2[N];
//	GLfloat theta = (2.0f * 3.1415926536) / N;
//	for (int c = 0; c < N; c++)
//	{
//		pointlist[c].set(radius * sin(theta * c), radius * cos(theta * c));
//	}
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			moveTo(pointlist[i]);
//			lineTo(pointlist[j]);
//		}
//	}
//}
//
//void render()
//{
//	//this is the callback for displays
//	glClear(GL_COLOR_BUFFER_BIT);
//	glViewport(10, 10, 640, 480);
//	rosette(5, .66f); // <- change the value from 5 to 10 for increased sides
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(30, 30);
//	glutCreateWindow("Lab 3 - Rossete");
//	glutDisplayFunc(render);
//
//	myInit();
//	glutMainLoop();
//
//}






//#include <gl/glut.h>
//#include <Windows.h>
//#define RED 1
//#define GREEN 2
//#define BLUE 3 
//#define WHITE 4
//
//float angle = 0.0;
//float red = 1.0, blue = 1.0, green = 1.0;
//void renderScene(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	glRotatef(angle, 0.0, 1.0, 0.0);
//	glColor3f(red, green, blue);
//
//	glBegin(GL_TRIANGLES);
//	glVertex3f(-0.5, -0.5, 0.0);
//	glVertex3f(0.5, 0.0, 0.0);
//	glVertex3f(0.0, 0.5, 0.0);
//	glEnd();
//	angle++;
//	glutSwapBuffers();
//}
//
//void processMenuEvents(int option) {
//	switch (option) {
//	case RED: 
//		red = 1.0;
//		green = 0.0;
//		blue = 0.0;
//		break;
//	case GREEN:
//		red = 1.0;
//		green = 1.0;
//		blue = 0.0;
//		break;
//	case BLUE:
//		red = 0.0;
//		green = 0.0;
//		blue = 1.0;
//		break;
//	case WHITE:
//		red = 1.0;
//		green = 1.0;
//		blue = 1.0;
//		break;
//
//	}
//}
//
//
//
//int main(int argc, char** argv)
//
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(320,320);
//	glutCreateWindow("Menu Test");
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(renderScene);
//
//	glutCreateMenu(processMenuEvents);
//	glutAddMenuEntry("Red", RED);
//	glutAddMenuEntry("Blue", BLUE);
//	glutAddMenuEntry("Green", GREEN);
//	glutAddMenuEntry("White", WHITE);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutMainLoop();
//	return 0;
//}






////GOLDER RATIO      
//#include <GL/glut.h>
//
// Function to draw the golden rectangle with a specified color
//void drawGoldenRectangle(float centerX, float centerY, float rectWidth, float rectHeight, float r, float g, float b)
//{
//    glColor3f(r, g, b);
//    glBegin(GL_TRIANGLE_STRIP);
//    glVertex2f(centerX - rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX - rectWidth / 2, centerY + rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY + rectHeight / 2);
//    glEnd();
//}
//
// Display callback function
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//     Calculate initial center and size for the golden rectangle
//    float centerX = 0.0f;
//    float centerY = 0.0f;
//    float rectWidth = 0.5f;
//    float rectHeight = 0.5f;
//
//     Draw the regression of golden rectangles with different colors
//    for (int i = 0; i < 10; ++i)
//    {
//        float r = (i / 10.0f);      // Varies from 0.0 to 1.0
//        float g = (1.0f - r);       // Varies from 1.0 to 0.0
//        float b = (0.5f + r / 2);   // Varies from 0.5 to 1.0
//
//        drawGoldenRectangle(centerX, centerY, rectWidth, rectHeight, r, g, b);
//
//         Update center and size for the next rectangle
//        centerX *= 0.9f;
//        centerY *= 0.9f;
//        rectWidth *= 0.9f;
//        rectHeight *= 0.9f;
//    }
//
//    glFlush();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 400);
//    glutCreateWindow("Golden Rectangles");
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}
//




//
//////maze game
//#include <GL/glut.h> // Include OpenGL GLUT library
//#include <iostream> // Include C++ input/output stream
//#include <vector> // Include C++ vector container
//#include <random> // Include C++ random number generation
//#include <ctime> // Include C time library for time-related functions
//#include <stack> // Include C++ stack container
//#include <cmath> // Include C math library for mathematical functions
//#include <chrono> // Include C++ chrono library for time measurement
//#include <sstream> // Include C++ string stream for string manipulation
//
//const int ROWS = 35; // Number of rows in the maze grid
//const int COLS = 35; // Number of columns in the maze grid
//const int CELL_SIZE = 35; // Size of each maze cell in pixels
//
//// Structure representing a cell in the maze
//struct Cell {
//    bool visited; // Whether the cell has been visited during maze generation
//    bool wallTop, wallRight, wallBottom, wallLeft; // Walls around the cell
//};
//const int TIMER_DURATION = 120; // Game duration in seconds
//const int TIMER_INTERVAL = 1;   // Timer update interval in seconds
//
//
//std::vector<Cell> maze(ROWS* COLS); // Vector to represent the maze cells
//int startRow, startCol, endRow, endCol, playerRow, playerCol; // Maze start, end, and player positions
//
//bool gameWon = false; // Flag to indicate if the game has been won
//bool gameLost = false; // Flag to indicate if the game has been lost
//
//std::chrono::time_point<std::chrono::system_clock> startTime; // Time when the game started
//
//// Function to check if a given row and column are within valid maze bounds
//bool isValid(int row, int col) {
//    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
//}
//
//void generateMaze() {
//    for (int row = 0; row < ROWS; ++row) {
//        for (int col = 0; col < COLS; ++col) {
//            maze[row * COLS + col].visited = false;
//            maze[row * COLS + col].wallTop = true;
//            maze[row * COLS + col].wallRight = true;
//            maze[row * COLS + col].wallBottom = true;
//            maze[row * COLS + col].wallLeft = true;
//        }
//    }
//
//    std::stack<std::pair<int, int>> stack;
//    startRow = std::rand() % ROWS;
//    startCol = std::rand() % COLS;
//    stack.push(std::make_pair(startRow, startCol));
//    maze[startRow * COLS + startCol].visited = true;
//
//    while (!stack.empty()) {
//        int currentRow = stack.top().first;
//        int currentCol = stack.top().second;
//        stack.pop();
//
//        std::vector<int> neighbors = { 0, 1, 2, 3 };
//        std::shuffle(neighbors.begin(), neighbors.end(), std::mt19937(std::random_device()()));
//
//        for (int dir : neighbors) {
//            int newRow = currentRow;
//            int newCol = currentCol;
//            switch (dir) {
//            case 0: newRow--; break; // Up
//            case 1: newCol++; break; // Right
//            case 2: newRow++; break; // Down
//            case 3: newCol--; break; // Left
//            }
//
//            if (isValid(newRow, newCol) && !maze[newRow * COLS + newCol].visited) {
//                if (dir == 0) {
//                    maze[currentRow * COLS + currentCol].wallTop = false;
//                    maze[newRow * COLS + newCol].wallBottom = false;
//                }
//                if (dir == 1) {
//                    maze[currentRow * COLS + currentCol].wallRight = false;
//                    maze[newRow * COLS + newCol].wallLeft = false;
//                }
//                if (dir == 2) {
//                    maze[newRow * COLS + newCol].wallTop = false;
//                    maze[currentRow * COLS + currentCol].wallBottom = false;
//                }
//                if (dir == 3) {
//                    maze[newRow * COLS + newCol].wallRight = false;
//                    maze[currentRow * COLS + currentCol].wallLeft = false;
//                }
//
//                stack.push(std::make_pair(newRow, newCol));
//                maze[newRow * COLS + newCol].visited = true;
//            }
//        }
//    }
//
//    startRow = 0;
//    startCol = 0;
//    maze[startRow * COLS + startCol].wallLeft = false;
//
//    // Set the ending point
//    endRow = ROWS - 1;
//    endCol = COLS - 1;
//    maze[endRow * COLS + endCol].wallRight = false;
//
//    // Set the player's initial position to the starting point
//    playerRow = startRow;
//    playerCol = startCol;
//}
//void drawTimer(int minutes, int seconds) {
//    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
//    glRasterPos2i(10, ROWS * CELL_SIZE - 20); // Set text position
//    std::stringstream timerText; // Create a string stream for timer text
//    timerText << minutes << " min " << seconds << " sec left"; // Compose timer text
//
//    // Loop to draw each character of the timer text
//    for (char c : timerText.str()) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Draw character using GLUT
//    }
//}
//void drawGameOverWindow(const std::string& message) {
//    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
//    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
//
//    glColor3f(1.0f, 1.0f, 1.0f);
//    int messageWidth = 400; // Width of the message box
//    int messageHeight = 200; // Height of the message box
//    int messageX = (windowWidth - messageWidth) / 2;
//    int messageY = (windowHeight - messageHeight) / 2;
//    glRectf(messageX, messageY, messageX + messageWidth, messageY + messageHeight);
//
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glRasterPos2i(messageX + 50, messageY + 140);
//    for (char c : message) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//    }
//
//    glRasterPos2i(messageX + 100, messageY + 100);
//    std::string options = "Press 1 to play again, 2 to exit.";
//    for (char c : options) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//    }
//}
//
//void checkGameStatus() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    if (!gameWon && !gameLost) {
//        auto currentTime = std::chrono::system_clock::now();
//        std::chrono::duration<double> elapsedSeconds = currentTime - startTime;
//        int remainingTime = TIMER_DURATION - static_cast<int>(elapsedSeconds.count());
//
//        int minutes = remainingTime / 60;
//        int seconds = remainingTime % 60;
//
//        drawTimer(minutes, seconds);
//
//        if (remainingTime <= 0) {
//            gameLost = true;
//        }
//
//    }
//    // Draw the maze walls
//    for (int row = 0; row < ROWS; ++row) {
//        for (int col = 0; col < COLS; ++col) {
//            const Cell& cell = maze[row * COLS + col];
//            int x = col * CELL_SIZE;
//            int y = row * CELL_SIZE;
//
//            glColor3f(1.0f, 1.0f, 1.0f);
//            if (cell.wallTop) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y);
//                glVertex2i(x + CELL_SIZE, y);
//                glEnd();
//            }
//            if (cell.wallRight) {
//                glBegin(GL_LINES);
//                glVertex2i(x + CELL_SIZE, y);
//                glVertex2i(x + CELL_SIZE, y + CELL_SIZE);
//                glEnd();
//            }
//            if (cell.wallBottom) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y + CELL_SIZE);
//                glVertex2i(x + CELL_SIZE, y + CELL_SIZE);
//                glEnd();
//            }
//            if (cell.wallLeft) {
//                glBegin(GL_LINES);
//                glVertex2i(x, y);
//                glVertex2i(x, y + CELL_SIZE);
//                glEnd();
//            }
//        }
//    }
//
//    // Draw the starting point (e.g., a green square)
//    glColor3f(0.0f, 1.0f, 0.0f);
//    glBegin(GL_QUADS);
//    glVertex2i(startCol * CELL_SIZE, startRow * CELL_SIZE);
//    glVertex2i((startCol + 1) * CELL_SIZE, startRow * CELL_SIZE);
//    glVertex2i((startCol + 1) * CELL_SIZE, (startRow + 1) * CELL_SIZE);
//    glVertex2i(startCol * CELL_SIZE, (startRow + 1) * CELL_SIZE);
//    glEnd();
//
//    // Draw the ending point (e.g., a red square)
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glBegin(GL_QUADS);
//    glVertex2i(endCol * CELL_SIZE, endRow * CELL_SIZE);
//    glVertex2i((endCol + 1) * CELL_SIZE, endRow * CELL_SIZE);
//    glVertex2i((endCol + 1) * CELL_SIZE, (endRow + 1) * CELL_SIZE);
//    glVertex2i(endCol * CELL_SIZE, (endRow + 1) * CELL_SIZE);
//    glEnd();
//
//    // Draw the player's icon (e.g., a blue circle)
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_TRIANGLE_FAN);
//    float playerX = playerCol * CELL_SIZE + CELL_SIZE / 2.0f;
//    float playerY = playerRow * CELL_SIZE + CELL_SIZE / 2.0f;
//    glVertex2f(playerX, playerY);
//    for (int i = 0; i <= 360; i++) {
//        float angle = 3.1415926f * i / 180.0f;
//        glVertex2f(playerX + cos(angle) * CELL_SIZE / 4.0f, playerY + sin(angle) * CELL_SIZE / 4.0f);
//    }
//    glEnd();
//
//    if (gameWon) {
//        drawGameOverWindow("Congratulations! You won the game.");
//    }
//    else if (gameLost) {
//        drawGameOverWindow("Time's up! Game over.");
//    }
//
//    glutSwapBuffers();
//}
//
//void timerCallback(int value) {
//    checkGameStatus();
//    glutPostRedisplay();
//    if (!gameWon && !gameLost) {
//        glutTimerFunc(TIMER_INTERVAL * 1000, timerCallback, 0); // Update timer
//    }
//}
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, COLS * CELL_SIZE, 0, ROWS * CELL_SIZE);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void movePlayer(int key, int x, int y) {
//    if (!gameWon && !gameLost) {
//        switch (key) {
//        case GLUT_KEY_DOWN:
//            if (!maze[playerRow * COLS + playerCol].wallTop && isValid(playerRow - 1, playerCol)) {
//                playerRow--;
//            }
//            break;
//        case GLUT_KEY_UP:
//            if (!maze[playerRow * COLS + playerCol].wallBottom && isValid(playerRow + 1, playerCol)) {
//                playerRow++;
//            }
//            break;
//        case GLUT_KEY_LEFT:
//            if (!maze[playerRow * COLS + playerCol].wallLeft && isValid(playerRow, playerCol - 1)) {
//                playerCol--;
//            }
//            break;
//        case GLUT_KEY_RIGHT:
//            if (!maze[playerRow * COLS + playerCol].wallRight && isValid(playerRow, playerCol + 1)) {
//                playerCol++;
//            }
//            break;
//        default:
//            break;
//        }
//
//        // Check if the player has reached the ending point
//        if (playerRow == endRow && playerCol == endCol) {
//            gameWon = true;
//        }
//
//        glutPostRedisplay();
//    }
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    if (gameWon || gameLost) {
//        if (key == '1') {
//            // Play again: Reset the game and flags
//            generateMaze();
//            gameWon = false;
//            gameLost = false;
//            startTime = std::chrono::system_clock::now(); // Restart the timer
//        }
//        else if (key == '2') {
//            // Exit: Close the application
//            exit(0);
//        }
//    }
//        // Check if the player has reached the ending point
//        if (playerRow == endRow && playerCol == endCol) {
//            gameWon = true;
//        }
//
//        glutPostRedisplay();
//}
//int main(int argc, char** argv) {
//    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
//
//    generateMaze(); // Generate the maze
//
//    // Initialize OpenGL and GLUT
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
//    glutCreateWindow("Maze Game");
//    glutDisplayFunc(checkGameStatus); // Set the display function to checkGameStatus
//    glutReshapeFunc(reshape);
//
//    // Register keyboard and special key callbacks
//    glutKeyboardFunc(keyboard);
//    glutSpecialFunc(movePlayer);
//
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the background color to black
//
//    // Start the timer
//    startTime = std::chrono::system_clock::now();
//
//    // Register the timer callback function
//    glutTimerFunc(0, timerCallback, 0);
//
//    glutMainLoop(); // Enter the GLUT main loop
//
//    return 0;
//}
//




//
////GOLDEN RATIO
//#include <GL/glut.h>
////Function to draw the golden rectangle with a specified color
//void drawGoldenRectangle(float centerX, float centerY, float rectWidth, float rectHeight, float r, float g, float b)
//{
//    glColor3f(r, g, b);
//    glBegin(GL_TRIANGLE_STRIP);
//    glVertex2f(centerX - rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY - rectHeight / 2);
//    glVertex2f(centerX - rectWidth / 2, centerY + rectHeight / 2);
//    glVertex2f(centerX + rectWidth / 2, centerY + rectHeight / 2);
//    glEnd();
//}
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    //Calculate initial center and size for the golden rectangle
//    float centerX = 0.0f;
//    float centerY = 0.0f;
//    float rectWidth = 0.5f;
//    float rectHeight = 0.5f;
//
//    //Draw the regression of golden rectangles with different colors
//        for (int i = 0; i < 10; ++i)
//        {
//            float r = (i / 10.0f);      // Varies from 0.0 to 1.0
//            float g = (1.0f - r);       // Varies from 1.0 to 0.0
//            float b = (0.5f + r / 2);   // Varies from 0.5 to 1.0
//
//            drawGoldenRectangle(centerX, centerY, rectWidth, rectHeight, r, g, b);
//
//            //Update center and size for the next rectangle
//            centerX *= 0.9f;
//            centerY *= 0.9f;
//            rectWidth *= 0.9f;
//            rectHeight *= 0.9f;
//        }
//
//    glFlush();
//}

//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 400);
//    glutCreateWindow("Golden Rectangles");
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}




