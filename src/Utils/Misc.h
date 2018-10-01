#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <ImageMagick-7/Magick++.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

#define SAFE_DELETE(var) { delete var; var = nullptr; }

template <class T>
std::string	ptr2Str(T* o) {
    std::stringstream ss;
    ss << o;
    return ss.str();
}
