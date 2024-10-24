#pragma once
#include "../Base/Base.h"

class BlockManager :public Base 
{
private:
	int m_cnt = 30;

public:
	void Update();
};