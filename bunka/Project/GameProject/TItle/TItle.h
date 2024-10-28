#pragma once
#include "../Base/Base.h"

class Title : public Base {
	CImage m_img;
	CFont m_title_text;
	int m_cnt;
public:
	Title();
	void Update();
	void Draw();
};