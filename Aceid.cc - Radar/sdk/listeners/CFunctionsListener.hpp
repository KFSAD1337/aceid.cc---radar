#pragma once

#ifndef CFUNCTIONSLISTENER_HPP
#define CFUNCTIONSLISTENER_HPP

#include "../classes/CCryAction.hpp"
#include "../managers/CSleepManager.hpp"

class CFunctionsListener 
	: public IGameFrameworkListener {
public:

	CFunctionsListener(CCryAction* m_pCryAction) 
		: m_pCryAction(m_pCryAction) { 

		this->m_pSleepManager = new CSleepManager();
	}

	~CFunctionsListener() { }

public:

	struct SPlayerId {

		SPlayerId(EntityId m_entityId) 
			: m_entityId(m_entityId) { }

		EntityId m_entityId;
	};

	std::vector< SPlayerId > m_players;

public:

	void OnPostUpdate(float fDeltaTime) {

		if (this->m_players.empty() == false)
			this->m_players.clear();

		if (this->m_pCryAction == nullptr)
			return;

		CPlayer* m_pShooter = nullptr;
		if (!this->m_pCryAction->GetClientActorInternal(&m_pShooter))
			return;

		CActorSystem* m_pActorSystem = this->m_pCryAction->GetActorSystem();
		if (m_pActorSystem == nullptr) return;

		CFeedbackSystem* m_pFeedbackSystem = this->m_pCryAction->GetGameRules()->m_pFeedbackSystem;
		if (m_pFeedbackSystem == nullptr) return;

		if (this->m_pSleepManager->join(3000)) {

			for (auto it = m_pFeedbackSystem->m_markerInstances.begin();
				it != m_pFeedbackSystem->m_markerInstances.end(); it++) {

				if (it->HUDBadgeID != 0) continue;
				if (it->HUDTextLabelID != 0) continue;
				if (it->HUDStatusInfoID != 0) continue;

				m_pFeedbackSystem->RemoveMarker(it->RadarIconID);
				m_pFeedbackSystem->RemoveMarker(it->MinimapIconID);
			}

			SMarkerParams m_params;

			for (auto it = m_pActorSystem->m_actors.begin();
				it != m_pActorSystem->m_actors.end(); it++) {

				if (it->second == nullptr) continue;
				if (it->second == m_pShooter) continue;
				if (it->second->IsDead()) continue;
				if (!this->m_pCryAction->GetGameRules()->GetTeam(m_pShooter->m_entityId, it->first)) continue;

				m_params.m_entity = it->first;
				m_pFeedbackSystem->AddMarker("enemy_is_visible", &m_params);
			}
		}
	}

private:
	CCryAction* m_pCryAction;
	CSleepManager* m_pSleepManager;
};

#endif // !CFUNCTIONSLISTENER_HPP