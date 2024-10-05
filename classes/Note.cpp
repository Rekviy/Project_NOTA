#include "Settings.h"
#include "Note.h"
Note::Note(std::wstring file, std::wstring dir, std::wstring name) {
	this->file = file;
	this->dir = dir;
	this->name = name;
	note = new std::wstring[num_Of_Strings];
	fs = &FileStream((dir + file).c_str());
}

Note::~Note(){
	delete[] note;
}

unsigned Note::getNumOfStrings() {return num_Of_Strings;}
unsigned Note::getCurrentString() {return cur_String;}


std::wstring Note::getDir() {return dir;}
std::wstring Note::getFileName() {return file;}
std::wstring Note::getName() {return name;}


int Note::wstr_cpy(std::wstring& str){
	note[cur_String] = str;
	cur_String++;
	if (cur_String == num_Of_Strings - 1)
	{
		ResizeNote();
	}
	return 0;
}

void Note::saveToFile(){
	fs.getFout() << this;
	Settings::saveTechInfo(*this);
}

int Note::writeNote()
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
	fs.getFout() << *this;
	return 0;
}
int Note::readNote()
{
	std::wcout << *this << std::endl;
	return 0;
}

void Note::ResizeNote() {
	num_Of_Strings *= 1.5;
	std::wstring* newNote = new std::wstring[num_Of_Strings];
	for (int i = 0; i < cur_String; i++)
		newNote[i] = note[i];

	delete[] note;
	note = newNote;
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


