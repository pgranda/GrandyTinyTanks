#include "Node.h"

void Node::SetParent(Node* a_parent)
{
	if (a_parent == this)
		return;

	if (m_pParent != nullptr)
	{
		m_pParent->RemoveChild(this);
	}
	m_pParent = a_parent;
	m_pParent->AddChild(this);
}

void Node::AddChild(Node* a_child)
{
	auto iter = m_pChildren.find(a_child);
	//Children are stored in a set. One of the features of a set is easy searching for an item
	//this allows us to see if the child already exists in the set of children. 
	//If it exists already we will not add it to the set multiple times.
	if (iter == m_pChildren.end())
	{
		m_pChildren.emplace(a_child);
	}
}

void Node::RemoveChild(Node* a_child)
{
	//if we can find the child remove it, a successful find returns an iterator to the object
	//we are looking for. An unsuccessful find returns an iterator that is one item past the end of the set
	auto iter = m_pChildren.find(a_child);
	if (iter != m_pChildren.end())
	{
		m_pChildren.erase(iter);
	}
}

void Node::GetWorldTransform(Matrix3& transform)
{
	if (m_pParent)
	{
		m_pParent->GetWorldTransform(transform);
		transform = m3PosRot * transform;
	}
	else
	{
		transform = m3PosRot;
	}
}

void Node::GetLocalTransform(Matrix3 a_m3Transform)
{
	a_m3Transform = m3PosRot;
}

void Node::SetTranslation(Vector2 a_v2Translation)
{
	m3PosRot.SetRow(2, Vector3(a_v2Translation));
}

void Node::RotateZ(float a_fRotation)
{
	Matrix3 m3Rotation = Matrix3::IDENTITY;
	m3Rotation.Rotate(a_fRotation);
	m3PosRot = m3Rotation * m3PosRot;
}

void Node::Scale(float a_fScale)
{
	Vector3 translation = Vector3::ZERO;
	m3PosRot.GetRow(2, translation);

	Matrix3 scale = Matrix3::IDENTITY;
	scale.Scale(a_fScale);
	m3PosRot = scale * m3PosRot;

	m3PosRot.SetRow(2, translation);

}

Node::Node()
{
	m_pParent = nullptr;
	m3PosRot = Matrix3::IDENTITY;
}

Node::~Node()
{
	for (auto iter = m_pChildren.begin(); iter != m_pChildren.end(); ++iter)
	{
		RemoveChild(*iter);
	}
	m_pParent = nullptr;
}