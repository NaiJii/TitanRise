#pragma once

struct VMatrix;

struct CViewRender {
	VCALL(VMatrix*, GetWorldToScreenMatrix, 14, (char i = 0), (this, i));
	VCALL(bool, HasWorldToScreenMatrix, 15, (char i = 0), (this, i));
};