#include "BlockManager.h"
#include "Block.h"

void BlockManager::Update()
{
	m_cnt--;
	if (m_cnt == 0) 
	{
		
		m_cnt = rand() % 60 + 60;
	}
}
