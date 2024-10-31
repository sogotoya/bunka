#pragma once
#include "../Base/Base.h"

#define MAP_WIDTH 39
#define MAP_HEIGHT 25
#define MAP_TIP_SIZE 49

class Map :public Base 
{
private:
	CImage m_img;
	//���������\�f�[�^
	int m_stage_data[MAP_HEIGHT][MAP_WIDTH];
public:
	Map(int area);
	void Draw();
	//�w����W�`�b�v�ԍ��̎擾
	int GetTip(const CVector2D& pos, int* tx=nullptr, int* ty=nullptr);
	//�w���A�s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int row);

	//�w���A�s�̃}�b�v�`�b�v��ݒ�
	void SetTip(int col, int row, int t);

	//�}�b�v�Ƃ̔���
	int CollisionPoint(const CVector2D& pos);
	//�����蔻��
	int CollisionRect(const CVector2D& pos, const CRect& rect,CVector2D*rev_pos);
};