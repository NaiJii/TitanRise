#include "render.h"

bool Render::Setup()
{
	m_ui = SDK::m_vguiSurface->CreateFont_();
	if (!SDK::m_vguiSurface->SetFontGlyphSet(m_ui, "Tahoma", 14, 600, 0, 0, FONTFLAG_OUTLINE))
		return false;

	m_watermark = SDK::m_vguiSurface->CreateFont_();
	if (!SDK::m_vguiSurface->SetFontGlyphSet(m_watermark, "Tahoma", 18, 800, 0, 0, FONTFLAG_ADDITIVE | FONTFLAG_DROPSHADOW))
		return false;

	m_warning = SDK::m_vguiSurface->CreateFont_();
	if (!SDK::m_vguiSurface->SetFontGlyphSet(m_warning, "Tahoma", 24, 800, 0, 0, FONTFLAG_OUTLINE))
		return false;

	return true;
}

void Render::Rectangle(int x, int y, int w, int h, Color_t color)
{
	SDK::m_vguiSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	SDK::m_vguiSurface->DrawRect(x, y, x + w, y + h);
}

void Render::FilledRectangle(int x, int y, int w, int h, Color_t color)
{
	SDK::m_vguiSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	SDK::m_vguiSurface->DrawFilledRect(x, y, x + w, y + h);
}

void Render::Line(int x, int y, int x2, int y2, Color_t color)
{
	SDK::m_vguiSurface->DrawSetColor(color.r, color.g, color.b, color.a);
	SDK::m_vguiSurface->DrawLine(x, y, x2, y2);
}

Point_t Render::Text(std::string_view str, int x, int y, ETextAlignment alignment, Font font, Color_t color)
{
	SDK::m_vguiSurface->DrawSetTextFont(font);
	SDK::m_vguiSurface->DrawSetTextColor(color.r, color.g, color.b, color.a);

	std::wstring wstr(str.begin(), str.end());
	Point_t size;
	SDK::m_vguiSurface->GetTextSize(font, wstr.data(), &size.x, &size.y);

	// 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 30 49 8B D9 49 8B F8

	if (alignment & DEFAULT) {
		SDK::m_vguiSurface->DrawSetTextPos(x, y);
		SDK::m_vguiSurface->DrawPrintText(wstr.data(), (int)wstr.length());
		return size;
	}

	if (alignment & VERTICAL_TOP)
		y -= size.y;
	else if (alignment & VERTICAL_CENTER)
		y -= size.y / 2;

	if (alignment & HORIZONTAL_LEFT)
		x -= size.x;
	else if (alignment & HORIZONTAL_CENTER)
		x -= size.x / 2;

	SDK::m_vguiSurface->DrawSetTextPos(x, y);
	SDK::m_vguiSurface->DrawPrintText(wstr.data(), (int)wstr.length());
	return size;
}

Point_t Render::GetTextSize(std::string_view str, Font font)
{
	Point_t size;
	std::wstring wstr(str.begin(), str.end());
	SDK::m_vguiSurface->GetTextSize(font, wstr.data(), &size.x, &size.y);
	return size;
}