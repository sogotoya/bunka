#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	CImage m_ing;
public:
	Game();
	void Update();
};