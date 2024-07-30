#include "stdafx.hpp"

int __stdcall DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {	
	
	if (fdwReason == DLL_PROCESS_ATTACH) {

		CCryAction* m_pCryAction = CCryAction::Singleton();
		if (m_pCryAction == nullptr) 
			MessageBox(0, L"Fatal error, CCryAction is nullptr!", L"Error", MB_OK);
		
		m_pCryAction->RegisterListener(new CFunctionsListener(m_pCryAction), 0, EFRAMEWORKLISTENERPRIORITY::FRAMEWORKLISTENERPRIORITY_GAME);
	}

	return 1;
}