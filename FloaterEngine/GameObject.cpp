#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

flt::engine::GameObject::GameObject(std::string id, std::string name) : BaseObject(id, name) {}

flt::engine::GameObject::~GameObject()
{
}

void flt::engine::GameObject::DontDestroyOnLoad()
{
	_dontDestroyFlag = true;
}

void flt::engine::GameObject::Reflected()
{
	
}

void flt::engine::GameObject::Awake()
{
}

void flt::engine::GameObject::Start()
{
}

void flt::engine::GameObject::Update()
{
}

void flt::engine::GameObject::OnDestroy()
{
}

void flt::engine::GameObject::OnDisable()
{
}

void flt::engine::GameObject::OnEnable()
{
}

void flt::engine::GameObject::FixedUpdate()
{
}

void flt::engine::GameObject::LateUpdate()
{
}

void flt::engine::GameObject::OnApplicationFocus()
{
}

void flt::engine::GameObject::OnApplicationPause()
{
}

void flt::engine::GameObject::OnApplicationQuit()
{
}

void flt::engine::GameObject::OnBecameInvisible()
{
}

void flt::engine::GameObject::OnBecameVisible()
{
}

void flt::engine::GameObject::OnCollisionEnter()
{
}

void flt::engine::GameObject::OnCollisionExit()
{
}

void flt::engine::GameObject::OnCollisionStay()
{
}

void flt::engine::GameObject::OnTriggerEnter()
{
}

void flt::engine::GameObject::OnTriggerExit()
{
}

void flt::engine::GameObject::OnTriggerStay()
{
}

void flt::engine::GameObject::OnMouseDown()
{
}

void flt::engine::GameObject::OnMouseDrag()
{
}

void flt::engine::GameObject::OnMouseExit()
{
}

void flt::engine::GameObject::OnMouseOver()
{
}

void flt::engine::GameObject::OnMouseUp()
{
}
