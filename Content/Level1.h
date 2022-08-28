// This class defines the first level of the game. There are nine active targets.
// Each of the targets is stationary and can be hit in any order.
#pragma once

#include "Level.h"

class Level1 : public Level
{
public:
    Level1();
    virtual void Initialize(std::vector<std::shared_ptr<GameObject>> const& objects) override;
};