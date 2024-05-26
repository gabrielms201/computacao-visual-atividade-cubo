# HelloGL
"Hello, World!" de Computação Gráfica usando C, SDL, OpenGL e GLSL.


# O que foi feito

Primeiramente, alteramos o triângulo para o cubo, conforme no snippet abaixo:
```c
    // Definição dos vértices do cubo.
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  // 0
        0.5f, -0.5f, -0.5f,  // 1
        0.5f,  0.5f, -0.5f,  // 2
        -0.5f,  0.5f, -0.5f,  // 3
        -0.5f, -0.5f,  0.5f,  // 4
        0.5f, -0.5f,  0.5f,  // 5
        0.5f,  0.5f,  0.5f,  // 6
        -0.5f,  0.5f,  0.5f   // 7
    };
    // Definição das cores dos vértices do cubo.
    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,  // Vermelho
        0.0f, 1.0f, 0.0f,  // Verde
        0.0f, 0.0f, 1.0f,  // Azul
        1.0f, 1.0f, 0.0f,  // Amarelo
        1.0f, 0.0f, 1.0f,  // Magenta
        0.0f, 1.0f, 1.0f,  // Ciano
        1.0f, 1.0f, 1.0f,  // Branco
        0.5f, 0.5f, 0.5f   // Cinza
    };
```


# Como rodar (UBUNTU)
```
sudo apt-get install build-essential libxmu-dev libxi-dev libgl-dev
sudo apt-get install libglfw3-dev
sudo apt-get install libglew-dev
sudo apt-get install libsdl2-dev
```

- Build pelo cmake
# Referencias
- https://www.youtube.com/watch?v=LxEFn-cGdE0
- https://github.com/nigels-com/glew
- https://github.com/recp/cglm
- https://launchpad.net/ubuntu/+source/cglm
- http://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/
- https://github.com/lszl84/wx_gl_cube_tutorial/blob/main/src/cube.h
- https://github.com/c2d7fa/opengl-cube