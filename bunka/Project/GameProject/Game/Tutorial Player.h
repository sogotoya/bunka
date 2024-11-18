#pragma once
#include "../Base/Base.h"

class TutorialPlayer :public Base {
	int Step = 0;
	int Jump = 0;
	CImage simg;
	CImage dimg;
	CImage aimg;
private:
	CFont m_Tutorial_text;
public:
	TutorialPlayer();
	void Update();
	void Draw();
};