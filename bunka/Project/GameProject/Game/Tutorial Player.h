#pragma once
#include "../Base/Base.h"

class TutorialPlayer :public Base {
	int Step = 0;
	CImage dimg;
	CImage aimg;
	CImage simg;
	CImage wimg;
	CImage Swimg;
private:
	CFont m_Tutorial_text;
public:
	TutorialPlayer();
	void Update();
	void Draw();
	//�`���[�g���A���̐i�s�x
	int TutorialProgress=0;
	//�{�^���������ꂽ���ǂ���
	bool Is_Holded = false;
};