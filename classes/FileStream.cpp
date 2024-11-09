#include "FileStream.h"
FileStream::FileStream() {};
FileStream::FileStream(const wchar_t* file) : FileStream(file, true, true) {}
FileStream::FileStream(const wchar_t* file, bool inOpen, bool outOpen)
{
	if (inOpen)
		openFin(file);
	if (outOpen)
		openFout(file);
}
FileStream::~FileStream() {closeStreams();}

FileStream& FileStream::operator=(FileStream* other)
{
	this->closeStreams();
	this->fin = other->fin;
	this->fout = other->fout;
	other->fin = nullptr;
	other->fout = nullptr;
	return *this;
}

FileStream* FileStream::operator&() {return this;}

void FileStream::closeStreams(){
	closeFinStream();
	closeFoutStream();
}
void FileStream::closeFinStream(){
	if (this->fin != nullptr) {
		fin->close();
		delete fin;
		fin = nullptr;
	}
}
void FileStream::closeFoutStream(){
	if (this->fout != nullptr) {
		fout->close();
		delete fout;
		fout = nullptr;
	}
}

void FileStream::openStreams(const wchar_t* file){
	openFinStream(file);
	openFoutStream(file);
}

void FileStream::openFinStream(const wchar_t* file){
	if (fin == nullptr) {
		openFin(file);
	}
}

void FileStream::openFoutStream(const wchar_t* file){
	if (fout == nullptr) {
		openFout(file);
	}
}

std::wifstream& FileStream::getFin() {return *fin;}

std::wofstream& FileStream::getFout() {return *fout;}

void FileStream::openFin(const wchar_t* file){
	std::wifstream* temp = new std::wifstream;
	
	temp->exceptions(std::wifstream::badbit | std::wifstream::failbit);
	try
	{
		std::cout << "Opening file..." << std::endl;
		temp->open(file, std::wifstream::app);
		std::cout << "File successful opened!" << std::endl;
		fin = temp;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
		delete temp;
	}
}
void FileStream::openFout(const wchar_t* file){
	std::wofstream* temp = new std::wofstream;

	temp->exceptions(std::wofstream::badbit | std::wofstream::failbit);
	try
	{
		std::cout << "Opening file..." << std::endl;
		temp->open(file, std::wofstream::app);
		std::cout << "File successful opened!" << std::endl;
		fout = temp;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
		delete temp;
	}
}