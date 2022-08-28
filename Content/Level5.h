// This class defines the fifth level of the game. It derives from the
// third level. This level introduces obstacles that move into place
// during game play. The targets may be hit in any order.
#pragma once

#include "Level3.h"

class Level5 : public Level3
{
public:
    Level5();
    virtual void Initialize(std::vector<std::shared_ptr<GameObject>> const& objects) override;
};