#include "TItle.h"
#include"../Game/Game.h"
TItle::TItle():Base(eType_TItle),
m_title_text("C:\\Windows\\Fonts\\tItle.xct",64)
{
	m_img = COPY_RESOURCE("TItle", CImage);
	m_cnt = 0;
}

void TItle::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton1)) {
		Base::KillAll();
		Base::Add(new Game());
	}
}

void TItle::Draw()
{
	m_img.Draw();
	m_title_text.Draw(64, 256, 0, 0, 0, "TItle");
	m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}
