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
#include "EndRoll/EndRoll.h"

Game::Game()
	:Base(eType_Scene)
{
	//生成
	Base::Add(new Field());
	//プレイヤーの各ステージのスポーン位置
	switch (GameData::s_score)
	{
	case 0:
		Base::Add(new Player(CVector2D(SCREEN_WIDTH/2, 900), true));
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
	case 5:
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
	skipimg = COPY_RESOURCE("skip", CImage);
	stopimg.SetPos(770, 400);
	clearimg.SetSize(1550, 745);
	clearimg.SetCenter(50, 100);
	clearimg.SetPos(230, 240);
	skipimg.SetSize(500,190);
	skipimg.SetPos(1200,280);
	drawclear = false;
	drawretry = false;
	drawone = false;
	GameData::Gameclear = false;
	//残機を３にセット
	for(int i=0;i<3;i++)
	zankiimg[i].SetSize(75, 75);
	switch (GameData::s_score) {
	case 0:
		SOUND("Tutorial")->Play();
		break;
	case 1:
		SOUND("stage1")->Play();
		break;
	case 2:
		SOUND("stage2")->Play();
		break;
	case 3:
		SOUND("stage3")->Play();
		break;
	case 4:
		SOUND("stage4")->Play();
		break;
	case 5:
		SOUND("stage5")->Play();
		break;
	}


}

void Game::Update()
{
	
	if (GameData::s_score == 0)
	{
		if (PUSH(CInput::eButton1)) {
			SOUND("Tutorial")->Stop();
			Base::KillAll();
			Base::Add(new Menu());
		}
	}
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal())
		{
			//サウンドの終了とエンドロールの加算
			switch (GameData::s_score) {
			case 0:
				SOUND("Tutorial")->Stop();
				break;
			case 1:
				SOUND("stage1")->Stop();
				if (GameData::stage1 == 1)
				{
					GameData::end_score += 1;
					GameData::stage1 = 0;
				}
				break;

			case 2:
				SOUND("stage2")->Stop();
				if (GameData::stage2 == 1)
				{
					GameData::end_score += 1;
					GameData::stage2 = 0;
				}
				break;

			case 3:
				SOUND("stage3")->Stop();
				if (GameData::stage3 == 1)
				{
					GameData::end_score += 1;
					GameData::stage3 = 0;
				}
				break;

			case 4:
				SOUND("stage4")->Stop();
				if (GameData::stage4 == 1)
				{
					GameData::end_score += 1;
					GameData::stage4 = 0;
				}
				break;
			case 5:
				SOUND("stage5")->Stop();
				if (GameData::stage5 == 1)
				{
					GameData::end_score += 1;
					GameData::stage5 = 0;
				}
				break;
			}
				//ゲームクリア画面表示
				drawclear = true;
				GameData::Gameclear = true;
				
				//チュ−トリアルからメニュー
				if (GameData::s_score == 0)
				{
					Base::KillAll();
					Base::Add(new Menu());
				}
				else 
				{
					//すべてのステージをクリアしたらエンドロール
					if (GameData::end_score == 4)
					{
						//EndRollがゲーム内になければ(常に生成されるため1回のみ生成)
						if (!Base::FindObject(eType_EndRoll))
						{
							KillAll();
							Base::Add(new EndRoll(CVector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT)));
						}
						if (PUSH(CInput::eButton1))
						{
							KillAll();
							Base::Add(new TItle());
						}
					}
					else
					{
						if (PUSH(CInput::eButton1))
						{
							GameData::zanki = 3;
							SetKill();
							Base::Kill(1 << eType_Goal
								| 1 << eType_Player
								| 1 << eType_count
								| 1 << eType_Scene);
							Base::Add(new Menu());
						}
					}


				}
	}
	//プレイヤーがKillされたら
		if (!Base::FindObject(eType_Player) && !GameData::Gameclear)
		{
			//残機がまだあれば描画できる
			if (GameData::zanki != 0)

				drawretry = true;

			if (PUSH(CInput::eButton1))
			{
				//リトライした後のカウントリセット
				Base* b = Base::FindObject(eType_count);
				count* c = dynamic_cast<count*>(b);
				c->SetCount(180 * 60);

				//プレイヤーの各ステージのリスポーン位置

				switch (GameData::s_score)
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
				case 5:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;
				}
				drawretry = false;
			}
		}
		
	}
}

void Game::Draw()
{
	//ゲーム中の一時停止
	if (PUSH(CInput::eButton10))
		m_pose = !m_pose;
	//残機描画
	if(GameData::s_score!=0)
	for (int i = 0; i < GameData::zanki; i++)
	{ 
		zankiimg[i].SetPos(10+80*i, 10);
		zankiimg[i].Draw();
	}
	
	
	//ステージクリア画面描画
	if (drawclear)
	{
		clearimg.Draw();
	}
	//リトライ画面描画
	if(drawretry)
	{
			retryimg.Draw();
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
			switch (GameData::s_score) {
			case 0:
				SOUND("Tutorial")->Stop();
				break;
			case 1:
				SOUND("stage1")->Stop();
				break;

			case 2:
				SOUND("stage2")->Stop();
				break;

			case 3:
				SOUND("stage3")->Stop();
				break;

			case 4:
				SOUND("stage4")->Stop();
				break;
			case 5:
				SOUND("stage5")->Stop();
				break;
			}
			Base::KillAll();
		
			//ゲームオーバーになるとメニュー画面に戻る
			Base::Add(new Menu());
			GameData::s_score = 1;
			GameData::zanki = GameData::Zanki_set;
			GameData::Gameclear = false;
			GameData::Gameover = false;
			
		}
	}
	//一時停止画像の描画
	if (m_pose)
	{
		stopimg.Draw();
	}
	//スキップ画面描写
	if (GameData::s_score ==0)
	{
		skipimg.Draw();
	}
}

