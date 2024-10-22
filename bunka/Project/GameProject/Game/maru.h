#pragma once
#include "../Base/Base.h"

#define MAP_TIP_SIZE 49
class maru :public Base
{
private:
	CImage m_img;

public:
	maru();
	void Draw();
	//�w����W�`�b�v�ԍ��̎擾
	int GetTip(const CVector2D& pos);
	//�w���A�s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int row);
	//�}�b�v�Ƃ̔���
	int CollisionPoint(const CVector2D& pos);
	//�����蔻��
	int CollisionRect(const CVector2D& pos, const CRect& rect);
};