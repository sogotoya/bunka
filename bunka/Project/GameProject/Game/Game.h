#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	//Game�N���A�摜
	CImage clearimg;
	bool drawclear;
	//�Q�[���I�[�o�[�摜
	CImage outimg;
	//�X�e�[�W1�N���A�摜
	CImage clear_one;
	//�X�e�[�W�Q�N���A�摜
	CImage clear_two;
	//���g���C�摜
	CImage retryimg;
	bool drawretry;
	//�c�@
	CImage zankiimg[3];
	//�X�e�[�W�N���A��ʕ`��
	bool drawone;
	//�ꎞ��~�摜
	CImage stopimg;
	//�X�L�b�v
	CImage skipimg;
	//stage7��Goal�B���摜
	CImage m_kakusu;
	//Goal�̃f�R�C
	CImage m_Goal1;
	CImage m_Goal2;
	CImage m_Goal3;
public:
	Game();
	void Update();
	void Draw();
};