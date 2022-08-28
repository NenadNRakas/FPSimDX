// This class defines the sixth and final level of the game. It derives from the
// fifth level. In this level the targets do not disappear when they are hit.
// The target will stay highlighted for two seconds. As this is the last level
// the only criteria for completion is time expiring.
#pragma once

#include "Level5.h"

class Level6 : public Level5
{
public:
    Level6();
    virtual bool Update(
        float time,
        float elapsedTime,
        float timeRemaining,
        std::vector<std::shared_ptr<GameObject>> const& objects
    ) override;
};