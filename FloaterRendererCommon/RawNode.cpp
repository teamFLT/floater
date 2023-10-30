#include "./include/RawNode.h"

flt::RawNode::RawNode(const std::wstring& name, Transform& transform) :
	name(name),
	transform(transform),
	mesh(nullptr),
	camera(nullptr),
	boneIndex(-1),
	children()
{

}

