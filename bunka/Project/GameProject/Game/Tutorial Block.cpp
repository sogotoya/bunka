#include "Tutorial Block.h"
TutorialBlock::TutorialBlock() :Base(eType_TutorialBlock),
m_Tutorial_text("C:\\Windows\\Fonts\\msgothic.ttc", 60)
{
	Rimg = COPY_RESOURCE("R key", CImage);
	Limg = COPY_RESOURCE("L key", CImage);
	Uimg = COPY_RESOURCE("U key", CImage);
	Downimg = COPY_RESOURCE("Down key", CImage);
}
void TutorialBlock::Update()
{

	if (PUSH_PAD(1, CInput::eRight)) {
		Step = 0;

	}
	if (PUSH_PAD(1, CInput::eLeft)) {
		Step = 1;

	}
	if (PUSH_PAD(1, CInput::eUp)) {
		Step = 2;

	}
	if (HOLD_PAD(1, CInput::eDown)) {
		Step = 3;

	}

}
void TutorialBlock::Draw()
{
	switch (Step) {
	case 0:
		Rimg.SetSize(180, 180);
		Rimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "âEà⁄ìÆ");
		Rimg.Draw();
		break;
	case 1:
		Limg.SetSize(180, 180);
		Limg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "ç∂à⁄ìÆ");
		Limg.Draw();
		break;
	case 2:
		Uimg.SetSize(180, 180);
		Uimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "âÒì]");
		Uimg.Draw();
		break;
	case 3:
		Downimg.SetSize(180, 180);
		Downimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "çÇë¨ç~â∫");
		Downimg.Draw();
		break;
	}

}