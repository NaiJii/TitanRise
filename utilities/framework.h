#pragma once

#include "../includes.h"
#include "../core/render.h"

namespace Menu {
	inline int m_cursor = 0;
	inline int m_itemIndex = 0;
	inline Point_t m_pos = Point_t(0, 0);
	inline const Color_t m_activeColor = Color_t(55, 200, 70, 255);

	bool Begin(std::string_view title, Point_t pos, Color_t accentColor, Color_t textColor, int key, bool* open);

	void Toggle(std::string_view title, bool& state);
	void Colorpicker(std::string_view title, Color_t& clr);
	void Int(std::string_view title, int& state, int min, int max, int step = 1);
}
