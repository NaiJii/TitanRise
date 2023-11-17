#pragma once

struct StudioHdr_t;

struct CModelInfo {
	VCALL(StudioHdr_t*, GetStudioModel, 28, (const void* model), (this, model));
};