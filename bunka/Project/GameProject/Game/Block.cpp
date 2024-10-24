#include "Block.h"
#include "Map.h"

static int block_data[Block::eMax][4][3][3] = 
{
	{

	{//L0
		1,0,0,
		1,0,0,
		1,1,1,
	},

	{//L1
		0,0,1,
		0,0,1,
		1,1,1,
	},

	{//L2
		1,1,1,
		0,0,1,
		0,0,1,
	},

	{//L3
		1,1,1,
		1,0,0,
		1,0,0,
	},
	},
	{
	{//sikaku
		1,1,0,
		1,1,0,
		0,0,0,
	},
	{//sikaku
		1,1,0,
		1,1,0,
		0,0,0,
	},
	{//sikaku
		1,1,0,
		1,1,0,
		0,0,0,
	},

	{//sikaku
		1,1,0,
		1,1,0,
		0,0,0,
	},
	}
};

Block::Block(const CVector2D& pos, int type)
	:Base(eType_Block)
{
	m_block_type = type;
	//回転の初期数
	m_block_dir = 0;
	m_pos = pos;
	m_cnt = 0;
	//新しい位置へブロックの書き込み
	WriteBlock(m_pos, 2);
}


void Block::Update()
{
	int move_cnt = 30;
	if (PUSH_PAD(1, CInput::eButton1)) 
	{
		WriteBlock(m_pos, 0);
		m_block_dir++;
		if (m_block_dir >= 4)
			m_block_dir = 0;
		WriteBlock(m_pos, 2);
	}
	if (PUSH_PAD(1, CInput::eButton2))
	{
		WriteBlock(m_pos, 0);
		m_block_dir--;
		if (m_block_dir <= 0)
			m_block_dir = 3;
		WriteBlock(m_pos, 2);
	}
	m_cnt++;
	//一定時間で下へ落下
	if (m_cnt >= move_cnt) 
	{
		m_cnt = 0;
		//今の位置のブロックを消す
		WriteBlock(m_pos, 0);
		//1マス下を確認
		if(CollisionCheck(m_pos+CVector2D(0,1),m_block_dir))
		{
			//下に行けないのなら削除
			SetKill();
			//今の位置へブロックを書き込み
			WriteBlock(m_pos, 2);
		}else
		{
			//下へ移動
			m_pos += CVector2D(0, 1);
			//新しい位置へブロックの書き込み
			WriteBlock(m_pos, 2);

		}
	}
	if (PUSH_PAD(1, CInput::eLeft))
	{
		//今の位置のブロックを消す
		WriteBlock(m_pos, 0);
		//1マス左を確認
		if (CollisionCheck(m_pos + CVector2D(-1, 0), m_block_dir))
		{
			//左に行けないのなら削除
			
			//今の位置へブロックを書き込み
			WriteBlock(m_pos, 2);
		}
		else
		{
			//左へ移動
			m_pos += CVector2D(-1, 0);
			//新しい位置へブロックの書き込み
			WriteBlock(m_pos, 2);

		}
	}
	//右
	if (PUSH_PAD(1, CInput::eRight))
	{
		//今の位置のブロックを消す
		WriteBlock(m_pos, 0);
		//1マス右を確認
		if (CollisionCheck(m_pos + CVector2D(1, 0), m_block_dir))
		{
			//右に行けないのなら削除
			
			//今の位置へブロックを書き込み
			WriteBlock(m_pos, 2);
		}
		else
		{
			//下へ移動
			m_pos += CVector2D(1, 1);
			//新しい位置へブロックの書き込み
			WriteBlock(m_pos, 2);

		}
	}
}


bool Block::CollisionCheck(const CVector2D& new_pos,int new_dir)
{
	Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Map));
	//3*3のブロックで検査
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			//block_dataが0の所はスキップ
			if (block_data[m_block_type][new_dir][i][j] == 0)continue;
			CVector2D v = new_pos + CVector2D(j, i);
			if (m->GetTip(v.x, v.y) != 0) 
			{
				//壁にぶつかる
				return true;
			}
		}
	}
	//移動できる
	return false;
}

void Block::WriteBlock(const CVector2D& pos, int t)
{
	Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Map));
	//3*3のブロックで書き込み
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			//block_dataが0の所はスキップ
			if (block_data[m_block_type][m_block_dir][i][j] == 0)continue;
			CVector2D v = pos + CVector2D(j, i);
			//マップチップへ書き込み
			m->SetTip(v.x, v.y, t);
		}
	}





}


