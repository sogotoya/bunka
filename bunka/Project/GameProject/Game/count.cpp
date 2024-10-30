#include "count.h"
#include "Map.h"
#include "GameData.h"

count::count(const CVector2D& pos) : Base(eType_count)
{
	m_cnt = 300 * 60;
}

void count::Update()
{
	//ゲームクリアがトゥルーの時にif文を通る
	if(!GameData::Gameclear)
	m_cnt--;
}

void count::Draw()
{
	if (!GameData::Gameclear)
	FONT_T()->Draw(910, 80, 1, 1, 1, "%d", m_cnt/60);
}

void count::Collision(Base* b)
{
}