// This class defines the third level of the game. In this level each of the
// nine targets is moving along closed paths and can be hit
// in any order.
#pragma once

#include "Level.h"

class Level3 : public Level
{
public:
    Level3();
    virtual void Initialize(std::vector<std::shared_ptr<GameObject>> const& objects) override;
};