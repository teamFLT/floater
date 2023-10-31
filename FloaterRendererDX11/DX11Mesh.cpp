#include "DX11Mesh.h"

flt::DX11Mesh* flt::MeshBuilder::build() const 
{
	return nullptr;
}

void flt::DX11Mesh::Release()
{
	vertexBuffer->Release();
	indexBuffer->Release();
	texture->Release();
	sampler->Release();
}
