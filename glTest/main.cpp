//
//  main.cpp
//  glTest
//
//  Created by Esteban Muñoz Lagos on 03-12-17.
//  Copyright © 2017 Esteban Muñoz Lagos. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void render(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glRotatef(45.0, 0.0, 1.0, 0.0);
    
    glBegin(GL_TRIANGLES); {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.5f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.5f, -0.5f);
    }
    glEnd();
}

int main(int argc, const char * argv[]) {
    GLFWwindow *win;
    
    if(!glfwInit()) {
        return -1;
    }
    
    win = glfwCreateWindow(640, 480, "OpenGl Test", NULL, NULL);
    if(!win) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    if(!glewInit()) {
        return -1;
    }
    
    glfwMakeContextCurrent(win);
    
    while (!glfwWindowShouldClose(win)) {
        render();
        glfwSwapBuffers(win);
        glfwPollEvents();
    }
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}
