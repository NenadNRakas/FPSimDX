// This class derives from MeshObject and creates a ID3D11Buffer of
// vertices and indices to represent a canonical sphere that is
// positioned at the origin with a radius of 1.0.
#pragma once

#include "MeshObject.h"

class SphereMesh : public MeshObject
{
public:
    SphereMesh(_In_ winrt::com_ptr<ID3D11Device3> const& device, uint16_t segments);
};
