#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BlockManager.h"
#include "Goal.h"
#include "GameData.h"
#include "count.h"
#include "TItle/TItle.h"

Game::Game()
	:Base(eType_Scene)
{
	Base::Add(new Player(CVector2D(200, 900), true));
	Base::Add(new Map(1));
	Base::Add(new BlockManager());
	Base::Add(new Goal(CVector2D(1740, 613)));
	Base::Add(new count(CVector2D(500, 0)));
	//ヘッダーで作ったCImageに、COPY_RESOURCEで画像をセット
	retryimg = COPY_RESOURCE("Retry", CImage);
	clearimg = COPY_RESOURCE("GameClear", CImage);
	outimg = COPY_RESOURCE("GameOver", CImage);
	clear_one = COPY_RESOURCE("stage1goal",CImage);
	clear_two = COPY_RESOURCE("stage2goal", CImage);
	zankiimg[0] = COPY_RESOURCE("zanki", CImage);
	zankiimg [1] = COPY_RESOURCE("zanki2", CImage);
	zankiimg[2] = COPY_RESOURCE("zanki3", CImage);
	drawclear = false;
	drawretry = false;
	drawone = false;
	drawtwo = false;
	for(int i=0;i<3;i++)
	zankiimg[i].SetSize(75, 75);

}

void Game::Update()
{
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if(g->GetGoal())
		{
			//ステージが３だった場合
			if (GameData::s_score==3)
			{
				drawclear = true;
				GameData::clear = true;
				if (PUSH(CInput::eButton1))
				{
					Base::KillAll();
					Base::Add(new TItle());
					GameData::s_score = 1;
					GameData::zanki=3;
					GameData::Gameclear = false;
					
				}
				
			}
			else{
				
				GameData::Gameclear = true;
			
			}
				
			
		}
	}
	if (!Base::FindObject(eType_Player))
	{
		//残機がまだあれば描画できる
		if(GameData::zanki!=0)
			drawretry = true;
		
		if (PUSH(CInput::eButton1))
		{
			Base::Kill(1 << eType_count);
			Base::Add(new count(CVector2D(500, 0)));
			//プレイヤーの各ステージの出現位置
			if (GameData::s_score == 1)
			{
				Base::Add(new Player(CVector2D(200, 900), true));
			}
			if (GameData::s_score == 2)
			{
				Base::Add(new Player(CVector2D(1800, 900), true));
			}
			if (GameData::s_score == 3) 
			{
				Base::Add(new Player(CVector2D(1800, 900), true));
			}
		}
	}

	if (GameData::Gameclear)
	{
		if (GameData::s_score == 1)
		{
			drawone = true;
			
		}
		if (GameData::s_score == 2)
		{
			drawtwo = true;
		}
		
		//eButton1で次のマップへ
		if (PUSH(CInput::eButton1))
		{
			Base::Kill(1 << eType_Map
				| 1 << eType_AreaChange
				| 1 << eType_Goal
				| 1 << eType_count
				| 1 << eType_Block);
			if (GameData::s_score <= 2)
			{
				Base::Kill(1 << eType_Player);
			}

			GameData::s_score++;
			GameData::Gameclear = false;
			Base::Add(new Map(GameData::s_score));

			Base::Add(new count(CVector2D(500, 0)));
		}
		//マップ２のPlayerの出現位置
		if (GameData::s_score == 2)
		{
			Base::Add(new Player(CVector2D(1800, 900), true));
		}
		//マップ３のPlayerの出現位置
		if (GameData::s_score == 3)
		{
			Base::Add(new Player(CVector2D(1800, 900), true));
		}
		
	}
		
}

void Game::Draw()
{
	//残機描画
	for (int i = 0; i < GameData::zanki; i++)
	{ 
		zankiimg[i].SetPos(10+80*i, 10);
		zankiimg[i].Draw();
	}
	
	
	//上に画像が被らないように
	//最後	のステージクリア画面描画
	if (drawclear)
	{
		clearimg.SetSize(1550,745);
		clearimg.SetCenter(50,100);
		clearimg.SetPos(230,240);
		clearimg.Draw();
	}
	//リトライ画面描画
	if(drawretry)
	{
		if(!drawclear)
		{ 
			retryimg.Draw();
			drawretry = false;
		}
	}
	//ステージ1クリア画面描画
	if (drawone)
	{
		clear_one.Draw();
		drawone = false;
	}
	//ステージ2クリア画面描画
	if (drawtwo)
	{
		clear_two.Draw();
		drawtwo = false;
	}
	//ゲームオーバー関連
	if (GameData::Gameover)
	{
		Base::Kill(1 << eType_AreaChange
			| 1 << eType_Goal
			| 1 << eType_Block);
		outimg.SetSize(1000, 700);
		outimg.SetPos(440, 200);
		outimg.Draw();
		if (PUSH(CInput::eButton1))
		{
			Base::KillAll();
		

			Base::Add(new TItle());
			GameData::s_score = 1;
			GameData::zanki = GameData::Zanki_set;
			GameData::Gameclear = false;
			GameData::clear = false;
			GameData::Gameover = false;
		}
	}
}

