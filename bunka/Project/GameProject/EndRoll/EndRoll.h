#pragma once
#include "../Base/Base.h"
class EndRoll :public Base {
private:

	//�G���h���[�������~����X�s�[�h
	const float EndRoll_Speed = 1;

	//�摜
	CImage endimg;

public:
	EndRoll(const CVector2D& p);
	void Update();
	void Draw();
};