#pragma once
#include "../Base/Base.h"

class Game :public Base {
private:
	//Gameクリア画像
	CImage clearimg;
	bool drawclear;
	//ゲームオーバー画像
	CImage outimg;
	//ステージ1クリア画像
	CImage clear_one;
	bool drawone;
	//ステージ２クリア画像
	CImage clear_two;
	bool drawtwo;
	//リトライ画像
	CImage retryimg;
	bool drawretry;
	//残機
	CImage zankiimg[ 3];
public:
	Game();
	void Update();
	void Draw();
};