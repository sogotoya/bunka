#include "Field.h"

float Field::m_ground_y = 540;
Field::Field() :Base(eType_Field)
{
	m_haikei = COPY_RESOURCE("", CImage);

	m_ground_y = 1080;



}
void Field::Draw()
{
	float sc;
	m_haikei.Draw();



}