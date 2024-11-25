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
		x = 0;

	}
	if (PUSH_PAD(1, CInput::eLeft)) {
		x = 1;

	}
	if (PUSH_PAD(1, CInput::eUp)) {
		x = 2;

	}
	if (HOLD_PAD(1, CInput::eDown)) {
		x = 3;

	}

}
void TutorialBlock::Draw()
{
	switch (x) {
	case 0:
		Rimg.SetSize(180, 180);
		Rimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 700, 1, 1, 1, "右移動");
		COPY_RESOURCE("Red window", CImage);
		Rimg.Draw();
		break;
	case 1:
		Limg.SetSize(180, 180);
		Limg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 700, 1, 1, 1, "左移動");
		COPY_RESOURCE("Red window", CImage);
		Limg.Draw();
		break;
	case 2:
		Uimg.SetSize(180, 180);
		Uimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 700, 1, 1, 1, "回転");
		COPY_RESOURCE("Red window", CImage);
		Uimg.Draw();
		break;
	case 3:
		Downimg.SetSize(180, 180);
		Downimg.SetPos(1160, 450);
		m_Tutorial_text.Draw(1160, 700, 1, 1, 1, "高速降下");
		COPY_RESOURCE("Red window", CImage);
		Downimg.Draw();
		break;
	}

}