//CaretCoordinator.h
/*
���ϸ� : CaretCoordinator.h
�ۼ����� : 2019�� 03�� 29��
�ۼ��� : �迵��
��� : ĳ���� ��ġ�� �����Ѵ�
���� : 20190410 GetXPos �����߰�
*/

#ifndef _CARETCOORDINATOR_H
#define _CARETCOORDINATOR_H

typedef signed long int Long;

class Glyph;
class FontMatrix;
class CaretCoordinator {
public:
	CaretCoordinator();
	CaretCoordinator(const CaretCoordinator& source);
	~CaretCoordinator();
	void MakePosition(FontMatrix *fontMatrix, Glyph *line, Long column);
	Long GetFirstXPos();
	Long GetXPos(FontMatrix *fontMatrix, Glyph *line);
	Long GetLastXPos(FontMatrix *fontMatrix, Glyph *line);
	Long GetYPos(FontMatrix *fontMatrix, Long row);
	CaretCoordinator& operator=(const CaretCoordinator& source);
	Long GetX() const;
	Long GetY() const;

private:
	Long x;
	Long y;
};

inline Long CaretCoordinator::GetX()const {
	return this->x;
}

inline Long CaretCoordinator::GetY()const {
	return this->y;
}

#endif //_CARETCOORDINATOR_H