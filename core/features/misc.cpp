#include "misc.h"

void Misc::OnCreateMove(CUserCmd* cmd)
{
	if (inSpeedhack)
		*(float*)((uintptr_t)cmd + 0xAC) += 0.025f;

	if (inAirstuck)
		cmd->m_commandNumber = INT_MAX;
}