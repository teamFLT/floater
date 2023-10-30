#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <concepts> 

#include "FDelegate.h"
#include "GameObjectManager.h"
#include "IProperty.h"
#include "FProperty.h"


namespace flt
{
	namespace engine
	{
		class GameObject;

		class BaseObject;
		class Component;

		template <class T>
		concept DerivedFromBaseObject = std::is_base_of_v<BaseObject, T>;


		class BaseObject
		{

		public:
			BaseObject(std::string id, std::string name);
			virtual ~BaseObject() = default;

			std::string	GetInstanceID() const; // 개체의 인스턴스 ID를 반환

			std::string ToString() const; // 개체의 이름을 반환

			virtual void Reflected() abstract; // 리플랙션을 통해 생성될 코드의 삽입부

			#pragma region FPROPERTY

			template<typename T>
			void AddFProperty(const T& value, const std::string& name); // 변수명을 통해 Property를 추가

			void RemoveFProperty(std::string name); // 변수명을 통해 Property를 반환

			IProperty* GetFProperty(const std::string& name) const; // 변수명을 통해 Property를 반환

			void SetFProperty(const std::string& name, const std::string& value); // 변수명을 통해 Property에 값을 삽입

			#pragma endregion

			#pragma region FFUNCTION
			template <typename T, typename R, typename... Args>
			void AddFDelegate(R(T::* mtd)(Args ...), const std::string& name);

			template <typename R, typename... Args>
			R Invoke(const std::string& name,Args... args);
			#pragma endregion

			static void Destroy(BaseObject* object, float delay = 0.0f); // 개체를 삭제

			template <typename T> requires DerivedFromBaseObject
				static T* Instantiate(const T* target); // 개체를 복제

			static void DontDestroyOnLoad(BaseObject* target);// 씬이 로드될때 개체를 삭제하지 않음

			template <typename T> requires DerivedFromBaseObject
				static T* FindObjectOfType(); // 현재 로드된 개체 중 가장 처음 나오는 T type의 BaseObject를 반환

			template <typename T> requires DerivedFromBaseObject
				static std::vector<T*> FindObjectsOfType(); // 현재 로드된 개체 중 모든 T type의 BaseObject를 반환

			static BaseObject* FindObjectByInstanceID(const std::string& id);

		public:
			std::vector<IProperty*> fproperties;
			std::unordered_map<std::string, IDelegate*> fdelegates;

		protected:
			std::string name;
			std::string id;

		private:
			static std::unordered_map<std::string, BaseObject*> s_baseObjects;
		};


		template <typename T>
		void BaseObject::AddFProperty(const T& value, const  std::string& name)
		{
			fproperties.push_back(new FProperty<T>(value, name));
		}


		template <typename T,typename R,typename... Args>
		void BaseObject::AddFDelegate(R(T::* mtd)(Args ...), const std::string& name)
		{
			fdelegates.insert(std::make_pair(name, new flt::engine::FDelegate<R, Args>(mtd)));
		}

		template <typename R, typename ... Args>
		R BaseObject::Invoke(const std::string& name, Args... args)
		{
			return fdelegates[name]->Invoke<R, Args...>(args...);
		}

		template <typename T> requires DerivedFromBaseObject
			T* BaseObject::Instantiate(const T* target)
		{
			BaseObject* original = static_cast<Component*>(target)->gameObject;
			GameObject* instance = GameObjectManager::Create("", original->GetInstanceID());//*수정필요 : ID
			GameObjectManager::Adapt(instance); //Component 연결
			GameObjectManager::Build(instance); //Component FProperty 구축
			GameObjectManager::Load(instance); //씬에 올리기
			return instance;
		}

		template <typename T> requires DerivedFromBaseObject
			T* BaseObject::FindObjectOfType()
		{
			for (auto element : s_baseObjects)
			{
				T* castedElement = dynamic_cast<T*>(element);
				if (castedElement != nullptr)
				{
					return castedElement;
				}
			}
			return nullptr;
		}

		template <typename T> requires DerivedFromBaseObject
			std::vector<T*> BaseObject::FindObjectsOfType()
		{
			std::vector<T*> result;
			for (auto element : s_baseObjects)
			{
				T* castedElement = dynamic_cast<T>(element);
				if (castedElement != nullptr)
				{
					result.push_back(castedElement);
				}
			}
			return result;
		}

		template<>
		inline void FProperty<BaseObject*>::SetValue(std::string id)
		{
			value = BaseObject::FindObjectByInstanceID(id);
		}

		template<>
		inline std::string FProperty<BaseObject*>::GetValue()
		{
			return value->GetInstanceID();
		}
	}
}
