#include "Vertex.h"

Vertex::Vertex()
:   position(0.f)
,   texCoord(0.f)
,   normal(0.f, 1.f, 0.f)
{

}

Vertex::Vertex(float px, float py, float pz, float tx, float ty, float nx, float ny, float nz)
:   position(px, py, pz)
,   texCoord(tx, ty)
,   normal(nx, ny, nz)
{

}

Vertex::Vertex(glm::vec3 p, glm::vec2 t, glm::vec3 n)
:   position(p)
,   texCoord(t)
,   normal(n)
{

}
