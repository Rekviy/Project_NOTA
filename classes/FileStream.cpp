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
	this->finOpened = other->finOpened;
	this->fout = other->fout;
	this->foutOpened = other->foutOpened;
	other->finOpened = false;
	other->foutOpened = false;
	return *this;
}

FileStream* FileStream::operator&() {return this;}

void FileStream::closeStreams()
{
	if (this->finOpened){
		fin->close();
		delete fin;
	}
	if (this->foutOpened){
		fout->close();
		delete fout;
	}
}

std::wifstream& FileStream::getFin() {return *fin;}

std::wofstream& FileStream::getFout() {return *fout;}

bool FileStream::isFinOpened() {return finOpened;}

bool FileStream::isFoutOpened() {return foutOpened;}

void FileStream::openFin(const wchar_t* file)
{
	std::wifstream* temp = new std::wifstream;

	temp->exceptions(std::wifstream::badbit | std::wifstream::failbit);
	try
	{
		std::cout << "Opening file..." << std::endl;
		temp->open(file, std::wifstream::app);
		std::cout << "File successful opened!" << std::endl;
		fin = temp;
		finOpened = true;
		return;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
	}
	finOpened = false;
	delete temp;
}
void FileStream::openFout(const wchar_t* file)
{
	std::wofstream* temp = new std::wofstream;

	temp->exceptions(std::wofstream::badbit | std::wofstream::failbit);
	try
	{
		std::cout << "Opening file..." << std::endl;
		temp->open(file, std::wofstream::app);
		std::cout << "File successful opened!" << std::endl;
		fout = temp;
		foutOpened = true;
		return;
	}
	catch (const std::wfstream::failure& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "ERROR" << ex.what() << std::endl;
	}
	foutOpened = false;
	delete temp;
}