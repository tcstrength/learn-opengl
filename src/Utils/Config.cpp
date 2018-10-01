#include "Config.h"

Config::Config()
{

}

Config::~Config()
{

}

Config* Config::get()
{
    static Config conf;

    return &conf;
}
