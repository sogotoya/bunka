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

Game::Game()
	:Base(eType_Scene)
{
	//����
	Base::Add(new Field());
	//�v���C���[�̊e�X�e�[�W�̃X�|�[���ʒu
	switch (GameData::s_score)
	{
	case 0:
		Base::Add(new Player(CVector2D(200, 900), true));
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
	stopimg.SetPos(770, 400);
	clearimg.SetSize(1550, 745);
	clearimg.SetCenter(50, 100);
	clearimg.SetPos(230, 240);
	skipimg.SetSize(500,190);
	skipimg.SetPos(700,200);
	drawclear = false;
	drawretry = false;
	drawone = false;
	GameData::Gameclear = false;
	//�c�@���R�ɃZ�b�g
	for(int i=0;i<3;i++)
	zankiimg[i].SetSize(75, 75);
	switch (GameData::s_score) {
	case 0:
		SOUND("Tutorial")->Play();
		break;
	case 1:
		SOUND("stege1")->Play();
		break;
	case 2:
		SOUND("stege2")->Play();
		break;
	case 3:
		SOUND("stege3")->Play();
		break;
	case 4:
		SOUND("stege4")->Play();
		break;
		/*case 5:
			SOUND("stege5")->Play();
			break;*/
	}


}

void Game::Update()
{
	if (GameData::s_score == 0)
	{
		if (PUSH(CInput::eButton1)) {
			Base::KillAll();
			Base::Add(new Menu());
		}
	}
	if(Base*b=Base::FindObject(eType_Goal))
	{
		Goal* g = dynamic_cast<Goal*>(b);
		if (g->GetGoal())
		{
				//�Q�[���N���A��ʕ\��
				drawclear = true;
				GameData::Gameclear = true;
				//�`���|�g���A�����烁�j���[
				if (GameData::s_score == 0)
				{
					Base::KillAll();
					Base::Add(new Menu());
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
						Base::Add(new Menu());

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
				}
				drawretry = false;
			}
		}
	}
	/*switch (GameData::s_score)
	{
	case 4:
		SOUND("stage2")->Stop();
	}*/
	//�X�e�[�W���N���A������
	/*if (GameData::clear)
	{

		if (PUSH(CInput::eButton1))
		{
			GameData::zanki = 3;
			GameData::clear = false;
			SetKill();
			Base::Kill(1 << eType_Goal
				| 1 << eType_Player
				| 1 << eType_count
				| 1	<< eType_Scene);
			Base::Add(new Menu());
		}
		if (GameData::Gameclear)
		{
			//�X�e�[�W�N���A����ƕ`��
			drawone = true;
			//eButton1�Ŏ��̃}�b�v��
			if (PUSH(CInput::eButton1))
			{
				Base::Kill(1 << eType_Map
					| 1 << eType_AreaChange
					| 1 << eType_Goal
					| 1 << eType_count
					| 1 << eType_Block);
				if (GameData::s_score <= 3)
				{
					Base::Kill(1 << eType_Player);
				}

				GameData::s_score++;
				GameData::Gameclear = false;
				GameData::zanki = GameData::Zanki_set;
				//s_score�ɘA������Map����
				Base::Add(new Map(GameData::s_score));

				Base::Add(new count(CVector2D(500, 0)));
			}

			//�e�X�e�[�W�N���A��̎�Player�̏o���ʒu
			switch (GameData::s_score)
			{

			case 2:
				//�}�b�v�Q��Player�̏o���ʒu
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;

			case 3:
				//�}�b�v�R��Player�̏o���ʒu
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;
			case 4:
				//�}�b�v4��Player�̏o���ʒu
				Base::Add(new Player(CVector2D(1800, 900), true));
				break;
			}

		}
	}*/
	
	
}

void Game::Draw()
{
	//�Q�[�����̈ꎞ��~
	if (PUSH(CInput::eButton10))
		m_pose = !m_pose;
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
			Base::KillAll();
		
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
	skipimg.Draw();
}

