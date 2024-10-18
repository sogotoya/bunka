#pragma once
#include "../Base/Base.h"

#define MAP_WIDTH 39
#define MAP_HEIGHT 22
#define MAP_TIP_SIZE 49

class Map :public Base 
{
private:
	CImage m_img;
public:
	Map();
	void Draw();
	//指定座標チップ番号の取得
	int GetTip(const CVector2D& pos);
	//指定列、行のマップチップを取得
	int GetTip(int col, int row);
	//マップとの判定
	int CollisionPoint(const CVector2D& pos);
	//当たり判定
	int CollisionRect(const CVector2D& pos, const CRect& rect);
};