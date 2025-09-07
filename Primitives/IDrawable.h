#pragma once

#include <any>

class IDrawable {
public:
    virtual ~IDrawable() {};

    virtual std::any getConcreteGraphicLibImpl() const = 0;
};
