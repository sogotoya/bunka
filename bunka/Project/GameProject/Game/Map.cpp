#include "Map.h"

static int stage1data[MAP_HEIGHT][MAP_WIDTH] = 
{
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
       
};
Map::Map():Base(eType_Map)
{
	m_img =COPY_RESOURCE("Map_Tip", CImage);
}

void Map::Draw()
{
	for (int q = 0; q < MAP_HEIGHT; q++) 
	{
		for (int w = 0; w < MAP_WIDTH; w++) 
		{
            if (stage1data[q][w] == 0)continue;
            int t = stage1data[q][w];
            m_img.SetRect(32*t, 0, 32*t + 32, 32);//?
			m_img.SetSize(MAP_TIP_SIZE *q -m_scroll.x, MAP_TIP_SIZE *w -m_scroll.y);
			m_img.Draw();
		}
	}
}

int Map::GetTip(const CVector2D& pos)
{
    //列の計算
    int col = pos.x / MAP_TIP_SIZE;
    //列(0～MAP_WIDTH-1 まで)の制限
    if (col < 0)col = 0;
    if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;
    //行の計算
    int row = pos.y / MAP_TIP_SIZE;
    //列(0～MAP_HEIGHT-1 まで)の制限
    if (row < 0)row = 0;
    if (row > MAP_HEIGHT - 1)row = MAP_HEIGHT - 1;
    //チップデータの返却
    return GetTip(col, row);
}

int Map::GetTip(int col, int row)
{
    return stage1data[row][col];
}

int Map::CollisionPoint(const CVector2D& pos)
{
    //1点のみ検証
    int t = GetTip(pos);
    if (t != 0)return t;
    return 0;
}

int Map::CollisionRect(const CVector2D& pos, const CRect& rect)
{
    CRect r = CRect(
        pos.x + rect.m_left,
        pos.y + rect.m_top,
        pos.x + rect.m_right,
        pos.y + rect.m_bottom);
    int t;//?
    t = CollisionPoint(CVector2D(r.m_left, r.m_top));
    if (t != 0)return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_top));
    if (t != 0)return t;
    t = CollisionPoint(CVector2D(r.m_left, r.m_bottom));
    if (t != 0)return t;
    t = CollisionPoint(CVector2D(r.m_right, r.m_bottom));
    if (t != 0)return t;
    return 0;
}
