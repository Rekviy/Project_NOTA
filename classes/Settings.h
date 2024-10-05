#pragma once
#ifndef _SETTINGS_H_
#define _SETTINGS_H_
#include <iostream>
#include <string>
#include <fstream>
#include "FileStream.h"

class Note;

class Settings
{
public:
	static std::wstring getVault();
	static std::wstring getSettingsDir();
	static void setSettingsDir(wchar_t* dir);
	
	void loadNote(Note& note);
	static void saveTechInfo(Note note);
	static void loadFileNames();
	static void saveFileName(Note& note);
private:
	static FileStream fs;

	static std::wstring vault;
	static std::wstring settingsDir;
	static std::wstring settingsFile;
	static std::wstring* File_Names;
	static int cur_File;
	static int end_File_Names;
	static void ResizeFile_Names();
};




#endif
