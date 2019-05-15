/*
���ϸ� : Line.h
//Line.cpp
�ۼ����� : 2019�� 03�� 27��
�ۼ��� : �����
��� : ������, ���������, �Ҹ���, , ���ڿ� �����, ������= ����
���� : 1900402 GetContents ����(Tabó��)
*/
#include "Line.h"
#include "iterator.h"


/*
�Լ��� : Line
��� : ������
*/
Line::Line(Long capacity) :Composite(capacity) {
}

/*
�Լ��� : Line
��� : ���� ������
*/
Line::Line(const Line& source) : Composite(source) {
	}

/*
�Լ��� : ~Line
��� : �Ҹ���
*/
Line::~Line() {
}


/*
�Լ��� : Add
��� : Add �������̵�
*/
Long Line::Add(Glyph* glyph) {
	if (this->capacity > this->length) {
		this->current = glyphs.Store(this->length, glyph) + 1;
	}
	else {
		this->current = glyphs.AppendFromRear(glyph) + 1;
		this->capacity++;
	}
	this->length++;
	return this->current;
}

Long Line::Add(Glyph * glyph, Long index) {
	Composite::Add(glyph, index);
	
	this->current++;

	return this->current;
}
#if 0
Long Line::Remove(Long index) {

	Long changedIndex = index - 1;

	if (this->glyphs[changedIndex] != 0) {
		delete this->glyphs[changedIndex];
	}

	this->glyphs.Delete(changedIndex);
	this->capacity--;
	this->length--;

	if (this->length > 0 && this->current > this->length - 1) {
		this->current--; //--�� ����
	}
	//�߰�
	else if (this->length <= 0) {
		this->current = 0;
	}

	return -1;
}
#endif
/*
�Լ��� : LeftWord
��� : �������� �� �ܾ� �̵�
*/
Long Line::LeftWord() {
	Glyph *letter;
	string contents;

	if (this->current == 0) {
		this->current++;
	}

	letter = this->glyphs.GetAt(this->current - 1);
	contents = letter->GetContents();

	while (this->current > 0 && contents[0] == ' ') {
		this->Previous();
		if (this->current > 0) {
			letter = this->glyphs.GetAt(this->current - 1);
			contents = letter->GetContents();
		}
	}
	while (this->current > 0 && contents[0] != ' ') {
		this->Previous();
		if (this->current > 0) {
			letter = this->glyphs.GetAt(this->current - 1);
			contents = letter->GetContents();
		}
	}

	return this->current;
}

/*
�Լ��� : RightWord
��� : ���������� �� �ܾ� �̵�
*/
Long Line::RightWord() {
	Glyph *letter;
	string contents;

	if (this->current < this->length)
	{
		letter = this->glyphs.GetAt(this->current);
		contents = letter->GetContents();
	}

	while (this->current < this->length && contents[0] != ' ') {
		this->Next();
		if (this->current < this->length)
		{
			letter = this->glyphs.GetAt(this->current);
			contents = letter->GetContents();
		}
	}

	while (this->current < this->length && contents[0] == ' ') {
		this->Next();
		letter = this->glyphs.GetAt(this->current);
		if (this->current < this->length)
		{
			letter = this->glyphs.GetAt(this->current);
			contents = letter->GetContents();
		}
	}

	return this->current;
}

/*
�Լ��� : Clone
��� : �����Ѵ�
*/
Glyph* Line::Clone() {
	return new Line(*this);
}

/*
�Լ��� : Getcontent
��� : ���ڸ� �����´�.
*/
string Line::GetContent() {
	Glyph *letter;

	letter = this->GetAt(this->current - 1);
	
	return letter->GetContents();
}

/*
�Լ��� : Getcontents
��� : ���ڿ��� �����
*/
string Line::GetContents() {
	string text = "";
	string contents;

	Iterator<Glyph*>*iterator = this->CreateItorator();

	for (iterator->First(); !iterator->IsDone(); iterator->Next()) {
		
		contents = iterator->CurrentItem()->GetContents();
		
		text += contents;
	}
	return text;
}


/*
�Լ��� : operator=
��� : ġȯ ������
*/
Line& Line::operator=(const Line& source) {
	Composite::operator=(source);
	return *this;
}