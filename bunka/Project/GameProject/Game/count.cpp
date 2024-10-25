#include "count.h"
#include "Map.h"

count::count(const CVector2D& pos) : Base(eType_count)
{
	m_cnt = 300 * 60;
}

void count::Update()
{
	m_cnt--;
}

void count::Draw()
{
	FONT_T()->Draw(910, 80, 1000, 1000, 1000, "%d", m_cnt/60);
}

void count::Collision(Base* b)
{
}