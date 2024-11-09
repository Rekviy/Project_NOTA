#include "Settings.h"
#include "Note.h"
Note::Note(std::wstring name, std::wstring dir) {
	this->file = dir + name + L".txt";
	this->name = name;
	note = new std::wstring[capacity];
	fs.openStreams((vault+file).c_str());
}

Note::~Note(){
	delete[] note;
	//todo delete file
	fs.closeStreams();
}

const unsigned Note::getCapacity() {return capacity;}
const unsigned Note::getSize() {return size;}

const std::wstring& Note::getFile() {return file;}
const std::wstring& Note::getName() {return name;}
const std::string& Note::getHash() { return hash; }
std::wstring Note::getVault() {return vault;}
const std::wstring& Note::operator[](unsigned num){return note[num];}

int Note::write(std::wstring& str){

	note[size] = str + L"\n";
	fs.getFout() << note[size];
	fs.getFout().flush();
	size++;

	if (size == capacity)
		Resize(capacity * 2);
	return 0;
}

void Note::saveNote() {Settings::saveFileInfo(*this);}

void Note::load(){
	Resize(capacity);
	for (unsigned i = 0; i < fs.getFin().eof(); i++)
		fs.getFin() >> *this;
}

void Note::save(){
	fs.getFout() << *this;
	fs.getFout().flush();
}

void Note::reOpenFileStream(){
	try
	{
		fs.closeStreams();
		fs.openStreams((vault + file).c_str());
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void Note::Resize(unsigned newSize) {
	std::wstring* newNote = new std::wstring[newSize];
	if (size > newSize)
		size = newSize;

	for (int i = 0; i < size; i++)
		newNote[i] = note[i];

	delete[] note;
	note = newNote;
	capacity = newSize;
}

std::wostream& operator<<(std::wostream& os, Note& note){
	for (unsigned i = 0; i < note.size; i++)
		os << note.note[i];
	return os;
}
std::wistream& operator>>(std::wistream& is, Note& note){
	std::getline(is, note.note[note.size]);
	note.size++;
	if (note.size == note.capacity)
		note.Resize(note.capacity * 2);
	return is;
}

std::wstring Note::vault = Settings::getUserFolder(FOLDERID_Documents);
