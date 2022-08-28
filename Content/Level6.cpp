#include "pch.h"
#include "Level6.h"

Level6::Level6()
{
    m_timeLimit = 20.0f;
    m_objective = L"Hit as many moving targets as possible while avoiding the obstacles before time runs out.";
}

bool Level6::Update(
    float time,
    float elapsedTime,
    float timeRemaining,
    std::vector<std::shared_ptr<GameObject>> const& objects
)
{
    for (auto&& object : objects)
    {
        if (object->Active() && object->Target())
        {
            if (object->Hit() && (object->HitTime() < (time - 2.0f)))
            {
                object->Hit(false);
            }
        }
    }
    return ((timeRemaining - elapsedTime) <= 0.0f);
}
