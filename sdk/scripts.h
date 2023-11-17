#pragma once

#include "../includes.h"

struct ExternalBuffer {
	uintptr_t m_buffer;
	uintptr_t m_size;
};

struct ScriptFunction {
	const char* m_name;
	const char* m_scriptName;
	const char* m_description;
	int m_qword18;
	void* m_qword20;
	bool m_gap28;
	bool m_byte29;
	int m_dword2C;
	void* m_qword30;
	int m_dword38;
	int m_dword3C;
	ExternalBuffer* m_qword40; // holds n * 4 bits
	void* m_n; // 0x48
	void* m_qword50;
	int m_dword58;
	int m_dword5C;
	void* m_function;
}; // 0x68

static_assert(sizeof(ScriptFunction) == 0x68);

namespace Scripts {
}