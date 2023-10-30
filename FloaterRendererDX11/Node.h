#pragma once
#include "../FloaterRendererCommon/include/Transform.h"
#include "../FloaterRendererCommon/include/Camera.h"
#include "Mesh.h"

#include <string>
#include <map>

namespace flt
{
	struct Node
	{
		Node(Transform& transform);

		std::wstring name;
		Transform& transform;
		Mesh* mesh;
		Camera* camera;

		int boneIndex;

		std::multimap<std::wstring, Node*> children;
	};
}
