#include "count.h"
#include "Map.h"
#include "GameData.h"

count::count(const CVector2D& pos) : Base(eType_count),
m_count_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
	m_cnt = 180 * 60;
	
}


void count::Update()
{
	//�Q�[���N���A���g�D���[�̎���if����ʂ�
	if(m_cnt>=0)
	{
		if(!GameData::Gameclear)
		{
			m_cnt--;
			
		}
	}
	//���Ԑ؂�ɂȂ�ƃQ�[���I�[�o�[
	if (m_cnt == 0)
	{
		GameData::Gameover = true;
	}
}

void count::Draw()
{
	if (!GameData::Gameclear)
	//�����\��
	m_count_text.Draw(830, 120, 1, 1, 1, "%d",m_cnt/60);
}

void count::Collision(Base* b)
{
}