#include "Note.h"
#include "Settings.h"



std::wstring Settings::settingsDir = getUserFolder(FOLDERID_Documents);
std::wstring Settings::settingsFile = L"files_info";

FileStream Settings::fs((settingsDir + settingsFile).c_str());

void Settings::loadNote(Note& note){
	fs.getFin() >> note.name >> note.file >> note.capacity;
}

void Settings::saveFileInfo(Note& note){
	fs.getFout() << note.getName() + L" "+ note.getFile() + L" " + std::to_wstring(note.getCapacity()) + L" \n";
	fs.getFout().flush();
}

void Settings::setSettingsDir(wchar_t* dir){
	Settings::settingsDir = dir;
}
std::wstring Settings::getSettingsDir() {return settingsDir;}

wchar_t* Settings::getUserFolder(KNOWNFOLDERID id) {
	wchar_t* path = nullptr;
	S_OK == SHGetKnownFolderPath(id, 0, 0, &path);
	wcscat(path, L"\\NOTA\\");
	return path;
}

bool Settings::endOfSettingsFile() {return fs.getFin().eof();}
