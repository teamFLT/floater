#pragma once
#include <vector>
#include "BaseObject.h"

namespace flt
{
	namespace engine
	{
		class Transform;
		class Component;

		template <class T>
		concept DerivedFromComponent = std::is_base_of_v<Component, T>;

		class Component : public BaseObject
		{
		public:
			Component(GameObject* gameObject, std::string id, std::string name);
			~Component() override;

			void SendMessage(std::string message);
			void BroadcastMessage(std::string message);
			void SendMessageUpward(std::string message);

			template <typename T, typename... Types>
			void SendMessage(const std::string& message, T arg, Types... args);

			template <typename T, typename... Types>
			void BroadcastMessage(const std::string& message, T arg, Types... args);

			template <typename T, typename... Types>
			void SendMessageUpward(const std::string& message, T arg, Types... args);

			template<typename T> requires DerivedFromComponent
			T* GetComponent();

			template<typename T> requires DerivedFromComponent
			bool TryGetComponent(T* component);

			template<typename T> requires DerivedFromComponent
			T* GetComponentInChildren();

			template<typename T> requires DerivedFromComponent
			std::vector<T*> GetComponentsInChildren();

			template<typename T> requires DerivedFromComponent
			T* GetComponentInParent();

			template<typename T> requires DerivedFromComponent
			std::vector<T*> GetComponentsInParent();

		public:
			GameObject* gameObject;
			Transform* transform;
			std::string tag;

		private:
			std::vector<Component*>& _components;

		};


		template <typename T, typename ... Types>
		void Component::SendMessage(const std::string& message, T arg, Types... args)
		{
		}

		template <typename T, typename ... Types>
		void Component::BroadcastMessage(const std::string& message, T arg, Types... args)
		{
		}

		template <typename T, typename ... Types>
		void Component::SendMessageUpward(const std::string& message, T arg, Types... args)
		{
		}

		template <typename T> requires DerivedFromComponent
		T* Component::GetComponent()
		{

		}

		template <typename T> requires DerivedFromComponent
		bool Component::TryGetComponent(T* component)
		{

		}

		template <typename T> requires DerivedFromComponent
		T* Component::GetComponentInChildren()
		{
		}

		template <typename T> requires DerivedFromComponent
		std::vector<T*> Component::GetComponentsInChildren()
		{
		}

		template <typename T> requires DerivedFromComponent
		T* Component::GetComponentInParent()
		{
		}

		template <typename T> requires DerivedFromComponent
		std::vector<T*> Component::GetComponentsInParent()
		{
		}
	}
}
