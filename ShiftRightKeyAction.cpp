
/*
���ϸ� : ShiftRightKeyAction.cpp
�ۼ����� : 2019�� 05�� 02��
�ۼ��� : �迵��
��� : ����Ʈ ������ ����Ű ���ÿ��� ����
���� :
*/

#include "ShiftRightKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"
#include "FontMatrix.h"
#include "CaretCoordinator.h"
#include "RegionController.h"

ShiftRightKeyAction::ShiftRightKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
	
}

ShiftRightKeyAction:: ~ShiftRightKeyAction() {

}

void ShiftRightKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	
	Glyph* previousLine;
	Glyph* nextLine;
	Long previousMemoCurrent, nextMemoCurrent;
	Long previousLineCurrent, nextLineCurrent;

	previousMemoCurrent = this->codeEditorForm->memo->GetCurrent();
	previousLine = this->codeEditorForm->current->Clone();

	previousLineCurrent = this->codeEditorForm->current->GetCurrent();
	nextLineCurrent = this->codeEditorForm->current->Next();
	
	if (previousLineCurrent == nextLineCurrent) {
		previousMemoCurrent = this->codeEditorForm->memo->GetCurrent();
		nextMemoCurrent = this->codeEditorForm->memo->Next();
		if (previousMemoCurrent != nextMemoCurrent) {
			this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(this->codeEditorForm->current->GetCurrent());
			this->codeEditorForm->current->First();
		}
	}

	nextMemoCurrent = this->codeEditorForm->memo->GetCurrent();
	nextLine = this->codeEditorForm->current->Clone();

	this->codeEditorForm->regionController->MakeRegion(previousLine, nextLine, previousMemoCurrent, nextMemoCurrent);

	this->codeEditorForm->Invalidate();
}