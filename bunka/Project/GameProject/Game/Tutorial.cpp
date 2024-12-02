#include "Tutorial.h"
#include "Player.h"
#include "Block.h"
Tutorial::Tutorial() :Base(eType_Tutorial),
m_Tutorial_text("C:\\Windows\\Fonts\\msgothic.ttc", 60)
{
	dimg = COPY_RESOURCE("D key", CImage);
	aimg = COPY_RESOURCE("A key", CImage);
	simg = COPY_RESOURCE("Space key", CImage);
	Rimg = COPY_RESOURCE("R key", CImage);
	Limg = COPY_RESOURCE("L key", CImage);
	Uimg = COPY_RESOURCE("U key", CImage);
	Downimg = COPY_RESOURCE("Down key", CImage);
	wimg = COPY_RESOURCE("Red window", CImage);
	Swimg = COPY_RESOURCE("Red Side window", CImage);
}
void Tutorial::Update()
{
	Player* p = dynamic_cast<Player*>(Base::FindObject(eType_Player));

	switch (Step) {
	case 0:
		p->stop = true;
		if (HOLD(CInput::eRight)) {
			Step++;

		}
		break;
	case 1:
		p->stop = false;
		if (FREE(CInput::eRight)) {
			Step++;

		}
		break;
	case 2:
		p->stop = true;
		if (HOLD(CInput::eLeft)) {
			Step++;

		}
		break;
	case 3:
		p->stop = false;
		if (FREE(CInput::eLeft)) {
			Step++;

		}
		break;
	case 4:
		p->stop = true;
		if (PUSH(CInput::eButton5)) {
			Step++;
			p->stop = false;

		}
		break;
	case 5:
		p->stop = false;
		if (FREE(CInput::eButton5)) {
			Step++;

		}
		break;
	case 6:
		p->stop = true;
		if (HOLD_PAD(1,CInput::eRight)) {
			Step++;

		}
		break;
	case 7:
		p->stop = false;
		if (FREE(CInput::eRight)) {
			Step++;

		}
		break;
	case 8:
		p->stop = true;
		if (HOLD_PAD(1,CInput::eLeft)) {
			Step++;

		}
		break;
	case 9:
		p->stop = false;
		if (FREE(CInput::eLeft)) {
			Step++;

		}
		break;
	case 10:
		p->stop = true;
		if (HOLD_PAD(1,CInput::eUp)) {
			Step++;

		}
		break;
	case 11:
		p->stop = false;
		if (FREE(CInput::eUp)) {
			Step++;

		}
		break;
	case 12:
		p->stop = true;
		if (HOLD_PAD(1,CInput::eDown)) {
			Step++;

		}
		break;
	case 13:
		p->stop = false;
		if (FREE(CInput::eDown)) {
			Step++;

		}
		break;
	}
}
void Tutorial::Draw()
{
	switch (TutorialProgress) {
	case 0:
		if (HOLD(CInput::eRight)) 
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if(Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		dimg.SetSize(180, 180);
		dimg.SetPos(870, 450);
		m_Tutorial_text.Draw(870, 720, 1, 1, 1, "右移動");
		dimg.Draw();
		break;

	case 1:
		if (HOLD(CInput::eLeft))
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		aimg.SetSize(180, 180);
		aimg.SetPos(870, 450);
		m_Tutorial_text.Draw(870, 720, 1, 1, 1, "左移動");
		aimg.Draw();
		break;

	case 2:
		if (HOLD(CInput::eUp))
		{
			Swimg.SetSize(460, 150);
			Swimg.SetPos(730, 460);
			Swimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		simg.SetSize(410, 100);
		simg.SetPos(750, 480);
		m_Tutorial_text.Draw(830, 680, 1, 1, 1, "ジャンプ");
		simg.Draw();
		break;
	
	case 3:
		if (HOLD_PAD(1, CInput::eRight))
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		Rimg.SetSize(180, 180);
		Rimg.SetPos(870, 450);
		m_Tutorial_text.Draw(870, 720, 1, 1, 1, "右移動");
		Rimg.Draw();
		break;

	case 4:
		if (HOLD_PAD(1, CInput::eLeft))
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		Limg.SetSize(180, 180);
		Limg.SetPos(870, 450);
		m_Tutorial_text.Draw(870, 720, 1, 1, 1, "左移動");
		Limg.Draw();
		break;

	case 5:
		if (HOLD_PAD(1, CInput::eUp))
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		Uimg.SetSize(180, 180);
		Uimg.SetPos(870, 450);
		m_Tutorial_text.Draw(870, 720, 1, 1, 1, "回転");
		Uimg.Draw();
		break;
	case 6:
		if (HOLD_PAD(1, CInput::eDown))
		{
			wimg.SetSize(230, 230);
			wimg.SetPos(850, 430);
			wimg.Draw();
			Is_Holded = true;
		}
		else if (Is_Holded)
		{
			TutorialProgress++;
			Is_Holded = false;
		}
		Downimg.SetSize(180, 180);
		Downimg.SetPos(870, 450);
		m_Tutorial_text.Draw(850, 720, 1, 1, 1, "高速降下");
		Downimg.Draw();
		break;
}
}
