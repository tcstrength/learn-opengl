#ifndef RENDERER_H
#define RENDERER_H

#include "../Entities/Transformer.h"
#include "../Shaders/Shader.h"

#include "Texture.h"
#include "Model.h"

class Renderer {
public:
    struct Uniforms {
        GLuint MVPMatrix;
    };

    Renderer(Shader* shader);

    ~Renderer();

    void load();

    void draw(Transformer& trans, Model* model);

    void draw(Transformer &trans, Model *model, Texture* texture);

private:

    Shader* _shader;
    Uniforms _location;
};

#endif // RENDERER_H
