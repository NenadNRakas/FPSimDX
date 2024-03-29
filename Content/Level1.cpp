#include "pch.h"
#include "Level1.h"
#include "Face.h"

using namespace DirectX;

Level1::Level1()
{
    m_timeLimit = 20.0f;
    m_objective = L"Hit each of the targets before time runs out.\nTouch to aim. Tap in right box to fire. Drag in left box to move.";
}

void Level1::Initialize(std::vector<std::shared_ptr<GameObject>> const& objects)
{
    XMFLOAT3 position[] =
    {
        XMFLOAT3(-2.5f, -1.0f, -1.5f),
        XMFLOAT3(-1.0f,  1.0f, -3.0f),
        XMFLOAT3(1.5f,  0.0f, -3.0f),
        XMFLOAT3(-2.5f, -1.0f, -5.5f),
        XMFLOAT3(0.5f, -2.0f, -5.0f),
        XMFLOAT3(1.5f, -2.0f, -5.5f),
        XMFLOAT3(2.0f,  0.0f,  0.0f),
        XMFLOAT3(0.0f,  0.0f,  0.0f),
        XMFLOAT3(-2.0f,  0.0f,  0.0f)
    };

    int targetCount = 0;
    for (auto&& object : objects)
    {
        if (auto target = dynamic_cast<Face*>(object.get()))
        {
            if (targetCount < 9)
            {
                target->Active(true);
                target->Target(true);
                target->Hit(false);
                target->AnimatePosition(nullptr);
                target->Position(position[targetCount]);
                targetCount++;
            }
            else
            {
                object->Active(false);
            }
        }
        else
        {
            object->Active(false);
        }
    }
}
