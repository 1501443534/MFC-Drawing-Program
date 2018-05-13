#pragma once
#include "WShape.h"
class WSquare :public WShape
{
public:
	int Width; //�����εı߳�
public:
	WSquare();
	WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WSquare();
	DECLARE_SERIAL(WSquare); //������WSquare��֧�����л�
};

