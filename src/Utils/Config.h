#ifndef CONFIG_H
#define CONFIG_H

#include "Misc.h"
#include "Log.h"

class Config {
public:
    int width = 1400;
    int height = 900;
    std::string title = "OpenGL 3D Engine";

    static Config* get();
private:
    Config();

    ~Config();
};

#endif // CONFIG_H
