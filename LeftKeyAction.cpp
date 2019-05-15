//LeftKeyAction.cpp

/*
���ϸ� : LeftKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : ���� ����Ű
���� :
*/

#include "LeftKeyAction.h"
#include "CodeEditorForm.h"
#include "RegionController.h"
#include "Glyph.h"

LeftKeyAction::LeftKeyAction(CodeEditorForm *codeEditorForm) 
	:KeyAction(codeEditorForm) {
}

LeftKeyAction:: ~LeftKeyAction() {
}

void LeftKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long ret;
	Long lineCurrent;
	Long memoCurrent;

	ret = this->codeEditorForm->current->GetCurrent();
	lineCurrent = this->codeEditorForm->current->Previous();

	if (ret == lineCurrent) {
		ret = this->codeEditorForm->memo->GetCurrent();
		memoCurrent = this->codeEditorForm->memo->Previous();

		if (ret != memoCurrent) {
			this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(memoCurrent);
			this->codeEditorForm->current->Last();
		}
	}

	this->codeEditorForm->regionController->CleanRegion();
}