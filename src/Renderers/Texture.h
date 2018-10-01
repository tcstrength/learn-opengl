#ifndef TEXTURE_H
#define TEXTURE_H

#include "../Utils/Log.h"

class Texture {
public:
    Texture();

    ~Texture();

    void bind(GLenum texUnit = GL_TEXTURE0);

    bool load(std::string path, GLenum target = GL_TEXTURE_2D);

    void free();

    std::string& path() { return _path; }

    int width() const;

    int height() const;

private:
    Magick::Image _image;
    Magick::Blob _blob;
    GLuint _texObj;
    GLuint _target;
    std::string _path;
    int _width;
    int _height;

};

#endif // TEXTURE_H
