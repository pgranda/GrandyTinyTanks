#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <set>

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

class Node
{
public:
	//Constructor
	Node();
	//destructor (virtual as we will use node as a base class)
	virtual ~Node();

	Matrix3 m3PosRot;
	//Function to set this node's parent 
	void SetParent(Node* a_parent);
	//Function to add a child to the node
	void AddChild(Node* a_child);
	//Remove a child from our node hierarchy structure
	void RemoveChild(Node* a_child);
	//Where is this node in the world 
	// this requires us to transform (multiply) this node by any parents it may have (and their parents in turn).
	void GetWorldTransform(Matrix3& transform);
	//Get the local transform for our point
	void GetLocalTransform(Matrix3 a_m3Transform);
	//Set our translation
	void SetTranslation(Vector2 a_v2Translation);
	//Rotate this node around it's z axis
	void RotateZ(float a_fRotation);
	//scale this node
	void Scale(float a_fScale);
private:
	Node* m_pParent;
	std::set<Node*>m_pChildren;

};

#endif _NODE_H_