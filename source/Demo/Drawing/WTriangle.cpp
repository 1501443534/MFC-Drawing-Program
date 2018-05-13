#include "StdAfx.h"
#include "WTriangle.h"
#include <math.h>

IMPLEMENT_SERIAL(WTriangle, CObject, 1)//ʵ����WSquare�����л���ָ���汾Ϊ1

WTriangle::WTriangle()
{
	Type = (ElementType)4;//ͼԪ����
}


WTriangle::WTriangle(int orgX, int orgY, int length, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)4;//ͼԪ����
	OrgX = orgX;
	OrgY = orgY;
	Length = length;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}


void WTriangle::Draw(CDC*pDC)
{
	// �������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//����ͼ��
	double x1 = double(OrgX), y1 = double(OrgY) + double(Length) / SQRT3;
	double x2 = double(OrgX) - double(Length) / 2, y2 = double(OrgY) - double(Length) / (2 * SQRT3);
	double x3 = double(OrgX) + double(Length) / 2, y3 = double(OrgY) - double(Length) / (2 * SQRT3);
	CPoint points[3] = { CPoint(int(x1), int(y1)), CPoint(int(x2), int(y2)), CPoint(int(x3), int(y3))};
	pDC->Polygon(points, 3);

	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WTriangle::IsMatched(CPoint pnt)
{
	CRgn rgn ;
	CPoint ptVertex[3];
	ptVertex[0].x = long(OrgX - Length / 2);
	ptVertex[0].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	ptVertex[1].x = long(OrgX);
	ptVertex[1].y = long(OrgY - (sqrt(1.0 / 3)) * Length);
	ptVertex[2].x = long(OrgX + (Length / 2));
	ptVertex[2].y = long(OrgY + (sqrt(1.0 / 12)) * Length);
	rgn.CreatePolygonRgn(ptVertex , 3 , ALTERNATE);

	BOOL flag= rgn.PtInRegion(pnt);
	if (flag)
	{
		return true;		
	}	
	else
		return false;

}

void WTriangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//�����ļ�
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Length;
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
		ar >> Length;
	}
}

WTriangle::~WTriangle()
{
}
