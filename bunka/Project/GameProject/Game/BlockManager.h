#pragma once
#include "../Base/Base.h"

class BlockManager :public Base 
{
private:
	int m_cnt = 35.5;

public:
	BlockManager();
	void Update();
};