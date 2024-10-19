#include "sikaku.h"

sikaku::sikaku():Base(eType_Sikaku)
{
	m_img = COPY_RESOURCE("sikaku", CImage);
	
}

void sikaku::Draw()
{
	m_img.SetSize(MAP_TIP_SIZE*6, MAP_TIP_SIZE*3);
	m_img.Draw();
}
