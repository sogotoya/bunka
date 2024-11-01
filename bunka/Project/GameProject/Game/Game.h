#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	CImage clearimg;
	bool drawclear;
	CImage retryimg;
	bool drawretry;
	CImage stage1goal;
	bool draw1goal;
	
public:
	Game();
	void Update();
	void Draw();
};