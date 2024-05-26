// OpenGL Mathematics (glm) for C.
#include "rotation.h"

typedef struct 
{
    double rx;
    double ry;
    double rz;
} rotation_weights;
const int MAX_STEPS_FOR_RY_ROTATION = 365 + 20; // qUANTIDADE MÁXIMA; UMA VOLTA + 5 GRAUS
const int STEP_INCREMENT_VALUE = 10;
bool rotate(
    int* steps,
    SDL_Window* window,
    GLuint VAO,
    GLuint u_MVPMatrix,
    double maxRotations,
    rotation_weights r_weights) // Peso para cada rotação. Feito para não causar repetição de código
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if (*steps >= maxRotations) // Se a quantidade de passos for igual a 100, paramos de rotacionar
    {
        *steps = 0;
        return true;
    }
    
    vec3 cameraPos = {0.0f, 2.0f, 5.0f};
    vec3 cameraTarget = {0.0f, 0.0f, 0.0f};
    vec3 cameraUp = {0.0f, 1.0f, 0.0f};

    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mat4 modelMatrix, viewMatrix, projectionMatrix;

    float tx = 0.0f, ty = 0.0f, tz = 0.0f;

    //  Esse calculo maluco foi feito apenas para facilitar na chamada do método quais rotações serão feitas
    float rx = 0.0f + ((*steps) * r_weights.rx);
    float ry = 0.0f + ((*steps) * r_weights.ry);
    float rz = 0.0f + ((*steps) * r_weights.rz);

    float sx = 1.0f, sy = 1.0f, sz = 1.0f;
    glm_mat4_identity(modelMatrix);
    glm_translate(modelMatrix, (vec3){ tx, ty, tz });

    glm_rotate(modelMatrix, glm_rad(rx), (vec3){ 1.0f, 0.0f, 0.0f });
    glm_rotate(modelMatrix, glm_rad(ry), (vec3){ 0.0f, 1.0f, 0.0f });
    glm_rotate(modelMatrix, glm_rad(rz), (vec3){ 0.0f, 0.0f, 1.0f });
    glm_scale(modelMatrix, (vec3){ sx, sy, sz });
    glm_lookat(cameraPos, cameraTarget, cameraUp, viewMatrix);

    float fov = glm_rad(60.0f);
    float aspect = WINDOW_WIDTH * 1.0f / WINDOW_HEIGHT * 1.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;
    glm_perspective(fov, aspect, nearPlane, farPlane, projectionMatrix);
    *steps += STEP_INCREMENT_VALUE;

    mat4 MVPMatrix;
    glm_mat4_mul(projectionMatrix, viewMatrix, MVPMatrix);
    glm_mat4_mul(MVPMatrix, modelMatrix, MVPMatrix);

    // Envio da matriz MVP para o vertex shader.
    glUniformMatrix4fv(u_MVPMatrix, 1, GL_FALSE, (const GLfloat *)MVPMatrix);
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles -> 6 squares
    glBindVertexArray(VAO);
    SDL_GL_SwapWindow(window);

    if ((*steps) % 100 == 1) // Feito apenas por fins de debuggings preguiçosos
        printf("%d\n", *steps);
    return false;
}

bool rotate_horizontal(int* steps, SDL_Window* window, GLuint VAO, GLuint u_MVPMatrix)
{
    rotation_weights r_weights = {rx: 0.0, ry: 1, rz: 0.0};
    return rotate(steps, window, VAO, u_MVPMatrix, MAX_STEPS_FOR_RY_ROTATION, r_weights);
}
bool rotate_vertical(int* steps, SDL_Window* window, GLuint VAO, GLuint u_MVPMatrix)
{
    rotation_weights r_weights = {rx: 1.0, ry: 0.0, rz: 0.0};
    return rotate(steps, window, VAO, u_MVPMatrix, MAX_STEPS_FOR_RY_ROTATION, r_weights);
}