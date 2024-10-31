#pragma once
#include "Base/Base.h"

class Player : public Base {
	enum 
	{
		eState_Idle,
		eState_Walk,
		
	};
	enum 
	{
		eAnimIdle = 0,
		eAnimWalk,
		eAnimjump,
		eAnimDon

	};
private:
	const int air_time_set = 70;
	const int cooltime_set = 20;

	int m_state;
	CImage m_img;
	bool m_flip;

	void StateIdle();
	//���n
	bool m_is_ground;

	//�󒆂ɂ��鎞�Ԃ��J�E���g
	int air_time_cnt = 0;
	//�N�[���^�C���B���ꂪ�O�ȏ�̏ꍇ�̓v���C���[�������܂���B
	int cooltime = 0;


public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
extern TexAnimData player_anim_data[];