#include "Effect.h"

Effect::Effect(const char* name, const CVector2D& pos, bool flip)
	:Base(eType_Effect)
{
	m_img = COPY_RESOURCE("Effect_Jump", CImage);
	m_pos = pos;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_img.ChangeAnimation(0, false);

}

void Effect::Update()
{
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) 
	{
		SetKill();
	}
}

void Effect::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

static TexAnim moku[] =
{
	{0,20},
	{1,20},
	{2,20},
	{3,20},
};
TexAnimData effect_anim_data[] = {
	ANIMDATA(moku),
};