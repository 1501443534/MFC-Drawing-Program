#include "StdAfx.h"
#include "WSquare.h"

IMPLEMENT_SERIAL(WSquare, CObject, 1)

WSquare::WSquare()
{
	Type = (ElementType)0;
}

WSquare::WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	Width = width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}


void WSquare::Draw(CDC*pDC)
{
	//�������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//����ͼ��
	pDC->Rectangle(OrgX - Width / 2, OrgY + Width / 2, OrgX + Width / 2, OrgY - Width / 2);

	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WSquare::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;
	}
	else
		return false;

}

void WSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//�����ļ�
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Width;
	}
	else
	{
		//��ȡ�ļ�
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar >> Width;
	}
}

WSquare::~WSquare()
{
}