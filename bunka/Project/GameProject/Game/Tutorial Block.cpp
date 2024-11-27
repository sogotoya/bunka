#include "Tutorial Block.h"
TutorialBlock::TutorialBlock() :Base(eType_TutorialBlock),
m_Tutorial_text("C:\\Windows\\Fonts\\msgothic.ttc", 60)
{
	Rimg = COPY_RESOURCE("R key", CImage);
	Limg = COPY_RESOURCE("L key", CImage);
	Uimg = COPY_RESOURCE("U key", CImage);
	Downimg = COPY_RESOURCE("Down key", CImage);
	Rwimg = COPY_RESOURCE("Red window", CImage);
}
void TutorialBlock::Update()
{

	if (HOLD_PAD(1,CInput::eRight)) {
		x = 0;

	}
	if (HOLD_PAD(1,CInput::eLeft)) {
		x = 1;

	}
	if (HOLD_PAD(1,CInput::eUp)) {
		x = 2;

	}
	if (HOLD_PAD(1,CInput::eDown)) {
		x = 3;

	}

}
void TutorialBlock::Draw()
{
	if (HOLD_PAD(1,CInput::eRight)) {
		Rwimg.SetSize(230, 230);
		Rwimg.SetPos(1140, 430);
		Rwimg.Draw();

	}
	if (HOLD_PAD(1,CInput::eLeft)) {
		Rwimg.SetSize(230, 230);
		Rwimg.SetPos(1140, 430);
		Rwimg.Draw();

	}
	if (HOLD_PAD(1,CInput::eUp)) {
		Rwimg.SetSize(230, 230);
		Rwimg.SetPos(1140, 430);
		Rwimg.Draw();
	}
	if (HOLD_PAD(1,CInput::eDown)) {
		Rwimg.SetSize(230, 230);
		Rwimg.SetPos(1140, 430);
		Rwimg.Draw();
	}

	switch (x) {
	case 0:
		Rimg.SetSize(180, 180);
		Rimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 720, 1, 1, 1, "âEà⁄ìÆ");
		Rimg.Draw();
		break;
	case 1:
		Limg.SetSize(180, 180);
		Limg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 720, 1, 1, 1, "ç∂à⁄ìÆ");
		Limg.Draw();
		break;
	case 2:
		Uimg.SetSize(180, 180);
		Uimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1190, 720, 1, 1, 1, "âÒì]");
		Uimg.Draw();
		break;
	case 3:
		Downimg.SetSize(180, 180);
		Downimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1140, 720, 1, 1, 1, "çÇë¨ç~â∫");
		Downimg.Draw();
		break;
	}

}