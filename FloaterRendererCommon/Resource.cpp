#include "./include/Resource.h"

flt::ResourceBase::ResourceBase(ResourceMgr& resourceMgr, const IBuilderBase& builder)
	: _resourceMgr(resourceMgr)
{
	_data = _resourceMgr.GetResource(this, builder);
}

