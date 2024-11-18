#include "Tutorial Player.h"
TutorialPlayer::TutorialPlayer():Base(eType_TutorialPlayer)
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
		dimg.Draw();
		break;
	case 1:
		aimg.Draw();
		break;
	}
}
