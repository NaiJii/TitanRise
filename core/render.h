#pragma once

#include "../sdk/sdk.h"

enum ETextAlignment : uint32_t {
	DEFAULT = (1 << 0),
	VERTICAL_TOP = (1 << 1),
	VERTICAL_BOTTOM = (1 << 2),
	VERTICAL_CENTER = (1 << 3),
	HORIZONTAL_LEFT = (1 << 4),
	HORIZONTAL_RIGHT = (1 << 5),
	HORIZONTAL_CENTER = (1 << 6),
};

namespace Render {
	bool Setup();
	void Rectangle(int x, int y, int w, int h, Color_t color);
	void FilledRectangle(int x, int y, int w, int h, Color_t color);
	void Line(int x, int y, int x2, int y2, Color_t color);
	Point_t Text(std::string_view str, int x, int y, ETextAlignment alignment, Font font, Color_t color);
	Point_t GetTextSize(std::string_view str, Font font);

	inline Font m_ui, m_watermark, m_warning;
}
