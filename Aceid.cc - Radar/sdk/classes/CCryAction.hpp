#pragma once

#ifndef CCRYACTION_HPP
#define CCRYACTION_HPP

#include "CActorSystem.hpp"
#include "CGameRules.hpp"
#include "../interfaces/IGameFrameworkListener.hpp"

class CCryAction {
public:

	CActorSystem* GetActorSystem() {
		return __vtbl< CActorSystem* >(this, 25);
	}

	void RegisterListener(IGameFrameworkListener* pGameFrameworkListener, const char* name,
		EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority) {
		__vtbl< void >(this, 108, pGameFrameworkListener, name, eFrameworkListenerPriority);
	}

	CGameRules* GetGameRules() {
		return __vtbl< CGameRules* >(this, 137);
	}

	char GetClientActorInternal(CPlayer** pOutActor) {
		return __vtbl< char >(this, 142, pOutActor);
	}

public:

	static CCryAction* Singleton() {
		return *reinterpret_cast< CCryAction** >(0x14218B408);
	}
};

#endif // !CCRYACTION_HPP