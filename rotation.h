#ifndef ROTATION_H
#define ROTATION_H

#include <stdio.h>
#include <stdbool.h>
#include <GL/glew.h>    // GLEW: The OpenGL Extension Wrangler Library.
#include <SDL2/SDL.h>   // Simple DirectMedia Layer.
#include "cglm/cglm.h" 


// Rotaciona horizontalmente, e retorna se finalizou de rotacionar
bool rotate_horizontal(int* steps, SDL_Window* window, GLuint VAO, GLuint u_MVPMatrix);
// Rotaciona verticalmente, e retorna se finalizou de rotacionar
bool rotate_vertical(int* steps, SDL_Window* window, GLuint VAO, GLuint u_MVPMatrixint);

#endif // ROTATION_H