#include "Note.h"
#include "Settings.h"

std::wstring Settings::vault = L"C:\\Users\\Vital\\Documents";
std::wstring* Settings::File_Names = new std::wstring[end_File_Names];
std::wstring Settings::settingsDir = L"C:\\Users\\Vital\\AppData\\Local\\NOTA\\";
std::wstring Settings::settingsFile = L"IMPORTANT.txt";
int  Settings::cur_File = 0;
int  Settings::end_File_Names = 4;
FileStream Settings::fs((settingsDir + settingsFile).c_str());

void Settings::loadNote(Note& note)
{

}

void Settings::saveTechInfo(Note note)
{
	fs.getFout() << note.getName() + L" " + note.getFileName() + L" " + std::to_wstring(note.getNumOfStrings()) + L" " + std::to_wstring(note.getCurrentString());
}


std::wstring Settings::getVault()
{
	return vault;
}
void Settings::setSettingsDir(wchar_t* dir)
{
	Settings::settingsDir = dir;
}
std::wstring Settings::getSettingsDir()
{
	return settingsDir;
}
void Settings::loadFileNames()
{
	
	while (true)
	{
		if (fs.getFin().eof())
		{
			break;
		}

		fs.getFin() >> File_Names[cur_File];
		cur_File++;

		if (cur_File == end_File_Names)
		{
			ResizeFile_Names();
		}
	}

}
void Settings::saveFileName(Note& note)
{
	fs.getFout() << note.getFileName() << L" ";
}
void Settings::ResizeFile_Names()
{
	end_File_Names *= 1.5;
	std::wstring* newFile_Names = new std::wstring[end_File_Names];
	for (int i = 0; i < cur_File; i++)
	{
		newFile_Names[i] = File_Names[i];
	}
	delete[] File_Names;
	File_Names = newFile_Names;
}