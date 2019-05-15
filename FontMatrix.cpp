//FontMatrix.cpp
/*���ϸ�: FontMatrix.cpp
	�ۼ����� : 2019�� 03�� 29��
	�ۼ��� : �迵��
	��� : ��Ʈ�� �ʺ�� ���̸� ���Ѵ�.
	���� :
	*/

#include "FontMatrix.h"
#include <string>
using namespace std;

/*
�Լ��� : FontMatrix
��� : �Ű����� ������
���� : �� ���� ����
*/
FontMatrix::FontMatrix(CDC *dc) {
	char code[3] = { 0, };
	int i;
	CSize sz;

	for (i = 1; i < 129; i++) {
		code[0] = i;
		sz = dc->GetTextExtent(code);
		this->widths[i] = (BYTE)sz.cx;
	}

	this->widths[0] = 0;

	strcpy(code, "��");
	sz = dc->GetTextExtent(code);
	this->widths[129] = (BYTE)sz.cx;
	this->height = sz.cy;

}

/*
�Լ��� : FontMatrix
��� : ���� ������
*/
FontMatrix::FontMatrix(const FontMatrix& source) {
	Long i;
	
	for (i = 0; i < 129; i++) {
		this->widths[i] = source.widths[i];
	}
	this->height = source.height;
}

/*
�Լ��� : ~FontMatrix
��� : �Ҹ���
*/
FontMatrix::~FontMatrix() {
}

/*
�Լ��� : GetSingleByteWidth
��� : widths���� width�� �����´�
*/
Long FontMatrix::GetSingleByteWidth(Long code) {
	return this->widths[code];
}

/*
�Լ��� : GetDoubleByteWidth
��� : widths���� width�� �����´�
*/
Long FontMatrix::GetDoubleByteWidth() {
	return this->widths[129];
}

/*
�Լ��� : GetLetterHeight
��� : height�� �����´�
*/
Long FontMatrix::GetLetterHeight() {
	return this->height;
}

/*
�Լ��� : operator=
��� : ġȯ ������
*/
FontMatrix& FontMatrix::operator=(const FontMatrix& source) {
	Long i;
	
	for (i = 0; i < 129; i++) {
		this->widths[i] = source.widths[i];
	}
	this->height = source.height;

	return *this;
}