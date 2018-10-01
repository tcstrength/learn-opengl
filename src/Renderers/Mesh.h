#ifndef MESH_H
#define MESH_H

#include "Model.h"
#include "Vertex.h"

class Mesh : public Model {
public:
    Mesh();

    ~Mesh();

    void clear();

    void load(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);

    void load(std::vector<Vertex>& vertices);

    void draw();

private:

    GLuint _numVertices;
    GLuint _numIndices;
    GLuint _vertexObj;
    GLuint _arrayObj;
    GLuint _indexObj;
    GLuint _materialIndex;
};

#endif // MESH_H
