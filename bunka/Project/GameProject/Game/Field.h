#pragma once
#include "../Base/Base.h"

class Field : public Base {
private:


	CImage m_haikei;
	CImage m_yuugata;
	CImage m_yuugatakumo;
	CImage m_murasaki;
	CImage m_murasakikumo;
	static float m_ground_y;
public:
	Field();
	void Draw();
	static float GetGroundY() {
		return m_ground_y;
	}
};