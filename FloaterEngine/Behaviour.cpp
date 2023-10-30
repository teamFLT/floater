#include "Component.h"
#include "GameObject.h"
#include "Behaviour.h"



flt::engine::Behaviour::Behaviour(GameObject* gameObject, std::string id, std::string name):
	Component(gameObject, id, name),
	enabled(false),
	isActiveAndEnabled(false){}

flt::engine::Behaviour::~Behaviour()
{
}
