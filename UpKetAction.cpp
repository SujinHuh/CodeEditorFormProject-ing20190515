//UpKeyAction.cpp
/*
���ϸ� : UpKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : ���� ����Ű
���� :
*/

#include "UpKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"
#include "CaretCoordinator.h"

//�Ű������� �ִ� ������
UpKeyAction::UpKeyAction(CodeEditorForm *codeEditorForm):KeyAction(codeEditorForm){
}

//�Ҹ���
UpKeyAction::~UpKeyAction() {
}


void UpKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long previousX;
	Long currentX;
	Long memoCurrent;
	Long lineCurrent;
	Long lineLength;
	Long previous;
	CaretCoordinator caretCoordinator;

	previousX = caretCoordinator.GetXPos(this->codeEditorForm->GetFontMatrix(), this->codeEditorForm->current);
	previous = this->codeEditorForm->memo->GetCurrent();
	memoCurrent = this->codeEditorForm->memo->Previous();

	if (memoCurrent != previous) {
		this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(memoCurrent);
		this->codeEditorForm->current->First();
		lineLength = this->codeEditorForm->current->GetLength();
		lineCurrent = this->codeEditorForm->current->GetCurrent();
		currentX = caretCoordinator.GetXPos(this->codeEditorForm->GetFontMatrix(), this->codeEditorForm->current);

		while (currentX < previousX && lineCurrent != lineLength) {
			lineCurrent = this->codeEditorForm->current->Next();
			currentX = caretCoordinator.GetXPos(this->codeEditorForm->GetFontMatrix(), this->codeEditorForm->current);
		}
	}
}