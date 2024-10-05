#pragma once
#ifndef _NOTE_H_
#define _NOTE_H_
#include <iostream>
#include <string>
#include <fstream>
#include "FileStream.h"
#include "Settings.h"

class Settings;

class Note
{

public:
	Note(std::wstring file, std::wstring dir = L"", std::wstring name = L"Unknown");
	~Note();

	unsigned getNumOfStrings();
	unsigned getCurrentString();

	std::wstring getDir();
	std::wstring getFileName();
	std::wstring getName();

	int wstr_cpy(std::wstring& str);
	void saveToFile();
	friend void Settings::loadNote(Note& note);
	int writeNote();
	int readNote();

private:
	FileStream fs;
	std::wstring name;
	std::wstring dir;
	std::wstring file;
	unsigned num_Of_Strings = 4;
	unsigned cur_String = 0;
	std::wstring* note = nullptr;
	friend std::wostream& operator<<(std::wostream& os, Note& note);
	friend std::wistream& operator>>(std::wistream& is, Note& note);

	void ResizeNote();
};



std::wostream& operator<<(std::wostream& os, Note& note);
std::wistream& operator>>(std::wistream& is, Note& note);
#endif