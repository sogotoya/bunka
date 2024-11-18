#include "TItle.h"
#include"../Game/Game.h"
#include "UI/Menu.h"
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
		Base::Add(new Menu());
		//Base::Add(new Game());
	}
}

void TItle::Draw()
{
	m_img.Draw();

}
