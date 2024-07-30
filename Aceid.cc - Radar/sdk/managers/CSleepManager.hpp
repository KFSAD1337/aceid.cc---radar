#pragma once

#ifndef CSLEEPMANAGER_HPP
#define CSLEEPMANAGER_HPP

#include <time.h>

class CSleepManager {
public:

	bool join(int coldown) {

		if (!this->m_state) {

			this->m_seconds = static_cast<float>(clock());
			this->m_seconds += coldown;

			this->m_state = true;
		}

		if ((static_cast<float>(clock())) >= this->m_seconds) {

			this->m_state = false;
			return true;
		}

		return false;
	}

private:
	bool m_state;
	float m_seconds;
};

#endif // !CSLEEPMANAGER_HPP