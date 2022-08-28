// This class derives from MeshObject and creates a ID3D11Buffer of
// vertices and indices to represent the ceiling of the bounding cube
// of the world.
// The vertices are defined by a position, a normal and a single
// 2D texture coordinate.
#pragma once
#include <MeshObject.h>
class WorldCeilingMesh : public MeshObject
{
public:
    WorldCeilingMesh(_In_ winrt::com_ptr<ID3D11Device3> const& device);
};

// WorldFloorMesh:
// This class derives from MeshObject and creates a ID3D11Buffer of
// vertices and indices to represent the floor of the bounding cube
// of the world.

class WorldFloorMesh : public MeshObject
{
public:
    WorldFloorMesh(_In_ winrt::com_ptr<ID3D11Device3> const& device);
};

// WorldWallsMesh:
// This class derives from MeshObject and creates a ID3D11Buffer of
// vertices and indices to represent the walls of the bounding cube
// of the world.

class WorldWallsMesh : public MeshObject
{
public:
    WorldWallsMesh(_In_ winrt::com_ptr<ID3D11Device3> const& device);
};