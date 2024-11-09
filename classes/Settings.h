#pragma once
#ifndef _SETTINGS_H_
#define _SETTINGS_H_
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <shlobj_core.h>
#include "FileStream.h"

class Note;

static class Settings
{
public:
	static std::wstring getSettingsDir();
	static void setSettingsDir(wchar_t* dir);
	
	static void loadNote(Note& note);
	static void saveFileInfo(Note& note);

	static wchar_t* getUserFolder(KNOWNFOLDERID id);
	static bool endOfSettingsFile();
private:
	static FileStream fs;

	
	static std::wstring settingsDir;
	static std::wstring settingsFile;


};
#endif
