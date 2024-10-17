#pragma once
#include "Base/Base.h"

class Player : public Base {
private:
	int m_state;
	CImage m_img;
	bool m_flip;

	void StateIdle();
	//’…’n
	bool m_is_ground;

public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
extern TexAnimData player_anim_data[];