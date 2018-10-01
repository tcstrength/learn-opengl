#ifndef VERTEX_H
#define VERTEX_H

#include "../Utils/Misc.h"

struct Vertex {
    Vertex();

    Vertex(float px, float py, float pz, float tx, float ty, float nx, float ny, float nz);

    Vertex(glm::vec3 p, glm::vec2 t, glm::vec3 n);

    glm::vec3 position;
    glm::vec2 texCoord;
    glm::vec3 normal;
};

#endif // VERTEX_H
