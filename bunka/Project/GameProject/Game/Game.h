#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	//Game�N���A�摜
	CImage clearimg;
	bool drawclear;

	//�X�e�[�W1�N���A�摜
	CImage clear_one;
	bool drawone;
	//�X�e�[�W�Q�N���A�摜
	CImage clear_two;
	bool drawtwo;
	//���g���C�摜
	CImage retryimg;
	bool drawretry;

public:
	Game();
	void Update();
	void Draw();
};