/*
���ϸ� : RightKeyAction.cpp
�ۼ����� : 2019�� 04�� 14��
�ۼ��� : �����
��� : RightKeyAction
*/
//RightKeyAction.cpp

/*
���ϸ� : RightKeyAction.cpp
�ۼ����� : 2019�� 04�� 15��
�ۼ��� : �迵��
��� : ������ ����Ű
���� :
*/

#include "RightKeyAction.h"
#include "CodeEditorForm.h"
#include "RegionController.h"
#include "Glyph.h"


RightKeyAction::RightKeyAction(CodeEditorForm *codeEditorForm):KeyAction(codeEditorForm) {
}

RightKeyAction:: ~RightKeyAction() {

}

void RightKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long ret;
	Long lineCurrent;
	Long memoCurrent;

	ret = this->codeEditorForm->current->GetCurrent();
	lineCurrent = this->codeEditorForm->current->Next();

	if (ret == lineCurrent) {
		ret = this->codeEditorForm->memo->GetCurrent();
		memoCurrent = this->codeEditorForm->memo->Next();
		if (memoCurrent != ret) {
			this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(memoCurrent);
			this->codeEditorForm->current->First();
		}
	}

	this->codeEditorForm->regionController->CleanRegion();
}