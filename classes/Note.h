#pragma once
#ifndef _NOTE_H_
#define _NOTE_H_
#include <iostream>
#include <string>
#include <fstream>
class Note
{
private:
	std::wstring name;
	std::wstring file_Name;
	long num_Of_Chars = 0;
	long num_Of_Words = 0;
	unsigned num_Of_Strings = 4;
	unsigned cur_String = 0;
	std::wstring* note = nullptr;
	friend std::wostream& operator<<(std::wostream& os, Note& note);
	friend std::wistream& operator>>(std::wistream& is, Note& note);
	void saveTechInfo();

	void ResizeNote();

	//former settings
	static wchar_t* dir;
	static wchar_t* techFile;
	static std::wstring* File_Names;
	static int cur_File;
	static int end_File_Names;
	static void ResizeFile_Names();

public:
	Note(std::wstring fileName);
	Note(std::wstring name, std::wstring fileName);
	~Note();

	unsigned getNumOfStrings();
	unsigned getCurrentString();

	std::wstring getFileName();
	std::wstring getName();
	int wstr_cpy(std::wstring& str);
	void saveToFile(std::wfstream* fs);
	void loadFile(const wchar_t* fileName);
	int writeNote();
	int readNote();


	//former settings
	static void setDir(wchar_t* dir);
	static wchar_t* getDir();

	static int openWFileStream(const wchar_t* file_Name, std::wfstream* fs);
	static void loadFileNames();
	static void saveFileNames(Note notes[], unsigned len);
};



std::wostream& operator<<(std::wostream& os, Note& note);
std::wistream& operator>>(std::wistream& is, Note& note);
#endif