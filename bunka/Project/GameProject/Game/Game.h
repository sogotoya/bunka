#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	//Gameクリア画像
	CImage clearimg;
	bool drawclear;

	//ステージ1クリア画像
	CImage clear_one;

	//ステージ２クリア画像
	CImage clear_two;

	//リトライ画像
	CImage retryimg;
	bool drawretry;

public:
	Game();
	void Update();
	void Draw();
};