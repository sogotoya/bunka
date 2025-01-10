#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BlockManager.h"
#include "Goal.h"
#include "GameData.h"
#include "count.h"
#include "TItle/TItle.h"
#include "Field.h"
#include "UI/Menu.h"
#include "EndRoll/EndRoll.h"

Game::Game()
	:Base(eType_Scene)
{
	//����
	Base::Add(new Field());
	//�v���C���[�̊e�X�e�[�W�̃X�|�[���ʒu
	switch (GameData::s_score)
	{
	case 0:
		Base::Add(new Player(CVector2D(780, 900), true));
		break;
	case 1:
		Base::Add(new Player(CVector2D(200, 900), true));
		break;
	case 2:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;

	case 3:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;

	case 4:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;
	case 5:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;
	case 6:
		Base::Add(new Player(CVector2D(100, 600), true));
		break;
	case 7:
		Base::Add(new Player(CVector2D(300, 200), true));
		break;
	case 8:
		Base::Add(new Player(CVector2D(100, 200), true));
		break;
	case 9:
		Base::Add(new Player(CVector2D(1800, 900), true));
		break;
	case 10:
		Base::Add(new Player(CVector2D(100, 900), true));
		break;
	}
	Base::Add(new Map(GameData::s_score));
	Base::Add(new BlockManager());
	if(GameData::s_score!=0)
	Base::Add(new count(CVector2D(500, 0)));
	//�w�b�_�[�ō����CImage�ɁACOPY_RESOURCE�ŉ摜���Z�b�g
	retryimg = COPY_RESOURCE("Retry", CImage);
	clearimg = COPY_RESOURCE("GameClear", CImage);
	outimg = COPY_RESOURCE("GameOver", CImage);
	clear_one = COPY_RESOURCE("stage1goal",CImage);
	clear_two = COPY_RESOURCE("stage2goal", CImage);
	zankiimg[0] = COPY_RESOURCE("zanki", CImage);
	zankiimg [1] = COPY_RESOURCE("zanki2", CImage);
	zankiimg[2] = COPY_RESOURCE("zanki3", CImage);
	stopimg = COPY_RESOURCE("stop", CImage);
	skipimg = COPY_RESOURCE("skip", CImage);
	m_kakusu = COPY_RESOURCE("kakusu", CImage);
	m_Goal1 = COPY_RESOURCE("Goal1", CImage);
	m_Goal2 = COPY_RESOURCE("Goal2", CImage);
	m_Goal3 = COPY_RESOURCE("Goal3", CImage);
	stopimg.SetPos(770, 400);
	clearimg.SetSize(1550, 745);
	clearimg.SetCenter(50, 100);
	clearimg.SetPos(230, 240);
	skipimg.SetSize(430,170);
	skipimg.SetPos(1400,100);
	m_kakusu.SetSize(1920,700);
	m_kakusu.SetPos(0, 900);
	m_Goal1.SetPos(140, 130);
	m_Goal1.SetSize(100, 100);
	m_Goal1.SetCenter(31, 120);
	m_Goal2.SetPos(940, 130);
	m_Goal2.SetSize(100, 100);
	m_Goal2.SetCenter(31, 120);
	m_Goal3.SetPos(1750, 130);
	m_Goal3.SetSize(100, 100);
	m_Goal3.SetCenter(31, 120);
	drawclear = false;
	drawretry = false;
	drawone = false;
	GameData::Gameclear = false;
	//�c�@���R�ɃZ�b�g
		for (int i = 0; i < 3; i++)
			zankiimg[i].SetSize(75, 75);
	switch (GameData::s_score) {
	case 0:
		SOUND("Tutorial")->Play();
		break;
	case 1:
		SOUND("stage1")->Play();
		break;
	case 2:
		SOUND("stage2")->Play();
		break;
	case 3:
		SOUND("stage3")->Play();
		break;
	case 4:
		SOUND("stage4")->Play();
		break;
	case 5:
		SOUND("stage5")->Play();
		break;
	}


}

void Game::Update()
{
	
	if (GameData::s_score == 0)
	{
		if (PUSH(CInput::eButton1)) {
			SOUND("Tutorial")->Stop();
			Base::KillAll();
			Base::m_pose = false;
			Base::Add(new Menu());
		}
	}
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal())
		{
			//�T�E���h�̏I���ƃG���h���[���̉��Z
			switch (GameData::s_score) {
			case 0:
				SOUND("Tutorial")->Stop();
				break;
			case 1:
				SOUND("stage1")->Stop();
				if (GameData::stage1 == 1)
				{
					GameData::end_score += 1;
					GameData::stage1 = 0;
				}
				break;

			case 2:
				SOUND("stage2")->Stop();
				if (GameData::stage2 == 1)
				{
					GameData::end_score += 1;
					GameData::stage2 = 0;
				}
				break;

			case 3:
				SOUND("stage3")->Stop();
				if (GameData::stage3 == 1)
				{
					GameData::end_score += 1;
					GameData::stage3 = 0;
				}
				break;

			case 4:
				SOUND("stage4")->Stop();
				if (GameData::stage4 == 1)
				{
					GameData::end_score += 1;
					GameData::stage4 = 0;
				}
				break;
			case 5:
				SOUND("stage5")->Stop();
				if (GameData::stage5 == 1)
				{
					GameData::end_score += 1;
					GameData::stage5 = 0;
				}
				break;
			}
				//�Q�[���N���A��ʕ\��
				drawclear = true;
				GameData::Gameclear = true;
				
				//�`���|�g���A�����烁�j���[
				if (GameData::s_score == 0)
				{
					Base::KillAll();
					Base::m_pose = false;
					Base::Add(new Menu());
				}
				else 
				{
					//���ׂẴX�e�[�W���N���A������G���h���[��
					if (GameData::end_score == 5)
					{
						//EndRoll���Q�[�����ɂȂ����(��ɐ�������邽��1��̂ݐ���)
						if (!Base::FindObject(eType_EndRoll))
						{
							KillAll();
							Base::Add(new EndRoll(CVector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT)));
							
						}
						
					}
					else
					{
						if (PUSH(CInput::eButton1))
						{
							GameData::zanki = 3;
							SetKill();
							Base::Kill(1 << eType_Goal
								| 1 << eType_Player
								| 1 << eType_count
								| 1 << eType_Scene);
						    Base::m_pose = false;
							Base::Add(new Menu());
						}
					}


				}
	}
	//�v���C���[��Kill���ꂽ��
		if (!Base::FindObject(eType_Player) && !GameData::Gameclear)
		{
			//�c�@���܂�����Ε`��ł���
			if (GameData::zanki != 0)

				drawretry = true;

			if (PUSH(CInput::eButton1))
			{
				//���g���C������̃J�E���g���Z�b�g
				Base* b = Base::FindObject(eType_count);
				count* c = dynamic_cast<count*>(b);
				c->SetCount(180 * 60);

				//�v���C���[�̊e�X�e�[�W�̃��X�|�[���ʒu

				switch (GameData::s_score)
				{
				case 1:
					Base::Add(new Player(CVector2D(200, 900), true));
					break;

				case 2:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 3:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 4:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 5:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 6:
					Base::Add(new Player(CVector2D(70, 70), true));
					break;

				case 7:
					Base::Add(new Player(CVector2D(100, 200), true));
					break;

				case 8:
					Base::Add(new Player(CVector2D(100, 200), true));
					break;

				case 9:
					Base::Add(new Player(CVector2D(1800, 900), true));
					break;

				case 10:
					Base::Add(new Player(CVector2D(100, 900), true));
					break;

				}
				drawretry = false;
			}
		}
		
	}
}

void Game::Draw()
{
	//stage7��Goal�B��
	if (GameData::s_score==7)
		m_kakusu.Draw();

	//stage9�̃f�R�C
	if (GameData::s_score == 9)
	{
		m_Goal1.Draw();
		m_Goal2.Draw();
		m_Goal3.Draw();
	}
	//�Q�[�����̈ꎞ��~
	if (PUSH(CInput::eButton10)) 
	{
		m_pose = !m_pose;
	}
	if (m_pose) 
	{
		if (PUSH(CInput::eButton1))
		{
			Base::KillAll();
			Base::m_pose = false;
			//�Q�[���I�[�o�[�ɂȂ�ƃ��j���[��ʂɖ߂�
				Base::Add(new Menu());
				GameData::s_score = 1;
				GameData::zanki = GameData::Zanki_set;
				GameData::Gameclear = false;
				GameData::Gameover = false;
		}

	}
	//�c�@�`��
	if(GameData::s_score!=0)
	for (int i = 0; i < GameData::zanki; i++)
	{ 
		zankiimg[i].SetPos(10+80*i, 10);
		zankiimg[i].Draw();
	}
	
	
	//�X�e�[�W�N���A��ʕ`��
	if (drawclear)
	{
		clearimg.Draw();
	}
	//���g���C��ʕ`��
	if(drawretry)
	{
			retryimg.Draw();
	}
	
	
	//�Q�[���I�[�o�[�֘A
	if (GameData::Gameover)
	{
		Base::Kill(1 << eType_AreaChange
			| 1 << eType_Goal
			| 1 << eType_Block);
		outimg.SetSize(1000, 700);
		outimg.SetPos(440, 200);
		outimg.Draw();
		if (PUSH(CInput::eButton1))
		{
			switch (GameData::s_score) {
			case 0:
				SOUND("Tutorial")->Stop();
				break;
			case 1:
				SOUND("stage1")->Stop();
				break;

			case 2:
				SOUND("stage2")->Stop();
				break;

			case 3:
				SOUND("stage3")->Stop();
				break;

			case 4:
				SOUND("stage4")->Stop();
				break;
			case 5:
				SOUND("stage5")->Stop();
				break;
			}
			Base::KillAll();
			Base::m_pose = false;
			//�Q�[���I�[�o�[�ɂȂ�ƃ��j���[��ʂɖ߂�
			Base::Add(new Menu());
			GameData::s_score = 1;
			GameData::zanki = GameData::Zanki_set;
			GameData::Gameclear = false;
			GameData::Gameover = false;
			
		}
	}
	//�ꎞ��~�摜�̕`��
	if (m_pose)
	{
		stopimg.Draw();
	}
	//�X�L�b�v��ʕ`��
	if (GameData::s_score ==0)
	{
		skipimg.Draw();
	}
}

