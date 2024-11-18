#include "Tutorial Player.h"
TutorialPlayer::TutorialPlayer():Base(eType_TutorialPlayer)
{
	img = COPY_RESOURCE("D key", CImage);
}
void TutorialPlayer::Update()
{
	switch (Step) {
	case 0:
		if (HOLD(CInput::eLeft)) {
			Step++;
			img = COPY_RESOURCE("D key", CImage);
		}
		break;
	case 1:
		if (HOLD(CInput::eRight)){
			Step--;
		}
		break;
	}
}
void TutorialPlayer::Draw()
{
	switch (Step) {
	case 0:
		img.Draw();
		break;
	case 1:
		
		break;
	}
}
