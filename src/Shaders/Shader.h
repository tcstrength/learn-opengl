#ifndef SHADER_H
#define SHADER_H

#include "../Utils/Config.h"

#define INVALID_UNIFORM 0xFFFFFFFF

class Shader {
public:
    Shader();

    virtual ~Shader();

    void load(const char* vsPath, const char* fsPath);

    GLuint getLocation(const char* uniformName);

    void bind() { glUseProgram(_program); }

    void unbind() { glUseProgram(0); }


protected:

    virtual void loadUniforms() { }

    virtual void connectTextures() { }

private:

    GLuint loadShader(const char* path, GLenum type);

    void checkShader(GLuint shader);

    void loadProgram(GLuint vs, GLuint fs);

    void checkProgram();

    GLuint _program;
};

#endif // SHADER_H
