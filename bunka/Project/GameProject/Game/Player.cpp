#include "Player.h"
#include "Map.h"


Player::Player(const CVector2D& p, bool flip)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	m_img.SetSize(90,90);
	m_img.SetCenter(45, 90);
	m_rect = CRect(-20, -87, 20, 0);
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	m_is_ground = true;
	
}

void Player::StateIdle()
{
	const float move_speed = 5;
	//�ړ��t���O
	bool move_flag = false;
	//��
	if (HOLD(CInput::eLeft)) 
	{
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E
	if (HOLD(CInput::eRight)) 
	{
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	const float jump_pow = 15;
	if (m_is_ground && PUSH(CInput::eButton2)) 
	{
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}
	if (!m_is_ground) 
	{//?
		if (m_vec.y < 0)
			m_img.ChangeAnimation(eAnimjump, false);
	}
	else 
	{
		if (move_flag) 
		{
			m_img.ChangeAnimation(eAnimWalk);
		}
		else 
		{
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}
void Player::Update()
{
	m_pos_old = m_pos;
	switch (m_state) 
	{
		case eState_Idle:
			StateIdle();
			break;

	}

	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;

	m_vec.y += GRAVITY;
	m_pos += m_vec;

	m_img.UpdateAnimation();
}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();
}

void Player::Collision(Base* b)
{
	switch (b->m_type) 
	{
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) 
		{
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x,m_pos_old.y),m_rect);
			if(t != 0)
			{
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y),m_rect);
			if (t != 0) 
			{
				m_pos.y = m_pos_old.y;
				//�������x�̃��G�b�g
				m_vec.y = 0;
				//���n�t���Oon
				m_is_ground = true;
			}
		}
		break;
	}
}

static TexAnim playerIdle[] = {
	{0,20},
	{1,20},
};

static TexAnim playerWalk[] = {
	{3,10},
	{4,5},
	{5,10},
};

static TexAnim playerjump[] = {
	{6,50}
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),//0
	ANIMDATA(playerWalk),//1
	ANIMDATA(playerjump),//2
};