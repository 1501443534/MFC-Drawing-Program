#pragma once
#include "WShape.h"
class WRectangle :public WShape
{
public:
	int Width;//���εĿ�
	int Height;//���εĸ�
public:
	WRectangle();
	WRectangle(int orgX, int orgY, int width, int height, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WRectangle();
	DECLARE_SERIAL(WRectangle); //������WRectangle��֧�����л�
};

