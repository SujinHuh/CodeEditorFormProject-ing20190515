//CaretCoordinator.cpp
/*
���ϸ� : CaretCoordinator.cpp
�ۼ����� : 2019�� 03�� 29��
�ۼ��� : �迵��
��� : ĳ���� ��ġ����
���� :
*/

#include "CaretCoordinator.h"
#include "Glyph.h"
#include "FontMatrix.h"
#include "SingleByteLetter.h"
#include "DoubleByteLetter.h"
#include <string>
using namespace std;

/*
�Լ���: CaretCoordinator
���: ������
*/
CaretCoordinator::CaretCoordinator()
{
	this->x = 0;
	this->y = 0;
}

/*
�Լ���: CaretCoordinator
���: ���������
*/
CaretCoordinator::CaretCoordinator(const CaretCoordinator& source) {
	this->x = source.x;
	this->y = source.y;
}

/*
�Լ���: ~CaretCoordinator
���: �Ҹ���
*/
CaretCoordinator::~CaretCoordinator() {
}

/*
�Լ���: MakePosition
���: ��ġ�� ����٤�
����: 20190407 x��ǥ ���ϴ� �ݺ��� ����
*/
void CaretCoordinator::MakePosition(FontMatrix *fontMatrix, Glyph *line, Long row) {

	this->GetXPos(fontMatrix, line);
	this->GetYPos(fontMatrix, row);
}


/*
�Լ���: GetFirstXPos
���: ù��° ��ġ�� X �� ���Ѵ�.
����:
*/
Long CaretCoordinator::GetFirstXPos()
{
	this->x = 0;

	return x;
}


/*
�Լ���: GetXPos
���: ���� ��ġ�� ���� ���Ѵ�
����: 
*/
Long CaretCoordinator::GetXPos(FontMatrix *fontMatrix, Glyph *line) {
	Long i = 0;
	Glyph *letter;
	string content;
	Long code;

	this->x = 0;
	while (i < line->GetCurrent()) {
		letter = line->GetAt(i);
		if (dynamic_cast<SingleByteLetter*>(letter)) {
			content = letter->GetContents();
			code = content.at(0);
			this->x += fontMatrix->GetSingleByteWidth(code);
		}
		else if (dynamic_cast<DoubleByteLetter*>(letter)) {
			this->x += fontMatrix->GetDoubleByteWidth();
		}
		i++;
	}

	return this->x;
}

/*
�Լ���: GetLastXPos
���: ������ ��ġ�� X�� ���Ѵ�.
����:
*/
Long CaretCoordinator::GetLastXPos(FontMatrix * fontMatrix, Glyph * line)
{
	Long i = 0;
	Glyph *letter;
	string content;
	Long code;

	this->x = 0;
	while (i < line->GetLength()) {
		letter = line->GetAt(i);
		if (dynamic_cast<SingleByteLetter*>(letter)) {
			content = letter->GetContents();
			code = content.at(0);
			this->x += fontMatrix->GetSingleByteWidth(code);
		}
		else if (dynamic_cast<DoubleByteLetter*>(letter)) {
			this->x += fontMatrix->GetDoubleByteWidth();
		}
		i++;
	}

	return this->x;
}

Long CaretCoordinator::GetYPos(FontMatrix * fontMatrix, Long row) {

	this->y = row * (fontMatrix->GetHeight());

	return this->y;
}

/*
�Լ���: operator=
���: ġȯ������
*/
CaretCoordinator& CaretCoordinator::operator=(const CaretCoordinator& source) {
	this->x = source.x;
	this->y = source.y;
	
	return *this;
}