#pragma once

#include <cstdint>

using Font = uint32_t;

enum EFontFlags {
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,		// custom generated font - never fall back to asian compatibility mode
	FONTFLAG_BITMAP = 0x800,		// compiled bitmap font - no fallbacks
};

enum EFontDrawType : int {
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,
	FONT_DRAW_TYPE_COUNT = 2,
};

struct CSurface {
	VCALL(void, DrawSetColor, 14, (int r, int g, int b, int a), (this, r, g, b, a));
	VCALL(void, DrawFilledRect, 16, (int x, int y, int x0, int y0), (this, x, y, x0, y0));
	VCALL(void, DrawRect, 19, (int x, int y, int x0, int y0), (this, x, y, x0, y0));
	VCALL(void, DrawLine, 20, (int x, int y, int x0, int y0), (this, x, y, x0, y0));
	VCALL(void, DrawSetTextFont, 22, (Font font), (this, font));
	VCALL(void, DrawSetTextColor, 25, (int r, int g, int b, int a), (this, r, g, b, a));
	VCALL(void, DrawSetTextPos, 26, (int x, int y), (this, x, y));
	VCALL(void, DrawPrintText, 28, (const wchar_t* text, int text_lenght, EFontDrawType draw_type = FONT_DRAW_DEFAULT), (this, text, text_lenght, std::to_underlying(draw_type)));
	VCALL(void, GetScreenSize, 48, (int* x, int* y), (this, x, y));
	VCALL(Font, CreateFont_, 78, (), (this));
	VCALL(bool, SetFontGlyphSet, 79, (Font font, const char* windows_font_name, int tall, int weight, int blur, int scanlines, int flags, int range_min = 0, int range_max = 0), (this, font, windows_font_name, tall, weight, blur, scanlines, flags, range_min, range_max));
	VCALL(void, GetTextSize, 86, (Font font, const wchar_t* text, int* w, int* h), (this, font, text, w, h));
};
