#include "Renderer.h"

Renderer::Renderer(Shader* shader)
    : _shader(shader)
{

}

Renderer::~Renderer()
{

}

void Renderer::load()
{
    _location.MVPMatrix = _shader->getLocation("MVPMatrix");
}

void Renderer::draw(Transformer &trans, Model *model)
{
    Config* config = Config::get();
    glm::mat4 projectionMatrix = glm::perspective(45.f, (float)config->width / (float)config->height, 0.01f, 100.f);
    glm::mat4 MVPMatrix = projectionMatrix * trans.transform();


    glUniformMatrix4fv(_location.MVPMatrix, 1, GL_FALSE, &MVPMatrix[0][0]);

    model->draw();
}

void Renderer::draw(Transformer &trans, Model *model, Texture *texture)
{
    glm::mat4 MVPMatrix = trans.transform();

    texture->bind(0);

    glUniformMatrix4fv(_location.MVPMatrix, 1, GL_FALSE, &MVPMatrix[0][0]);

    model->draw();
}
