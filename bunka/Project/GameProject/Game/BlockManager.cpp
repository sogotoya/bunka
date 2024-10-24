#include "BlockManager.h"
#include "Block.h"

BlockManager::BlockManager()
	:Base(eType_BlockManager)
{

}

void BlockManager::Update()
{
	m_cnt--;
	if (m_cnt == 0) 
	{
		Base::Add(new Block(CVector2D(150, 0), rand() % Block::eMax));
		m_cnt = rand() % 300 + 300;
	}
}
