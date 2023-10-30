#pragma once
#include <string>
#include <iostream>
#include "ResourceMgr.h"

namespace flt
{
	struct IBuilderBase;
	template<typename T> struct IBuilder;


	struct ResourceBase
	{
		friend class ResourceMgr;

		ResourceBase(ResourceMgr& resourceMgr, const IBuilderBase& builder);

		virtual ~ResourceBase()
		{
		}

	protected:
		std::wstring _key;
		void* _data;
		ResourceMgr& _resourceMgr;
	};

	template<typename Derived>
	struct Resource : ResourceBase
	{
	public:
		Resource(const typename IBuilder<Derived>& builder) : ResourceBase(builder) {}

		void Release()
		{
			if (_data)
			{
				if (_resourceMgr.ReleaseResource(this))
				{
					((Derived*)_data)->Release();
				}
				_data = nullptr;
			}
		}

		operator Derived* () const
		{
			return (Derived*)_data;
		}
	};
}
