#pragma once
#include"../Base/Base.h"
class sikaku :public Base 
{
private:
	CImage m_img;
public:
	sikaku(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};