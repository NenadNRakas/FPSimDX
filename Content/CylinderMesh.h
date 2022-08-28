// This class derives from MeshObject and creates a ID3D11Buffer of
// vertices and indices to represent a canonical cylinder (capped at
// both ends) that is positioned at the origin with a radius of 1.0,
// a height of 1.0 and with its axis in the +Z direction.
#pragma once

#include "MeshObject.h"

class CylinderMesh : public MeshObject
{
public:
    CylinderMesh(_In_ winrt::com_ptr<ID3D11Device3> const& device, uint16_t segments);
};
