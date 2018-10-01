#include "Log.h"

Log::Log()
{
    _stream.open(LOG_FILENAME);
}

Log::~Log()
{
    _stream.close();
}

Log* Log::get()
{
    static Log log;

    return &log;
}

std::ofstream& Log::getStream()
{
    return _stream;
}

std::string Log::getTime()
{
    time_t now = time(nullptr);
    tm* lc = localtime(&now);
    std::string s;
    s += ((lc->tm_hour < 10) ? "0" + std::to_string(lc->tm_hour) : std::to_string(lc->tm_hour)) + ':';
    s += ((lc->tm_min < 10) ? "0" + std::to_string(lc->tm_min) : std::to_string(lc->tm_min)) + ':';
    s += ((lc->tm_sec < 10) ? "0" + std::to_string(lc->tm_sec) : std::to_string(lc->tm_sec));
    return s;
}
