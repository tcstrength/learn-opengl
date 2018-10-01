#include "Shader.h"

Shader::Shader()
{
    LOG_DEBUG("Create new Shader " + ptr2Str(this));

}

Shader::~Shader()
{
    LOG_DEBUG("Delete Shader " + ptr2Str(this));

    glDeleteProgram(_program);
}

void Shader::load(const char* vsPath, const char* fsPath)
{
    glDeleteProgram(_program);

    GLuint vertex = loadShader(vsPath, GL_VERTEX_SHADER);
    GLuint fragment = loadShader(fsPath, GL_FRAGMENT_SHADER);

    checkShader(vertex);
    checkShader(fragment);

    loadProgram(vertex, fragment);
    checkProgram();

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    loadUniforms();
}

GLuint Shader::getLocation(const char* uniformName) {
    GLuint loc = glGetUniformLocation(_program, uniformName);

    if (loc == INVALID_UNIFORM)
        LOG_WARNING("Invalid uniform " + std::string(uniformName));

    return loc;
}

GLuint Shader::loadShader(const char* path, GLenum type)
{
    GLuint shader = glCreateShader(type);

    std::string code;
    std::ifstream shfile(path);
    std::stringstream shstream(code);

    if (shfile.is_open() == false)
        LOG_ERROR("File not found: " + std::string(path));

    shstream << shfile.rdbuf();
    code = shstream.str();
    shfile.close();

    const GLchar* shaderCode = code.c_str();

    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    return shader;
}

void Shader::checkShader(GLuint shader)
{
    int success = 0;
    GLchar infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        LOG_ERROR("SHADER:COMPILE");
        LOG_ERROR(std::string(infoLog));
    }
}

void Shader::loadProgram(GLuint vs, GLuint fs)
{
    _program = glCreateProgram();
    glAttachShader(_program, vs);
    glAttachShader(_program, fs);
    glLinkProgram(_program);
}

void Shader::checkProgram()
{
    int success = 0;
    GLchar infoLog[512];

    glGetProgramiv(_program, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(_program, 512, nullptr, infoLog);
        LOG_ERROR("Shader::LINK:ERROR");
        LOG_ERROR(std::string(infoLog));
    }
}
