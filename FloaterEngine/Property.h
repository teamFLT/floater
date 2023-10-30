#pragma once
#include <string>

#include "Define.h"
#include "IProperty.h"

namespace flt
{
	namespace engine
	{
        template <typename T>
		class Property : public IProperty
		{
        public:

            Property(T& x, std::string p_name);
            
            void SetValue(std::string p_value) override;

            std::string GetValue() override;

            std::string GetType() override;

            std::string GetName() override;

        public:
            T& value;
            std::string name;

		};

        template <typename T>
        Property<T>::Property(T& x, std::string p_name): value(x)
        {
	        name = p_name;
        }

        template <typename T>
        void Property<T>::SetValue(std::string p_value)
        {
	        std::istringstream ss(p_value);
	        ss >> value;
        }

        template <typename T>
        std::string Property<T>::GetValue()
        {
	        std::ostringstream ss;
	        ss << value;
	        return ss.str();
        }

        template <typename T>
        std::string Property<T>::GetType()
        {
	        return typeid(decltype(value)).name();
        }

        template <typename T>
        std::string Property<T>::GetName()
        {
	        return name;
        }
	}
}
