TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lglfw -lGLEW -lGL -lassimp $(shell Magick++-config --ldflags --libs)

QMAKE_CXXFLAGS += $(shell Magick++-config --cppflags --cxxflags)

SOURCES += \
    src/main.cpp \
    src/Utils/Config.cpp \
    src/Utils/Misc.cpp \
    src/Utils/Log.cpp \
    src/Renderers/Display.cpp \
    src/Renderers/Model.cpp \
    src/Renderers/Mesh.cpp \
    src/Renderers/Vertex.cpp \
    src/Renderers/Texture.cpp \
    src/Shaders/Shader.cpp \
    src/Renderers/Renderer.cpp \
    src/Entities/Transformer.cpp

HEADERS += \
    src/Utils/Config.h \
    src/Utils/Misc.h \
    src/Utils/Log.h \
    src/Renderers/Display.h \
    src/Renderers/Model.h \
    src/Renderers/Mesh.h \
    src/Renderers/Vertex.h \
    src/Renderers/Texture.h \
    src/Shaders/Shader.h \
    src/Renderers/Renderer.h \
    src/Entities/Transformer.h
