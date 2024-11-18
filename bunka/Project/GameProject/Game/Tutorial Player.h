#pragma once
#include "../Base/Base.h"

class TutorialPlayer :public Base {
	int Step = 0;
	CImage dimg;
	CImage aimg;
public:
	TutorialPlayer();
	void Update();
	void Draw();
};