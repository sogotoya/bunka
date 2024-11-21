#include "Tutorial Player.h"
TutorialPlayer::TutorialPlayer() :Base(eType_TutorialPlayer),
m_Tutorial_text("C:\\Windows\\Fonts\\msgothic.ttc", 60)
{
	dimg = COPY_RESOURCE("D key", CImage);
	aimg = COPY_RESOURCE("A key", CImage);
	simg = COPY_RESOURCE("Space key", CImage);
	Rimg = COPY_RESOURCE("R key", CImage);
}
void TutorialPlayer::Update()
{
	
		if (HOLD(CInput::eRight)) {
			Step=0;
			
		}
		if (HOLD(CInput::eLeft)){
			Step=1;
			
		}
		if (HOLD(CInput::eUp)) {
			Step=2;
			
		}
		if (HOLD(CInput::eRight)) {
			Step = 3;
		}

}
void TutorialPlayer::Draw()
{
	switch (Step) {
	case 0:
		dimg.SetSize(180, 180);
		dimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "右移動");
		dimg.Draw();
		break;
	case 1:
		aimg.SetSize(180, 180);
		aimg.SetPos(830, 450);
		m_Tutorial_text.Draw(830, 700, 1, 1, 1, "左移動");
		aimg.Draw();
		break;
	case 2:
		simg.SetSize(410, 100);
		simg.SetPos(750, 450);
		m_Tutorial_text.Draw(830, 618, 1, 1, 1, "ジャンプ");
		simg.Draw();
		break;
	}

}
