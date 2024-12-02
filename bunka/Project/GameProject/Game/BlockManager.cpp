#include "BlockManager.h"
#include "Block.h"
#include "GameData.h"
#include "Map.h"

BlockManager::BlockManager()
	:Base(eType_BlockManager)
{

}

void BlockManager::Update()
{
	//見つからなければカウントダウン
	if(!Base::FindObject(eType_Block))
	m_cnt--;
	if (m_cnt == 0) 
	{
		//dynamic_castでBaseからMapに変換
		Map* m =dynamic_cast<Map*> (Base::FindObject(eType_Block));
		Base::Add(new Block(m->drop_pos, rand() % Block::eMax));
		m_cnt = rand() % 10 + 10;
	}

}
