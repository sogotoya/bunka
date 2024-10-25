#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BlockManager.h"
#include "Goal.h"
#include "GameData.h"
Game::Game()
	:Base(eType_Scene)
{
	//Base::Add(new Player(CVector2D(200, 900), true));
	//Base::Add(new Map(1));
	//Base::Add(new BlockManager());
	//Base::Add(new Goal(CVector2D(1740, 613)));
}

void Game::Update()
{
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if(g->GetGoal())
		{
			//�܂Ƃ߂č폜
			Base::Kill(1 << eType_Map
				| 1 << eType_AreaChange
				| 1 << eType_Goal
				| 1 <<eType_Block);
			GameData::s_score++;
			Base::Add(new Map(GameData::s_score));
			
		}
	}
	/*if (GamaData::s_score>=3)
	{
		Base::KillAll();
		Base::Add(new Title());
	}*/
}
