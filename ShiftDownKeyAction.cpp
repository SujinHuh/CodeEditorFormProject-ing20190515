//ShiftDownKeyAction.cpp

/*
���ϸ� : ShiftDownKeyAction.cpp
�ۼ����� : 2019�� 05�� 14��
�ۼ��� : 
��� : �Ʒ��� ���ÿ��� ����
���� :
*/

#include "ShiftDownKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"
#include "CaretCoordinator.h"
#include "RegionController.h"

//�Ű������� �ִ� ������
ShiftDownKeyAction::ShiftDownKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
}

//�Ҹ���
ShiftDownKeyAction::~ShiftDownKeyAction() {
}

void ShiftDownKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long previousX;
	Long currentX;
	Long memoCurrent;
	Long lineCurrent;
	Long lineLength;
	Long previous;
	CaretCoordinator caretCoordinator;
	Glyph* previousLine;
	Glyph* nextLine;
	Long previousMemoCurrent, nextMemoCurrent;

	previousMemoCurrent = this->codeEditorForm->memo->GetCurrent();
	previousLine = this->codeEditorForm->current->Clone();

	previousX = caretCoordinator.GetXPos(this->codeEditorForm->GetFontMatrix(), this->codeEditorForm->current);
	previous = this->codeEditorForm->memo->GetCurrent();
	memoCurrent = this->codeEditorForm->memo->Next();

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

	nextMemoCurrent = this->codeEditorForm->memo->GetCurrent();
	nextLine = this->codeEditorForm->current->Clone();

	this->codeEditorForm->regionController->MakeRegion(previousLine, nextLine, previousMemoCurrent, nextMemoCurrent);
}