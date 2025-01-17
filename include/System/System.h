#pragma once

#include <set>
#include "Entity.h"


class System {
public:
    std::set<Entity> entities;

    virtual void Update() = 0;
};