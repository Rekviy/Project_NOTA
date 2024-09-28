#include "Note.h"
//former settings
int Note::cur_File = 0;
int Note::end_File_Names = 4;
std::wstring* Note::File_Names = new std::wstring[end_File_Names];
wchar_t* Note::dir = (wchar_t*)L"C:\\Users\\Vital\\AppData\\Local\\NOTA\\";
wchar_t* Note::techFile = (wchar_t*)L"IMPORTANT.txt";

void Note::saveTechInfo()
{
	std::wfstream* fs = openWFileStream(file_Name.c_str());
	if (fs == nullptr)
		return;
	*fs << name + L" " + file_Name + L" " + std::to_wstring(num_Of_Chars) + L" " + std::to_wstring(num_Of_Words) + L" " +
		std::to_wstring(num_Of_Strings) + L" " + std::to_wstring(cur_String);
	(*fs).close();
}

void Note::ResizeNote()
{
	num_Of_Strings += 8;
	std::wstring* newNote = new std::wstring[num_Of_Strings];
	for (int i = 0; i < cur_String; i++)
	{
		newNote[i] = note[i];
	}

	delete[] note;
	note = newNote;
}

Note::Note(std::wstring fileName) : Note(L"Unknown", fileName) {}

Note::Note(std::wstring name, std::wstring fileName)
{
	this->name = name;
	this->file_Name = fileName;
	note = new std::wstring[num_Of_Strings];
}

Note::~Note()
{
	delete[] note;
}

unsigned Note::getNumOfStrings()
{
	return num_Of_Strings;
}
unsigned Note::getCurrentString()
{
	return cur_String;
}

std::wstring Note::getFileName()
{
	return file_Name;
}
std::wstring Note::getName()
{
	return name;
}


int Note::wstr_cpy(std::wstring& str)
{
	note[cur_String] = str;
	cur_String++;
	if (cur_String == num_Of_Strings - 1)
	{
		ResizeNote();
	}
	return 0;
}
void Note::saveToFile(std::wfstream* fs)
{
	*fs << this;
	saveTechInfo();
}
void Note::loadFile(const wchar_t* fileName)
{
	std::wfstream* fs = openWFileStream(fileName);
	if (fs == nullptr)
		return;

	try
	{
		*fs >> name;
		*fs >> file_Name;
		*fs >> num_Of_Chars;
		*fs >> num_Of_Words;
		*fs >> num_Of_Strings;
		*fs >> cur_String;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
		return;
	}
	catch (const std::exception& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		return;
	}


	(*fs).close();
}
int Note::writeNote(std::wfstream* fs)
{
	std::wstring buff = L"";
	std::cout << "(Q) to quit" << std::endl;
	while (true)
	{
		std::wcin >> buff;
		if (buff == L"Q" || buff == L"q")
			break;
		this->wstr_cpy(buff);
	}
	*fs << *this;
	return 0;
}
int Note::readNote(std::wfstream* fs)
{
	std::wcout << *this << std::endl;
	return 0;
}


//former settings
void Note::setDir(wchar_t* dir)
{
	Note::dir = dir;
}
wchar_t* Note::getDir()
{
	return dir;
}

std::wfstream* Note::openWFileStream(const wchar_t* str)
{
	wchar_t* tempstr = new wchar_t[std::wcslen(str) + std::wcslen(dir) + 1];

	//std::wcscpy(tempstr, dir);

	wcscpy_s(tempstr, wcslen(dir), dir);

	//std::wcscat(tempstr, str);
	wcscat_s(tempstr, wcslen(str), str);
	std::wfstream fs;
	fs.exceptions(std::wfstream::badbit | std::wfstream::failbit);
	try
	{
		std::cout << "Открытие файла..." << std::endl;
		fs.open(tempstr, std::wfstream::app | std::wfstream::in | std::wfstream::out);
		std::cout << "Файл успешно открыт!" << std::endl;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
		delete[] tempstr;
		return nullptr;
	}
	catch (const std::exception& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		delete[] tempstr;
		return nullptr;
	}
	delete[] tempstr;
	return &fs;
}
void Note::loadFileNames()
{
	std::wfstream* fs = openWFileStream(techFile);
	if (fs == nullptr)
		return;

	while (true)
	{
		if ((*fs).eof())
		{
			break;
		}

		*fs >> File_Names[cur_File];
		cur_File++;

		if (cur_File == end_File_Names)
		{
			ResizeFile_Names();
		}

	}
	(*fs).close();
}
void Note::saveFileNames(Note notes[], unsigned len)
{
	std::wfstream* fs = openWFileStream(techFile);
	if (fs == nullptr)
		return;
	for (int i = 0; i < len; i++)
	{
		*fs << notes[i].getFileName() << L" ";
	}
	(*fs).close();

}
void Note::ResizeFile_Names()
{
	end_File_Names += 8;
	std::wstring* newFile_Names = new std::wstring[end_File_Names];
	for (int i = 0; i < cur_File; i++)
	{
		newFile_Names[i] = File_Names[i];
	}
	delete[] File_Names;
	File_Names = newFile_Names;
}


std::wostream& operator<<(std::wostream& os, Note& note)
{
	for (int i = 0; i < note.cur_String; i++)
	{
		os << note.note[i] << L"\n";
	}
	return os;
}
std::wistream& operator>>(std::wistream& is, Note& note)
{
	std::getline(is, note.note[note.cur_String]);
	note.cur_String++;
	if (note.cur_String == note.num_Of_Strings)
	{
		note.ResizeNote();
	}
	return is;
}