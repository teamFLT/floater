#pragma once
#include <d3d11.h>
#include "CommonMath.h"
#include "../FloaterRendererCommon/include/IBuilder.h"
#include "../FloaterRendererCommon/include/Resource.h"

namespace flt
{
	struct Vertex
	{
		using type = struct
		{
			Vector3f Pos;
			Vector2f Tex;
			Vector3f Normal;
		};

		static constexpr unsigned int numElements = 3;
		static constexpr D3D11_INPUT_ELEMENT_DESC layout[numElements] =
		{
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(type, Pos), D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, offsetof(type, Tex), D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, offsetof(type, Normal), D3D11_INPUT_PER_VERTEX_DATA, 0}
		};
	};

	struct Mesh
	{
		ID3D11ShaderResourceView* texture;
		ID3D11SamplerState* sampler;


		ID3D11Buffer* vertexBuffer;
		size_t singleVertexSize;
		ID3D11Buffer* indexBuffer;
		size_t indexCount;
	};

	template struct Resource<Mesh>;

	struct MeshBuilder : public IBuilder<Mesh>
	{
		MeshBuilder(const std::wstring name) : IBuilder<Mesh>(name), pDevice(nullptr) {}

		virtual void* build(ResourceMgr& _resourceMgr) const override;

		ID3D11Device* pDevice;
	};
}
