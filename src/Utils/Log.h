#ifndef LOG_H
#define LOG_H

#include "Misc.h"

#define LOG_DEBUG(anything) LOG_LEVEL("DEBUG", anything)

#define LOG_ERROR(anything) LOG_LEVEL("ERROR", anything)

#define LOG_WARNING(anything) LOG_LEVEL("WARNING", anything)

#define LOG_LEVEL(level, anything) \
    std::cout << std::endl << "[ " << Log::getTime() << ", " << level << " ] " << anything << std::endl;

class Log {
public:

    std::ofstream& getStream();

    static Log* get();

    static std::string getTime();

private:

    Log();

    ~Log();

    const char* LOG_FILENAME = "log.txt";
    std::ofstream _stream;
};

#endif // LOG_H
