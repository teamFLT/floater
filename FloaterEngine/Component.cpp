
#include "GameObject.h"
#include "Transform.h"
#include "Component.h"


flt::engine::Component::Component(GameObject* gameObject, std::string id, std::string name):
	BaseObject(id, name),
	_components(gameObject->components) {}

flt::engine::Component::~Component()
{
}

void flt::engine::Component::SendMessage(std::string message)
{
}

void flt::engine::Component::BroadcastMessage(std::string message)
{
}

void flt::engine::Component::SendMessageUpward(std::string message)
{
}
