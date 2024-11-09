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
	Note(std::wstring name = L"Unknown", std::wstring dir = L"");
	~Note();

	unsigned getCapacity();
	unsigned getSize();

	const std::wstring& getFile();
	const std::wstring& getName();
	const std::string& getHash();
	static std::wstring getVault();
	void saveNote();
	friend void Settings::loadNote(Note&);
	void load();
	void save();
	int write(std::wstring&);
	const std::wstring& operator[](unsigned num);
	void reOpenFileStream();
	void Resize(unsigned);
private:
	static std::wstring vault;
	FileStream fs;
	std::string hash;
	std::wstring name;
	std::wstring file;
	unsigned capacity = 4;
	unsigned size = 0;
	std::wstring* note = nullptr;
	friend std::wostream& operator<<(std::wostream&, Note&);
	friend std::wistream& operator>>(std::wistream&, Note&);

	Note(const Note&) = delete;
	Note operator=(const Note&) = delete;
};



std::wostream& operator<<(std::wostream&, Note&);
std::wistream& operator>>(std::wistream&, Note&);
#endif