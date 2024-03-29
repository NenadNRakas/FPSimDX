// This is the class representing a generic object in the 3D world of the game. There are
// specific sub-classes that have specific geometric shapes. This class contains all the
// properties of objects that are common.
//
// During the game physics calculations the IsTouching method will be called to determine
// the object's proximity to a point. It is expected the sub-classes will replace this method.
// The Render method will be called during rendering to include the object in the generation of
// the scene.
#pragma once

#include "MeshObject.h"
#include "SoundEffect.h"
#include "Animate.h"
#include "Material.h"

class GameObject
{
public:
    GameObject();

    // Expect the IsTouching method to be overloaded by subclasses.
    virtual bool IsTouching(
        DirectX::XMFLOAT3 /* point */,
        float /* radius */,
        _Out_ DirectX::XMFLOAT3* contact,
        _Out_ DirectX::XMFLOAT3* normal
    )
    {
        *contact = DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
        *normal = DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f);
        return false;
    };

    void Render(
        _In_ ID3D11DeviceContext* context,
        _In_ ID3D11Buffer* primitiveConstantBuffer
    );

    void Active(bool active);
    bool Active();
    void Target(bool target);
    bool Target();
    void Hit(bool hit);
    bool Hit();
    void OnGround(bool ground);
    bool OnGround();
    void TargetId(int targetId);
    int  TargetId();
    void HitTime(float t);
    float HitTime();

    void AnimatePosition(_In_ std::shared_ptr<Animate> const& animate);
    std::shared_ptr<Animate> AnimatePosition();

    void HitSound(_In_ std::shared_ptr<SoundEffect> const& hitSound);
    std::shared_ptr<SoundEffect> HitSound();

    void PlaySound(float impactSpeed, DirectX::XMFLOAT3 eyePoint);

    void Mesh(_In_ std::shared_ptr<MeshObject> const& mesh);

    void NormalMaterial(_In_ std::shared_ptr<Material> const& material);
    std::shared_ptr<Material> NormalMaterial();
    void HitMaterial(_In_ std::shared_ptr<Material> const& material);
    std::shared_ptr<Material> HitMaterial();

    void Position(DirectX::XMFLOAT3 position);
    void Position(DirectX::XMVECTOR position);
    void Velocity(DirectX::XMFLOAT3 velocity);
    void Velocity(DirectX::XMVECTOR velocity);
    DirectX::XMMATRIX ModelMatrix();
    DirectX::XMFLOAT3 Position();
    DirectX::XMVECTOR VectorPosition();
    DirectX::XMVECTOR VectorVelocity();
    DirectX::XMFLOAT3 Velocity();

protected:
    DirectX::XMFLOAT4X4 m_modelMatrix;
    DirectX::XMFLOAT3   m_position;

private:
    virtual void UpdatePosition() {};
    // Object Data
    bool                         m_active;
    bool                         m_target;
    int                          m_targetId;
    bool                         m_hit;
    bool                         m_ground;

    DirectX::XMFLOAT3            m_velocity;

    std::shared_ptr<Material>    m_normalMaterial;
    std::shared_ptr<Material>    m_hitMaterial;

    DirectX::XMFLOAT3            m_defaultXAxis;
    DirectX::XMFLOAT3            m_defaultYAxis;
    DirectX::XMFLOAT3            m_defaultZAxis;

    float                        m_hitTime;

    std::shared_ptr<Animate>     m_animatePosition;
    std::shared_ptr<MeshObject>  m_mesh;

    std::shared_ptr<SoundEffect> m_hitSound;
};

__forceinline void GameObject::Active(bool active)
{
    m_active = active;
}

__forceinline bool GameObject::Active()
{
    return m_active;
}

__forceinline void GameObject::Target(bool target)
{
    m_target = target;
}

__forceinline bool GameObject::Target()
{
    return m_target;
}

__forceinline void GameObject::Hit(bool hit)
{
    m_hit = hit;
}

__forceinline bool GameObject::Hit()
{
    return m_hit;
}

__forceinline void GameObject::OnGround(bool ground)
{
    m_ground = ground;
}

__forceinline bool GameObject::OnGround()
{
    return m_ground;
}

__forceinline void GameObject::TargetId(int targetId)
{
    m_targetId = targetId;
}

__forceinline int GameObject::TargetId()
{
    return m_targetId;
}

__forceinline void GameObject::HitTime(float t)
{
    m_hitTime = t;
}

__forceinline float GameObject::HitTime()
{
    return m_hitTime;
}

__forceinline void GameObject::Position(DirectX::XMFLOAT3 position)
{
    m_position = position;
    // Update any internal states that are dependent on the position.
    // UpdatePosition is a virtual function that is specific to the derived class.
    UpdatePosition();
}

__forceinline void GameObject::Position(DirectX::XMVECTOR position)
{
    XMStoreFloat3(&m_position, position);
    // Update any internal states that are dependent on the position.
    // UpdatePosition is a virtual function that is specific to the derived class.
    UpdatePosition();
}

__forceinline DirectX::XMFLOAT3 GameObject::Position()
{
    return m_position;
}

__forceinline DirectX::XMVECTOR GameObject::VectorPosition()
{
    return DirectX::XMLoadFloat3(&m_position);
}

__forceinline void GameObject::Velocity(DirectX::XMFLOAT3 velocity)
{
    m_velocity = velocity;
}

__forceinline void GameObject::Velocity(DirectX::XMVECTOR velocity)
{
    XMStoreFloat3(&m_velocity, velocity);
}

__forceinline DirectX::XMFLOAT3 GameObject::Velocity()
{
    return m_velocity;
}

__forceinline DirectX::XMVECTOR GameObject::VectorVelocity()
{
    return DirectX::XMLoadFloat3(&m_velocity);
}

__forceinline void GameObject::AnimatePosition(_In_ std::shared_ptr<Animate> const& animate)
{
    m_animatePosition = animate;
}

__forceinline std::shared_ptr<Animate> GameObject::AnimatePosition()
{
    return m_animatePosition;
}

__forceinline void GameObject::NormalMaterial(_In_ std::shared_ptr<Material> const& material)
{
    m_normalMaterial = material;
}

__forceinline std::shared_ptr<Material> GameObject::NormalMaterial()
{
    return m_normalMaterial;
}

__forceinline void GameObject::HitMaterial(_In_ std::shared_ptr<Material> const& material)
{
    m_hitMaterial = material;
}

__forceinline std::shared_ptr<Material> GameObject::HitMaterial()
{
    return m_hitMaterial;
}

__forceinline void GameObject::Mesh(_In_ std::shared_ptr<MeshObject> const& mesh)
{
    m_mesh = mesh;
}

__forceinline void GameObject::HitSound(_In_ std::shared_ptr<SoundEffect> const& hitSound)
{
    m_hitSound = hitSound;
}

__forceinline std::shared_ptr<SoundEffect> GameObject::HitSound()
{
    return m_hitSound;
}

__forceinline DirectX::XMMATRIX GameObject::ModelMatrix()
{
    return DirectX::XMLoadFloat4x4(&m_modelMatrix);
}
