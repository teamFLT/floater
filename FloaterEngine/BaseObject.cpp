#include <cassert>

#include "Component.h"
#include "GameObject.h"
#include "BaseObject.h"

std::unordered_map<std::string, flt::engine::BaseObject*> flt::engine::BaseObject::s_baseObjects;

flt::engine::BaseObject::BaseObject(std::string id, std::string name) :
	id(id),
	name(name) {}

std::string flt::engine::BaseObject::GetInstanceID() const
{
	return id;
}

std::string flt::engine::BaseObject::ToString() const
{
	return name;
}

void flt::engine::BaseObject::RemoveFProperty(std::string name)
{
	fproperties.erase(std::remove(fproperties.begin(), fproperties.end(), GetFProperty(name)), fproperties.end());
}

flt::engine::IProperty* flt::engine::BaseObject::GetFProperty(const std::string& name) const
{
	for (IProperty* iProp : fproperties)
	{
		if (iProp->GetName() == name)
		{
			return iProp;
		}
	}
	assert("Property is not exist");
	return nullptr;
}

void flt::engine::BaseObject::SetFProperty(const std::string& name, const std::string& value)
{
	for (IProperty* iProp : fproperties)
	{
		if (iProp->GetName() == name)
		{
			iProp->SetValue(value);
			break;
		}
	}
}

void flt::engine::BaseObject::Destroy(BaseObject* object, float delay)
{
	//*수정필요 : 딜레이
GameObjectManager::Destroy(dynamic_cast<GameObject*>(object));
}

flt::engine::BaseObject* flt::engine::BaseObject::FindObjectByInstanceID(const std::string& id)
{
	return s_baseObjects[id];
}

void flt::engine::BaseObject::DontDestroyOnLoad(BaseObject* target)
{
	dynamic_cast<GameObject*>(target)->DontDestroyOnLoad();
}

