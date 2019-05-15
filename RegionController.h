#pragma once
/*
���ϸ�: Region
�ۼ��� : 2019��05��09��
�ۼ��� : �����
���: ������ �����.
���� :
*/
//Region.h
#ifndef _REGIONCONTROLLER_H
#define _REGIONCONTROLLER_H
#include <afxwin.h>
#include <string>
using namespace std;

typedef signed long int Long;
class CodeEditorForm;
class Glyph;
class RegionController {
public:
	RegionController();
	RegionController(CodeEditorForm* codeEditorForm);
	~RegionController();
	HRGN MakeRegion(Glyph* previousLine, Glyph* nextLine, Long previousMemoNumber, Long nextMemoNumber);
	void DrawRegion();
	void CleanRegion();
	bool GetIsBeing() const;
	//CRgn GetSelectedRgn() const;

public:
	CodeEditorForm *codeEditorForm;

	Long standardX;
	Long secondStandardX;
	Long standardY;
	Long secondStandardY;

	CRgn printRgn;
	CRgn firstRgn;
	CRgn secondRgn;
	CRgn thirdRgn;

	COLORREF backgroundColor;
	COLORREF letterColor;
	HBRUSH brush;
	string contents;
	bool isBeing = FALSE;
};

inline bool RegionController::GetIsBeing() const {
	
	return this->isBeing;
}



#endif //_REGIONCONTROLLER_H