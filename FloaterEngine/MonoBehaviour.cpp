
#include "GameObject.h"
#include "MonoBehaviour.h"



flt::engine::MonoBehaviour::MonoBehaviour(GameObject* gameObject, std::string id, std::string name) :
	Behaviour(gameObject, id, name) {}

flt::engine::MonoBehaviour::~MonoBehaviour()
{
}

void flt::engine::MonoBehaviour::Invoke(std::string methodName)
{
}

void flt::engine::MonoBehaviour::Invoke(std::string methodName, float delay)
{
}

void flt::engine::MonoBehaviour::InvokeRepeating(std::string methodName, float interval)
{
}

void flt::engine::MonoBehaviour::Reset()
{
}

void flt::engine::MonoBehaviour::Awake()
{
}

void flt::engine::MonoBehaviour::Start()
{
}

void flt::engine::MonoBehaviour::Update()
{
}

void flt::engine::MonoBehaviour::FixedUpdate()
{
}

void flt::engine::MonoBehaviour::LateUpdate()
{
}

void flt::engine::MonoBehaviour::OnApplicationFocus()
{
}

void flt::engine::MonoBehaviour::OnApplicationPause()
{
}

void flt::engine::MonoBehaviour::OnApplicationQuit()
{
}

void flt::engine::MonoBehaviour::OnBecameInvisible()
{
}

void flt::engine::MonoBehaviour::OnBecameVisible()
{
}

void flt::engine::MonoBehaviour::OnCollisionEnter()
{
}

void flt::engine::MonoBehaviour::OnCollisionExit()
{
}

void flt::engine::MonoBehaviour::OnCollisionStay()
{
}

void flt::engine::MonoBehaviour::OnTriggerEnter()
{
}

void flt::engine::MonoBehaviour::OnTriggerExit()
{
}

void flt::engine::MonoBehaviour::OnTriggerStay()
{
}

void flt::engine::MonoBehaviour::OnDestroy()
{
}

void flt::engine::MonoBehaviour::OnDisable()
{
}

void flt::engine::MonoBehaviour::OnEnable()
{
}

void flt::engine::MonoBehaviour::OnMouseDown()
{
}

void flt::engine::MonoBehaviour::OnMouseDrag()
{
}

void flt::engine::MonoBehaviour::OnMouseExit()
{
}

void flt::engine::MonoBehaviour::OnMouseOver()
{
}

void flt::engine::MonoBehaviour::OnMouseUp()
{
}
