#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	CImage m_img;
public:
	Game();
	void Update();
};