#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
    clear();
}

void Mesh::clear()
{
    glDeleteVertexArrays(1, &_arrayObj);
    glDeleteBuffers(1, &_vertexObj);
    glDeleteBuffers(1, &_indexObj);
}

void Mesh::load(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
    clear();

    _numVertices = vertices.size();
    _numIndices = indices.size();

    glGenVertexArrays(1, &_arrayObj);
    glGenBuffers(1, &_vertexObj);
    glGenBuffers(1, &_indexObj);
    glBindVertexArray(_arrayObj);

    glBindBuffer(GL_ARRAY_BUFFER, _vertexObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _numVertices, &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * _numIndices, &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
//    glEnableVertexAttribArray(1);
//    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glBindVertexArray(0);
}

void Mesh::load(std::vector<Vertex> &vertices)
{
    std::vector<GLuint> indices;

    for (uint i = 0; i < vertices.size(); ++i)
        indices.push_back(i);

    load(vertices, indices);
}

void Mesh::draw()
{
    glBindVertexArray(_arrayObj);
    glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, nullptr);
}
