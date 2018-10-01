#include "Texture.h"

Texture::Texture()
{
    LOG_DEBUG("Create new Texture " << this);
}

Texture::~Texture()
{
    LOG_DEBUG("Delete Texture " << this);

    glDeleteTextures(1, &_texObj);
}

void Texture::bind(GLenum texUnit)
{
    glActiveTexture(texUnit);
    glBindTexture(_target, _texObj);
}

void Texture::free()
{
    glDeleteTextures(1, &_texObj);
}

int Texture::width() const
{
    return _width;
}

int Texture::height() const
{
    return _height;
}

bool Texture::load(std::string path, GLenum target)
{
    LOG_DEBUG("Load Texture " << path);

    glDeleteTextures(1, &_texObj);

    _target = target;
    _path = path;

    try {
        _image.read(_path);
        _image.write(&_blob, "RGBA"); }
    catch (Magick::Error& error) {
        LOG_ERROR("Texture::Error while loading " + _path + ": " + error.what());
        return false;
    }

    _width = _image.columns();
    _height = _image.rows();

    glGenTextures(1, &_texObj);
    glBindTexture(_target, _texObj);
    glTexImage2D(_target, 0, GL_RGBA, _image.columns(), _image.rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _blob.data());
    glTexParameterf(_target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(_target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(_target, 0);

    return true;
}
