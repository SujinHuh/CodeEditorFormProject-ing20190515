/*
���ϸ� : Caret.h
�ۼ����� : 2019�� 03�� 29��
�ۼ��� : �迵��
��� :
���� :
*/

#pragma once
//Caret.h
#ifndef _CARET_H
#define _CARET_H

typedef signed long int Long;

class CodeEditorForm;
class Caret {
public:
	Caret();
	Caret(CodeEditorForm *CodeEditorForm, Long width = 0, Long height= 0);
	Caret(const Caret& source);
	~Caret();
	void Make(Long width, Long height);
	void Move(Long x, Long y);
	void Show(bool isShow);
	void Delete();
	Caret & operator=(const Caret & source);
	Long GetWidth() const;
	Long GetHeight() const;

private:
	CodeEditorForm *codeEditorForm;
	Long width;
	Long height;
	bool isShow;
};

inline Long Caret::GetWidth()const {
	return this->width;
}
inline Long Caret::GetHeight()const {
	return this->height;
}

#endif //_CARET_H