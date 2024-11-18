#include "Tutorial Player.h"
TutorialPlayer::TutorialPlayer() :Base(eType_TutorialPlayer),
m_Tutorial_text("C:\\Windows\\Fonts\\msgothic.ttc", 60)
{
	dimg = COPY_RESOURCE("D key", CImage);
	aimg = COPY_RESOURCE("A key", CImage);
}
void TutorialPlayer::Update()
{
	switch (Step) {
	case 0:
		if (HOLD(CInput::eLeft)) {
			Step++;
			dimg = COPY_RESOURCE("D key", CImage);
		}
		break;
	case 1:
		if (HOLD(CInput::eRight)){
			Step--;
			aimg = COPY_RESOURCE("A key", CImage);
		}
		break;
	}
}
void TutorialPlayer::Draw()
{
	switch (Step) {
	case 0:
		dimg.SetSize(180, 180);
		dimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "âEà⁄ìÆ");
		dimg.Draw();
		break;
	case 1:
		aimg.SetSize(180, 180);
		aimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "ç∂à⁄ìÆ");
		aimg.Draw();
		break;
	}
}
