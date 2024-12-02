#include "BlockManager.h"
#include "Block.h"
#include "GameData.h"

BlockManager::BlockManager()
	:Base(eType_BlockManager)
{
	stop = false;
}

void BlockManager::Update()
{
	if (stop == true)
		return;
	//見つからなければカウントダウン
	if(!Base::FindObject(eType_Block))
	m_cnt--;
	if (m_cnt == 0) 
	{
		/*if (GameData::s_score == 5)
		{
			Base::Add(new Block(CVector2D(150, -4), rand() % Block::eMax));
		}
		else 
		{
			Base::Add(new Block(CVector2D(96, -4), rand() % Block::eMax));
		}*/
		Base::Add(new Block(CVector2D(96, -4), rand() % Block::eMax));
		m_cnt = rand() % 10 + 10;
	}

}
