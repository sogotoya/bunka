#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BlockManager.h"
#include "Goal.h"
#include "GameData.h"
#include "count.h"
#include "TItle/TItle.h"
#include "Field.h"
#include "UI/Menu.h"

Game::Game()
	:Base(eType_Scene)
{
	//生成
	Base::Add(new Field());
	//プレイヤーの各ステージのスポーン位置
	switch (GameData::s_score)
	{
	case 0:
		Base::Add(new Player(CVector2D(200, 900), true));
		break;
	case 1:
		Base::Add(new Player(CVector2D(200, 900), true));
		break;
	case 2:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;

	case 3:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;

	case 4:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;
	}
	Base::Add(new Map(GameData::s_score));
	Base::Add(new BlockManager());
	if(GameData::s_score!=0)
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
	stopimg = COPY_RESOURCE("stop", CImage);
	stopimg.SetPos(770, 400);
	clearimg.SetSize(1550, 745);
	clearimg.SetCenter(50, 100);
	clearimg.SetPos(230, 240);
	drawclear = false;
	drawretry = false;
	drawone = false;
	//残機を３にセット
	for(int i=0;i<3;i++)
	zankiimg[i].SetSize(75, 75);
	

}

void Game::Update()
{
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal())
		{

			//ゲームクリア画面
			drawclear = true;
			GameData::clear = true;


			if (GameData::clear)
			{
				if (PUSH(CInput::eButton1))
				{ 
					GameData::zanki = 3;
					GameData::clear = false;
					SetKill();
					Base::Kill(1 << eType_Goal
					| 1 << eType_Player
					| 1 << eType_count
					| 1 << eType_Scene);
					Base::Add(new Menu());
				}
			}
			//チュ－トリアルからメニュー
			if (GameData::s_score == 0)
			{
				Base::KillAll();
				Base::Add(new Menu());
			}
		}
	}
	//プレイヤーがKillされたら
	if (!Base::FindObject(eType_Player))
	{
		//残機がまだあれば描画できる
		if(GameData::zanki!=0)
			
				drawretry = true;
		
		if (PUSH(CInput::eButton1))
		{
			//リトライした後のカウントリセット
			Base* b = Base::FindObject(eType_count);
			count* c = dynamic_cast<count*>(b);
			c->SetCount(180 * 60);
			
			//プレイヤーの各ステージのリスポーン位置
			switch(GameData::s_score)
			{ 
				case 1:
					Base::Add(new Player(CVector2D(200, 900), true));
					break;
				case 2:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;
			
				case 3:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 4:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;
			}
		}
	}
	//ステージをクリアしたら
	/*if (GameData::clear)
	{

		if (PUSH(CInput::eButton1))
		{
			GameData::zanki = 3;
			GameData::clear = false;
			SetKill();
			Base::Kill(1 << eType_Goal
				| 1 << eType_Player
				| 1 << eType_count
				| 1	<< eType_Scene);
			Base::Add(new Menu());
		}
		if (GameData::Gameclear)
		{
			//ステージクリアすると描画
			drawone = true;
			//eButton1で次のマップへ
			if (PUSH(CInput::eButton1))
			{
				Base::Kill(1 << eType_Map
					| 1 << eType_AreaChange
					| 1 << eType_Goal
					| 1 << eType_count
					| 1 << eType_Block);
				if (GameData::s_score <= 3)
				{
					Base::Kill(1 << eType_Player);
				}

				GameData::s_score++;
				GameData::Gameclear = false;
				GameData::zanki = GameData::Zanki_set;
				//s_scoreに連動したMap生成
				Base::Add(new Map(GameData::s_score));

				Base::Add(new count(CVector2D(500, 0)));
			}

			//各ステージクリア後の次Playerの出現位置
			switch (GameData::s_score)
			{

			case 2:
				//マップ２のPlayerの出現位置
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;

			case 3:
				//マップ３のPlayerの出現位置
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;
			case 4:
				//マップ4のPlayerの出現位置
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;
			}

		}
	}*/
	
	
}

void Game::Draw()
{
	//ゲーム中の一時停止
	if (PUSH(CInput::eButton1))
		m_pose = !m_pose;
	//残機描画
	if(GameData::s_score!=0)
	for (int i = 0; i < GameData::zanki; i++)
	{ 
		zankiimg[i].SetPos(10+80*i, 10);
		zankiimg[i].Draw();
	}
	
	
	//上に画像が被らないように
	//最後のステージクリア画面描画
	if (drawclear)
	{
		clearimg.Draw();
	}
	//リトライ画面描画
	if(drawretry)
	{
	//ゲームクリアしていなければ表示
		if(GameData::clear)
		{ 
			retryimg.Draw();
			drawretry = false;
		}
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
		
			//ゲームオーバーになるとメニュー画面に戻る
			Base::Add(new Menu());
			GameData::s_score = 1;
			GameData::zanki = GameData::Zanki_set;
			GameData::Gameclear = false;
			GameData::clear = false;
			GameData::Gameover = false;
		}
	}
	//一時停止画像の描画
	if (m_pose)
	{
		stopimg.Draw();
	}
}

