#include "Player.h"



Player::Player(const CVector2D& p, bool flip)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_img.ChangeAnimation(0);
	m_pos_old = m_pos = p;
	m_img.SetSize(90,90);
	//í èÌèÛë‘Ç÷
	//m_state = eState_Idle;
	m_is_ground = true;
	
}

void Player::StateIdle()
{
}
void Player::Update()
{

}

void Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect;
}

void Player::Collision(Base* b)
{

}

static TexAnim playerIdle[] = {
	{0,10},
	{1,10},
};

static TexAnim playerWalk[] = {
	{3,20},
	{4,20},
	{5,20},
};

static TexAnim playerjump[] = {
	{6,50}
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),//0
	ANIMDATA(playerWalk),//1
	ANIMDATA(playerjump),//2
};