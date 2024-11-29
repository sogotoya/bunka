#include "EndRoll.h"

EndRoll::EndRoll(const CVector2D& p):Base(eType_EndRoll)
{
	endimg = COPY_RESOURCE("end", CImage);
	endimg.SetSize(800, 1200);
	endimg.SetCenter(400, 600);
	m_pos = p;
}

void EndRoll::Update()
{
	m_pos.y -= EndRoll_Speed;
}

void EndRoll::Draw()
{
	endimg.SetPos(m_pos);
	endimg.Draw();
}
