#pragma once

#ifndef CACTORSYSTEM_HPP
#define CACTORSYSTEM_HPP

#include "CPlayer.hpp"

class CActorSystem {
public:

	class CActorIterator {
	public:
		virtual void Function0(); 
		virtual CPlayer* Next(); 
		virtual void AddRef(); 
		virtual unsigned __int64 Count(); 
		virtual void Release(); 
	}; 

	struct DemoSpectatorSystem {

		unsigned int m_originalActor;
		unsigned int m_currentActor;
	};

public:

	void CreateActorIteratorInternal(CActorIterator** pOutIter) {
		__vtbl< void >(this, 18, pOutIter); 
	}

public:
	char padding[0x10];
	DemoSpectatorSystem m_demoSpectatorSystem;
	unsigned int m_demoPlaybackMappedOriginalServerPlayer;
	void* m_pSystem;
	void* m_pEntitySystem;
	std::map< EntityId, CPlayer*, std::less< EntityId >, std::allocator< std::pair< EntityId const, CPlayer* > > > m_actors;
};

#endif // !CACTORSYSTEM_HPP