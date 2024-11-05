#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BlockManager.h"
#include "Goal.h"
#include "GameData.h"
#include "count.h"
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
	clear_one = COPY_RESOURCE("stage1goal",CImage);
	clear_two = COPY_RESOURCE("stage2goal", CImage);
	drawclear = false;
	drawretry = false;
	drawone = false;
	drawtwo = false;
}

void Game::Update()
{
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if(g->GetGoal())
		{
			if (GameData::s_score==3)
			{
				drawclear = true;
				//GameData::Gameclear = true;
				if(PUSH(CInput::eButton1))
				Base::KillAll();
			}
			else{
				
				GameData::Gameclear = true;
			
			}
				
			
		}
	}
	if (!Base::FindObject(eType_Player))
	{
		drawretry = true;
		if (PUSH(CInput::eButton1))
		{


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
		
		if (PUSH(CInput::eButton1))
		{
			Base::Kill(1 << eType_Map
				| 1 << eType_AreaChange
				| 1 << eType_Goal
				| 1 << eType_Block);

			GameData::s_score++;
			GameData::Gameclear = false;
			Base::Add(new Map(GameData::s_score));
		}
	}
}

void Game::Draw()
{
	//上に画像が被らないように
	if (drawclear)
	{
			clearimg.Draw();
	}
	if(drawretry)
	{
		retryimg.Draw();
		drawretry = false;
	}
	if (drawone)
	{
		clear_one.Draw();
		drawone = false;
	}
	if (drawtwo)
	{
		clear_two.Draw();
		drawtwo = false;
	}
}
