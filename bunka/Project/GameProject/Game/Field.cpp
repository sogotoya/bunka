#include "Field.h"
#include "Game/Game.h"
#include "GameData.h"

Field::Field() :Base(eType_Field)
{
	m_haikei = COPY_RESOURCE("aozora", CImage);
	m_yuugata = COPY_RESOURCE("yuugata", CImage);
	m_yuugatakumo = COPY_RESOURCE("yuugatakumo", CImage);
	m_murasaki = COPY_RESOURCE("murasaki", CImage);
	m_haikei. SetSize(1920, 1080);
	m_yuugata.SetSize(1920, 1080);
	m_yuugatakumo.SetSize(1920, 1080);
	m_murasaki.SetSize(1920, 1080);
}
void Field::Draw()
{
	if(GameData::s_score==1)
		m_haikei.Draw();

	if (GameData::s_score == 2)
		m_yuugata.Draw();

	if (GameData::s_score == 3)
		m_yuugatakumo.Draw();

	if (GameData::s_score == 4)
		m_murasaki.Draw();

}