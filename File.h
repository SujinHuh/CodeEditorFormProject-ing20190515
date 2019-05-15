/*
���ϸ� : File.h
�ۼ����� : 2019�� 04�� 02��
�ۼ��� : �迵��
��� : ���� Ŭ���� (������)
���� :
*/

#pragma once

#ifndef _FILE_H
#define _FILE_H

#include <string>
using namespace std;
class CodeEditorForm;
class File {
public:
	File();
	File(string pathName, string fileName);
	File(const File& source);
	~File();
	void Save(string constents, string pathName);
	string Load(string pathName);
	void OpenDialog(bool isOpen);
	File& operator=(const File& source);
	string GetPathName() const;
	string GetFileName() const;

private:
	CodeEditorForm *codeEditorForm;
	string pathName;
	string fileName;
};

inline string File::GetPathName() const {
	return this->pathName;
}

inline string File::GetFileName() const {
	return this->fileName;
}

#endif //_FILE_H