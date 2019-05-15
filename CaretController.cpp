//CaretController.cpp
/*
���ϸ� : CaretController.cpp
�ۼ����� : 2019�� 03�� 29��
�ۼ��� : ���α�
��� : ĳ������ Ŭ�������� �����ϴ� Ŭ����
���� : 20190410 GetXPosCaret �����߰�
*/

#include "CaretController.h"
#include "CodeEditorForm.h"
#include "FontMatrix.h"
#include "Caret.h"
#include "CaretCoordinator.h"
#include "Memo.h"

/*
�Լ��� : CaretController
��� : ����Ʈ������
*/
CaretController::CaretController() {
	this->codeEditorForm = 0;
	this->caret = 0;
	this->caretCoordinator = 0;
	this->line =0;
	this->row = 0;
}

/*
�Լ��� : CaretController
��� : �Ű������� ������ ������
*/
CaretController::CaretController(CodeEditorForm *codeEditorForm, Glyph *line, Long row) {
	this->codeEditorForm = codeEditorForm;
	this->caret = new Caret(this->codeEditorForm);
	this->caretCoordinator = new CaretCoordinator;
	this->line = line;
	this->row = row;
	this->codeEditorForm->Add(this);
}

/*
�Լ��� : CaretController
��� : ���������
*/
CaretController::CaretController(const CaretController& source) {
	this->codeEditorForm = source.codeEditorForm;
	this->caretCoordinator = source.caretCoordinator;
	this->caret = source.caret;
	this->line = source.line;
	this->row = source.row;
}

/*
�Լ��� : ~CaretController
��� : �Ҹ���
����: 20190407 caret,caretCoordinator ���� �Ҵ�����
*/
CaretController::~CaretController() {
	
	delete caret;
	delete caretCoordinator;
}

/*
�Լ��� : MakeCaret
��� : ĳ���� �����.
*/
void CaretController::MakeCaret() {
	Long width=2;
	Long height;

	
	if (this->codeEditorForm->GetIsComposing() == TRUE) {
		width -= this->codeEditorForm->GetFontMatrix()->GetDoubleByteWidth();
	}
	height = this->codeEditorForm->GetFontMatrix()->GetHeight();
	
	this->caret->Make(width, height);
}

/*
�Լ���: MoveCaret
��� : ĳ���� �̵��Ѵ�.
����: 20190407 �ŰԺ��� ���, �����͸���� ����ϵ��� ����
*/
void CaretController::MoveCaret() {
	Long x;
	Long y;

	this->caretCoordinator->MakePosition(this->codeEditorForm->GetFontMatrix(), this->line, this->row);
	x = this->caretCoordinator->GetX();
	y = this->caretCoordinator->GetY();
	this->caret->Move(x, y);
}

/*
�Լ���: ShowCaret
��� : ĳ���� �����ְų� �����.
*/
void CaretController::ShowCaret(bool isShow) {
	this->caret->Show(isShow);
}

/*
�Լ���: DeleteCaret
��� : ĳ���� �����Ѵ�.
*/
void CaretController::DeleteCaret() {
	
	this->caret->Delete();
}

/*
�Լ���: GetXPosCaret
��� : ���� ��ġ�� ���� ���Ѵ�
*/
Long CaretController::GetXPosCaret() {
	Long xPos;
	
	xPos = this->caretCoordinator->GetXPos(this->codeEditorForm->GetFontMatrix(), this->line);

	return xPos;
}

/*
�Լ���: Update
��� : line�� column�� ������Ʈ �Ѵ�.
���� : MakeCaret, MoveCaret, ShowCaret �߰�
*/
void CaretController::Update() {
	this->row = this->codeEditorForm->memo->GetCurrent();
	this->line = this->codeEditorForm->memo->GetAt(this->row);

	this->MakeCaret();
	this->MoveCaret();
	this->ShowCaret(TRUE);
}

/*
�Լ���: operator=
��� : ġȯ ������
*/
CaretController& CaretController::operator=(const CaretController& source) {
	this->codeEditorForm = source.codeEditorForm;
	this->caretCoordinator = source.caretCoordinator;
	this->caret = source.caret;
	this->line = source.line;
	this->row = source.row;

	return *this;
}