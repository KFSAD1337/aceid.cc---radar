#pragma once

#ifndef IGAMEFRAMEWORKLISTENER_HPP
#define IGAMEFRAMEWORKLISTENER_HPP

enum EFRAMEWORKLISTENERPRIORITY {

	FRAMEWORKLISTENERPRIORITY_DEFAULT,
	FRAMEWORKLISTENERPRIORITY_GAME,
	FRAMEWORKLISTENERPRIORITY_HUD,
	FRAMEWORKLISTENERPRIORITY_MENU
};

interface IGameFrameworkListener {
public:
	virtual void Function0() { };
	virtual void OnPostUpdate(float fDeltaTime) { };
	virtual void OnSaveGame(__interface ISaveGame* pSaveGame) { };
	virtual void OnLoadGame(__interface ILoadGame* pLoadGame) { };
	virtual void OnLevelEnd(const char* nextLevel) { };
	virtual void OnActionEvent(const struct SActionEvent& event) { };
	virtual void OnPreRender() { };
};

#endif // !IGAMEFRAMEWORKLISTENER_HPP