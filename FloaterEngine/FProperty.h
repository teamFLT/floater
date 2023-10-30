#pragma once
#include <string>

#include "Define.h"
#include "IProperty.h"

namespace flt
{
	namespace engine
	{
        template <typename T>
		class FProperty : public IProperty
		{
        public:
            FProperty(T& x, std::string name);
            
            void SetValue(std::string value) override;

            std::string GetValue() override;

            std::string GetType() override;

            std::string GetName() override;

        public:
            T& value;
            std::string name;

		};

        template <typename T>
        FProperty<T>::FProperty(T& x, std::string name):
		value(x),
		name(name) {}

        template <typename T>
        void FProperty<T>::SetValue(std::string p_value)
        {
	        std::istringstream ss(p_value);
	        ss >> value;
        }

        template <typename T>
        std::string FProperty<T>::GetValue()
        {
	        std::ostringstream ss;
	        ss << value;
	        return ss.str();
        }

        template <typename T>
        std::string FProperty<T>::GetType()
        {
	        return typeid(decltype(value)).name();
        }

        template <typename T>
        std::string FProperty<T>::GetName()
        {
	        return name;
        }
	}
}
