#pragma once
#include "../Base/Base.h"

class TutorialBlock :public Base {
	int x = 0;
	CImage Rimg;
	CImage Limg;
	CImage Uimg;
	CImage Downimg;
	CImage Rwimg;
private:
	CFont m_Tutorial_text;
public:
	TutorialBlock();
	void Update();
	void Draw();
};