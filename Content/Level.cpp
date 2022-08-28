#include "pch.h"
#include "Level.h"

bool Level::Update(
    float /* time */,
    float /* elapsedTime */,
    float /* timeRemaining*/,
    std::vector<std::shared_ptr<GameObject>> const& objects
)
{
    int left = 0;

    for (auto&& object : objects)
    {
        if (object->Active() && object->Target())
        {
            if (object->Hit())
            {
                object->Active(false);
            }
            else
            {
                left++;
            }
        }
    }
    return (left == 0);
}

void Level::SaveState(PersistentState& /* state */)
{
}

void Level::LoadState(PersistentState& /* state */)
{
}

std::wstring const& Level::Objective()
{
    return m_objective;
}

float Level::TimeLimit()
{
    return m_timeLimit;
}