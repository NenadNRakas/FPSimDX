// This class defines the fourth level of the game. It derives from the
// third level. The targets must be hit in numeric order.
#pragma once

#include "Level3.h"

class Level4 : public Level3
{
public:
    Level4();
    virtual void Initialize(std::vector<std::shared_ptr<GameObject>> const& objects) override;

    virtual bool Update(
        float time,
        float elapsedTime,
        float timeRemaining,
        std::vector<std::shared_ptr<GameObject>> const& objects
    ) override;

    virtual void SaveState(PersistentState& state) override;
    virtual void LoadState(PersistentState& state) override;

private:
    int m_nextId;
};


