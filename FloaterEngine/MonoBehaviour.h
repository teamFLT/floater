#pragma once
#include <string>
#include "Behaviour.h"

namespace flt
{
	namespace engine
	{
		class MonoBehaviour : public Behaviour
		{
		public:
			MonoBehaviour(GameObject* gameObject, std::string id, std::string name);
			~MonoBehaviour() override;

			void Invoke(std::string methodName);
			void Invoke(std::string methodName, float delay);
			void InvokeRepeating(std::string methodName, float interval);

			virtual void Reset();
			virtual void Awake();
			virtual void Start();
			virtual void Update();
			virtual void OnDestroy();
			virtual void OnDisable();
			virtual void OnEnable();
			virtual void FixedUpdate();
			virtual void LateUpdate();
			virtual void OnApplicationFocus(); //윈도우 focus시
			virtual void OnApplicationPause(); //윈도우 non focus시
			virtual void OnApplicationQuit(); //윈도우 종료시
			virtual void OnBecameInvisible();
			virtual void OnBecameVisible();

			//물리
			virtual void OnCollisionEnter();
			virtual void OnCollisionExit();
			virtual void OnCollisionStay();
			virtual void OnTriggerEnter();
			virtual void OnTriggerExit();
			virtual void OnTriggerStay();
			
			//Picking 이후
			virtual void OnMouseDown(); 
			virtual void OnMouseDrag();
			virtual void OnMouseExit();
			virtual void OnMouseOver();
			virtual void OnMouseUp();
		};
	}
}
