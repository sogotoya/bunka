#include "BlockManager.h"
#include "Block.h"

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
		Base::Add(new Block(CVector2D(96, -4), rand() % Block::eMax));
		m_cnt = rand() % 10 + 10;
	}
}
