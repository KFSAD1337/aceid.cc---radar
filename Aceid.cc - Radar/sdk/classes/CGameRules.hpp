#pragma once

#ifndef CGAMERULES_HPP
#define CGAMERULES_HPP

#include "../helpers/helpers.hpp"
#include "CFeedbackSystem.hpp"

class CGameRules {
public:

	int GetTeam(EntityId entityId) {
		return __vtbl< int >(this, 112, entityId); 
	}

	bool GetTeam(EntityId m_shooterId, EntityId m_targetId) {
		return this->GetTeam(m_shooterId) != this->GetTeam(m_targetId)
			|| this->GetTeam(m_shooterId) == 0;
	}

public:

	std::byte m_padding[0x300];
	CFeedbackSystem* m_pFeedbackSystem;
};

#endif // !CGAMERULES_HPP