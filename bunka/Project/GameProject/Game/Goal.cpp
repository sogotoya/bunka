#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {
    m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	m_img.SetSize(64, 128);
	m_img.SetCenter(31, 120);
	m_rect = CRect(-32, -128, 32, 0);
	//m_is_goal = false;//�G���[
}

void Goal::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
}
