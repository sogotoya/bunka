#pragma once
#include "../Base/Base.h"

class Block :public Base 
{
public:
	
	enum 
	{
		eL,
		eSikaku,
		eStick,
		eMax,
	};
private:
	
	//�u���b�N�̎��
	int m_block_type;
	//�u���b�N�̉�]
	int m_block_dir;
	//�����J�E���g
	int m_cnt;
	//�V�����ʒu���ړ��ł��邩�̃`�F�b�N
	bool CollisionCheck(const CVector2D& new_pos,int new_dir);
	//�u���b�N���}�b�v�֏�������
	void WriteBlock(const CVector2D& pos, int t);
	
public:
	Block(const CVector2D& pos, int type);
	void Update();
};