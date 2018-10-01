#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "../Utils/Log.h"
#include "../Utils/Config.h"

class Transformer {
public:
    Transformer();

    ~Transformer();

    glm::mat4 transform();

    glm::vec3 position() const;

    void setPosition(const glm::vec3 &position);

    float scale() const;

    void setScale(float scale);

    float pitch() const;

    void setPitch(float pitch);

    float yaw() const;

    void setYaw(float yaw);

private:
    glm::vec3 _position;
    float     _scale;
    float     _pitch;
    float     _yaw;
};

#endif // TRANSFORMER_H
