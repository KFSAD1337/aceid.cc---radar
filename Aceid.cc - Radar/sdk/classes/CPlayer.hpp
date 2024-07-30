#pragma once

#ifndef CPLAYER_HPP
#define CPLAYER_HPP

#include "../helpers/helpers.hpp"

class CPlayer {
public:

	int GetHealth() {
		return __vtbl< int >(this, 27); 
	}

	bool IsDead() {
		return this->GetHealth() <= 0;
	}

public:

	std::byte m_padding[0x20];
	EntityId m_entityId;
};

#endif // !CPLAYER_HPP