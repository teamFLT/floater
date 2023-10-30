#pragma once
#include <vector>
#include "BaseObject.h"

namespace flt
{
	namespace engine
	{
		class Component;
		class Transform;

		class GameObject : public BaseObject
		{
		public:
			friend class GameObjectManager;
		public:
			GameObject(std::string id,std::string name);
			~GameObject() override;
			void DontDestroyOnLoad();//씬이 로드될때 개체를 삭제하지 않음
			void Reflected() override;
			void Awake();
			void Start();
			void Update();
			void OnDestroy();
			void OnDisable();
			void OnEnable();
			void FixedUpdate();
			void LateUpdate();
			void OnApplicationFocus(); //윈도우 focus시
			void OnApplicationPause(); //윈도우 non focus시
			void OnApplicationQuit(); //윈도우 종료시
			void OnBecameInvisible();
			void OnBecameVisible();
			
			void OnCollisionEnter();
			void OnCollisionExit();
			void OnCollisionStay();
			void OnTriggerEnter();
			void OnTriggerExit();
			void OnTriggerStay();


			void OnMouseDown();
			void OnMouseDrag();
			void OnMouseExit();
			void OnMouseOver();
			void OnMouseUp();

			std::vector<Component*> components;
			Transform* transform;

		private:
			bool _dontDestroyFlag;
		};

	}
}
