#include "Effect.h"

Effect::Effect(const char* name, const CVector2D& pos, bool flip)
	:Base(eType_Effect)
{

}

void Effect::Update()
{

}

void Effect::Draw()
{

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