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

		ResourceBase(const ResourceBase& other) = delete;

		ResourceBase(ResourceBase&& other) noexcept : 
			_resourceMgr(other._resourceMgr), 
			_data(other._data), 
			_key(other._key)
		{
			other._data = nullptr;
		}

		ResourceBase(ResourceMgr& resourceMgr, const IBuilderBase& builder)	: 
			_resourceMgr(resourceMgr),
			_key(),
			_data(nullptr)
		{
			_data = _resourceMgr.GetResource(this, builder);
		}


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
		Resource(ResourceMgr& resourceMgr, const typename IBuilder<Derived>& builder) : ResourceBase(resourceMgr, builder) {}
		Resource(const Resource& other) = delete;
		Resource(Resource&& other) = default;
		virtual ~Resource()
		{
			Release();
		}

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
