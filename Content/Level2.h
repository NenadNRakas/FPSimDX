// This class defines the second level of the game. It derives from the
// first level. In this level the targets must be hit in numeric order.
#pragma once

#include "Level1.h"

class Level2 : public Level1
{
public:
    Level2();
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
