#pragma once
#include"../Base/Base.h"

#define MAP_TIP_SIZE 49
class sikaku :public Base 
{
private:
	enum
	{
		eState_Idle,
		eState_Down,//������
	};
	CImage m_img;
	bool m_is_ground;
	int m_state;
	void StateIdle();
	void StateDown();
public:
	sikaku(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	//�w����W�`�b�v�ԍ��̎擾
	int GetTip(const CVector2D& pos);
	//�w���A�s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int row);
	//�}�b�v�Ƃ̔���
	int CollisionMap(Base* b);
	//�����蔻��
	int CollisionRect(const CVector2D& pos, const CRect& rect);
};