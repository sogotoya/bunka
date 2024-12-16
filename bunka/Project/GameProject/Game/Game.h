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
	//ステージ２クリア画像
	CImage clear_two;
	//リトライ画像
	CImage retryimg;
	bool drawretry;
	//残機
	CImage zankiimg[3];
	//ステージクリア画面描画
	bool drawone;
	//一時停止画像
	CImage stopimg;
	//スキップ
	CImage skipimg;
	//stage7のGoal隠す画像
	CImage m_kakusu;
public:
	Game();
	void Update();
	void Draw();
};