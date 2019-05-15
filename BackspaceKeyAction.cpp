//BackspaceKeyAction.cpp
/*
���ϸ� : BackspaceKeyAction.cpp
�ۼ����� : 2019�� 04�� 17��
�ۼ��� : �迵��
��� : �齺���̽� Ű
���� :
*/

#include "BackspaceKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"

BackspaceKeyAction::BackspaceKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
}

BackspaceKeyAction::~BackspaceKeyAction() {
}

void BackspaceKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long lineCurrent;
	Long memoCurrent;
	Long ret;
	Long cloneLength;
	Long i = 0;
	Glyph *previous;
	Glyph *letter;
	Long lineLength;

	lineCurrent = this->codeEditorForm->current->GetCurrent();
	lineLength = this->codeEditorForm->current->GetLength();

	if (lineCurrent > 0) {
		this->codeEditorForm->current->Remove(lineCurrent - 1);

		if (this->codeEditorForm->current->GetCurrent() < this->codeEditorForm->current->GetLength()) {
			this->codeEditorForm->current->Previous();
		}
	}
	else {
		memoCurrent = this->codeEditorForm->memo->GetCurrent();
		previous = this->codeEditorForm->current;
		ret = this->codeEditorForm->memo->Previous();

		if (ret != memoCurrent) {
			this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(ret);
			lineLength = this->codeEditorForm->current->GetLength(); //�����߰� else�� current�� Length�� if�� current�� Length�� ��뷮�� �ٸ� 
			cloneLength = previous->GetLength();

			while (i < cloneLength) {
				letter = previous->GetAt(i);
				this->codeEditorForm->current->Add(letter->Clone());
				i++;
			}

			this->codeEditorForm->memo->Remove(ret + 1);
			this->codeEditorForm->current->Move(lineLength); // �����߰� �齺���̽��� �������� ���� �� �������� ��뷮���� ĳ�� �̵�
		}
	}
}