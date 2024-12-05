#include "BlockManager.h"
#include "Block.h"
#include "GameData.h"
#include "Map.h"

BlockManager::BlockManager()
	:Base(eType_BlockManager)
{
	stop = false;
}

void BlockManager::Update()
{
	if (stop == true)
		return;
	//������Ȃ���΃J�E���g�_�E��
	if(!Base::FindObject(eType_Block))
	m_cnt--;
	if (m_cnt == 0) 
	{
		//dynamic_cast��Base����Map�ɕϊ�
		Map* m =dynamic_cast<Map*> (Base::FindObject(eType_Map));
		Base::Add(new Block(m->drop_pos, rand() % Block::eMax));
		m_cnt = rand() % 10 + 10;
	}

}
