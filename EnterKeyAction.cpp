#include "EnterKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"
#include "Line.h"

EnterKeyAction::EnterKeyAction(CodeEditorForm * codeEditorForm) :KeyAction(codeEditorForm) {
}

EnterKeyAction::~EnterKeyAction() {
}

void EnterKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Glyph *line;
	Glyph *letter;
	//Long memoCurrent;
	//Long memoLength;
	Long lineCurrent;
	Long lineLength;
	Long i;

		line = new Line;
		//memoCurrent = this->codeEditorForm->memo->GetCurrent();
		//memoLength = this->codeEditorForm->memo->GetLength();
		lineCurrent = this->codeEditorForm->current->GetCurrent();
		lineLength = this->codeEditorForm->current->GetLength();

		//���� ������ ��ġ�� ���̶�� ���� 
		if (lineCurrent == lineLength) {
			this->codeEditorForm->memo->Add(line);
		}
		else //���� �ƴ϶�� ���� �������ĸ� ����
		{
			i = lineCurrent;

			while (i < lineLength) {
				letter = this->codeEditorForm->current->GetAt(i);
				line->Add(letter->Clone());
				i++;
			}

			i = lineLength;

			while (i > lineCurrent) {
				this->codeEditorForm->current->Remove(lineCurrent);
				i--;
			}
			this->codeEditorForm->memo->Add(line, this->codeEditorForm->memo->GetCurrent() + 1);
		}
		this->codeEditorForm->current = line;
		this->codeEditorForm->current->First();
}