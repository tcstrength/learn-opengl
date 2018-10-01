#include "Renderers/Display.h"
#include "Renderers/Mesh.h"
#include "Renderers/Texture.h"
#include "Renderers/Renderer.h"
#include "Shaders/Shader.h"

Display display;
Shader shader;
Renderer renderer(&shader);
Mesh mesh;
Texture testPng;
Transformer transformer;

void init();

int main()
{
    init();

    while (display.isOpen())
    {
        display.begin();
        display.disable3D();
        shader.bind();

        renderer.draw(transformer, &mesh, &testPng);

        display.end();
    }
    return 0;
}

void init()
{
    std::vector<Vertex> vertices = {
        Vertex( 0.5f, 0.5f, 0.0f,    0.0f, 0.0f,     0.0f, 0.0f, 1.0f),
        Vertex(-0.5f, 0.5f, 0.0f,    0.0f, 0.0f,     0.0f, 0.0f, 1.0f),
        Vertex( 0.0f, 0.0f, 0.0f,    0.0f, 0.0f,     0.0f, 0.0f, 1.0f),
    };

    std::vector<GLuint> indices = {
        0, 1, 2
    };

    shader.load("Shaders/main.vs", "Shaders/main.fs");
    renderer.load();
    testPng.load("Textures/unknown.png");
    mesh.load(vertices, indices);
    transformer.setPosition(glm::vec3(0.f, 0.f, 0.f));
}
