#pragma once
#include <string>
#include "../../FloaterUtil/include/ConvString.h"

namespace flt
{
	class ResourceMgr;

	struct IBuilderBase
	{
		IBuilderBase(const std::wstring& key) : key(key) {}
		virtual void* operator()(std::wstring* typeName, ResourceMgr& _resourceMgr) const = 0;
		std::wstring key;
	};

	template<typename Derived>
	struct IBuilder : public IBuilderBase
	{
		using type = Derived;

		IBuilder(const std::wstring& key) : IBuilderBase(key) {}
		virtual void* operator()(std::wstring* typeName, ResourceMgr& _resourceMgr) const final
		{
			*typeName = convToWstring(typeid(Derived).name());

			return build(_resourceMgr);
		}

		virtual void* build(ResourceMgr& _resourceMgr) const = 0;
	};
}
