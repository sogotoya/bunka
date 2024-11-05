#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	//Gameクリア画像
	CImage clearimg;
	bool drawclear;

	//ステージ1クリア画像
	CImage clear_one;
	bool drawone;
	//ステージ２クリア画像
	CImage clear_two;
	bool drawtwo;
	//リトライ画像
	CImage retryimg;
	bool drawretry;

public:
	Game();
	void Update();
	void Draw();
};