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
	//��]�̏�����
	m_block_dir = 0;
	m_pos = pos;
	m_cnt = 0;
	//�V�����ʒu�փu���b�N�̏�������
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
	//��莞�Ԃŉ��֗���
	if (m_cnt >= move_cnt) 
	{
		m_cnt = 0;
		//���̈ʒu�̃u���b�N������
		WriteBlock(m_pos, 0);
		//1�}�X�����m�F
		if(CollisionCheck(m_pos+CVector2D(0,1),m_block_dir))
		{
			//���ɍs���Ȃ��̂Ȃ�폜
			SetKill();
			//���̈ʒu�փu���b�N����������
			WriteBlock(m_pos, 2);
		}else
		{
			//���ֈړ�
			m_pos += CVector2D(0, 1);
			//�V�����ʒu�փu���b�N�̏�������
			WriteBlock(m_pos, 2);

		}
	}
	if (PUSH_PAD(1, CInput::eLeft))
	{
		//���̈ʒu�̃u���b�N������
		WriteBlock(m_pos, 0);
		//1�}�X�����m�F
		if (CollisionCheck(m_pos + CVector2D(-1, 0), m_block_dir))
		{
			//���ɍs���Ȃ��̂Ȃ�폜
			
			//���̈ʒu�փu���b�N����������
			WriteBlock(m_pos, 2);
		}
		else
		{
			//���ֈړ�
			m_pos += CVector2D(-1, 0);
			//�V�����ʒu�փu���b�N�̏�������
			WriteBlock(m_pos, 2);

		}
	}
	//�E
	if (PUSH_PAD(1, CInput::eRight))
	{
		//���̈ʒu�̃u���b�N������
		WriteBlock(m_pos, 0);
		//1�}�X�E���m�F
		if (CollisionCheck(m_pos + CVector2D(1, 0), m_block_dir))
		{
			//�E�ɍs���Ȃ��̂Ȃ�폜
			
			//���̈ʒu�փu���b�N����������
			WriteBlock(m_pos, 2);
		}
		else
		{
			//���ֈړ�
			m_pos += CVector2D(1, 1);
			//�V�����ʒu�փu���b�N�̏�������
			WriteBlock(m_pos, 2);

		}
	}
}


bool Block::CollisionCheck(const CVector2D& new_pos,int new_dir)
{
	Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Map));
	//3*3�̃u���b�N�Ō���
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			//block_data��0�̏��̓X�L�b�v
			if (block_data[m_block_type][new_dir][i][j] == 0)continue;
			CVector2D v = new_pos + CVector2D(j, i);
			if (m->GetTip(v.x, v.y) != 0) 
			{
				//�ǂɂԂ���
				return true;
			}
		}
	}
	//�ړ��ł���
	return false;
}

void Block::WriteBlock(const CVector2D& pos, int t)
{
	Map* m = dynamic_cast<Map*>(Base::FindObject(eType_Map));
	//3*3�̃u���b�N�ŏ�������
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			//block_data��0�̏��̓X�L�b�v
			if (block_data[m_block_type][m_block_dir][i][j] == 0)continue;
			CVector2D v = pos + CVector2D(j, i);
			//�}�b�v�`�b�v�֏�������
			m->SetTip(v.x, v.y, t);
		}
	}





}


