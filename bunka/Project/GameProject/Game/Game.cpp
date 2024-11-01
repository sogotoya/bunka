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
	retryimg = COPY_RESOURCE("Retry", CImage);
	clearimg = COPY_RESOURCE("GameClear", CImage);
	stage1goal= COPY_RESOURCE("stage1goal", CImage);
	drawclear = false;
	drawretry = false;
	draw1goal = false;
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
				
					Base::Kill(1 << eType_Map
						| 1 << eType_AreaChange
						| 1 << eType_Goal
						| 1 << eType_Block);
					
					GameData::s_score++;
					Base::Add(new Map(GameData::s_score));
			
			}
				
			
		}
	}
	if (!Base::FindObject(eType_Player)) 
	{
		drawretry = true;
		if (PUSH(CInput::eButton1))
			
		Base::Add(new Player(CVector2D(200, 900), true));
	}
	/*if (GamaData::s_score>=3)
	{
		Base::KillAll();
		Base::Add(new Title());
	}*/
}

void Game::Draw()
{
	//��ɉ摜�����Ȃ��悤��
	if (drawclear)
	{
			clearimg.Draw();
	}
	if(drawretry)
	{
		retryimg.Draw();
		drawretry = false;
	}
	if (draw1goal)
	{
		stage1goal.Draw();
		draw1goal = false;
	}
}
