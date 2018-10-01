#ifndef MODEL_H
#define MODEL_H

class Model {
public:
    Model();

    virtual ~Model();

    virtual void draw() = 0;
};

#endif // MODEL_H
