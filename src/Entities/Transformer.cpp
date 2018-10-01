#include "Transformer.h"

Transformer::Transformer()
    : _position(0.f)
    , _scale(1.f)
    , _pitch(0.f)
    , _yaw(0.f)
{

}

Transformer::~Transformer()
{

}

glm::mat4 Transformer::transform()
{
    glm::mat4 modelMatrix(1.f);

    modelMatrix = glm::translate(modelMatrix, _position);
    modelMatrix = glm::scale(modelMatrix, glm::vec3(_scale));
    modelMatrix = glm::rotate(modelMatrix, _pitch, glm::vec3(0.f, 1.f, 0.f));
    modelMatrix = glm::rotate(modelMatrix, _yaw, glm::vec3(1.f, 0.f, 0.f));

    return modelMatrix;
}

glm::vec3 Transformer::position() const
{
    return _position;
}

void Transformer::setPosition(const glm::vec3 &position)
{
    _position = position;
}

float Transformer::scale() const
{
    return _scale;
}

void Transformer::setScale(float scale)
{
    _scale = scale;
}

float Transformer::pitch() const
{
    return _pitch;
}

void Transformer::setPitch(float pitch)
{
    _pitch = pitch;
}

float Transformer::yaw() const
{
    return _yaw;
}

void Transformer::setYaw(float yaw)
{
    _yaw = yaw;
}
