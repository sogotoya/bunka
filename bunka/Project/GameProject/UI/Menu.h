#pragma once
#include "Base/Base.h"

class Menu :public Base
{
	//���j���[�g�֘A
	class Waku :public Base
	{
	private:
		CImage m_sute;
		//�X�e�[�W�P
		CImage m_stagewaku1;
		int m_stagen;

	public:
		
		Waku(char* imgname,CVector2D pos, int stagen);
		void Update();
		void Draw();
	};

private:
	CImage m_menu;
	Waku *m_waku[10];

public:
	Menu();
	void Update();
	void Draw();
};