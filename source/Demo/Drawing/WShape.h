#pragma once
enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT};
class WShape:public CObject
{
public:
	ElementType Type; //ͼԪ����
	int OrgX; //�߼����� X
	int OrgY; //�߼����� Y
	COLORREF BorderColor; //�߿���ɫ
	int BorderType; //�߿����ͣ�ʵ�ߣ����ߣ�����ߣ�
	int BorderWidth; //�߿���
	COLORREF FillColor; //�����ɫ
	int FillType; //������ͣ�ʵ�ģ�˫�Խǣ� ʮ�ֽ��棩
public:
	WShape();
	virtual void Draw(CDC* pDC) = 0; // ����ͼԪ����
	virtual bool IsMatched(CPoint pnt) = 0; // �ж������Ƿ�����ͼ����
	virtual void Serialize(CArchive& ar) = 0; // ���л�����
	void SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType); //�ı�ͼ�����Ա���
	virtual ~WShape();
};

