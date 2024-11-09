#include "FileStream.h"
FileStream::FileStream() {};
FileStream::FileStream(const wchar_t* file) : FileStream(file, true, true) {}
FileStream::FileStream(const wchar_t* file, bool inOpen, bool outOpen)
{
	if (inOpen)
		openFin(file, fin);
	if (outOpen)
		openFout(file, fout);
}
FileStream::~FileStream() {closeStreams();}

void FileStream::closeStreams(){
	closeFinStream();
	closeFoutStream();
}
void FileStream::closeFinStream(){
	if (fin.is_open()) {
		fin.close();
	}
}
void FileStream::closeFoutStream(){
	if (fout.is_open()) {
		fout.close();
	}
}

void FileStream::openStreams(const wchar_t* file){
	openFinStream(file);
	openFoutStream(file);
}

void FileStream::openFinStream(const wchar_t* file){
	if (!fin.is_open()) {
		openFin(file, fin);
	}
}

void FileStream::openFoutStream(const wchar_t* file){
	if (!fout.is_open()) {
		openFout(file, fout);
	}
}

std::wifstream& FileStream::getFin() {return fin;}

std::wofstream& FileStream::getFout() {return fout;}

void FileStream::openFin(const wchar_t* file, std::wifstream& fin){
	fin.exceptions(std::wifstream::badbit | std::wifstream::failbit);
	try{
		std::cout << "Opening file..." << std::endl;
		fin.open(file, std::wifstream::app);
		std::cout << "File successful opened!" << std::endl;
	}
	catch (const std::wifstream::failure& ex){
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
	}
}
void FileStream::openFout(const wchar_t* file, std::wofstream& fout){
	fout.exceptions(std::wofstream::badbit | std::wofstream::failbit);
	try{
		std::cout << "Opening file..." << std::endl;
		fout.open(file, std::wofstream::app);
		std::cout << "File successful opened!" << std::endl;
	}
	catch (const std::wofstream::failure& ex){
		std::cout << "ERROR" << ex.what() << std::endl;
		std::cout << "CODE:" << ex.code() << std::endl;
	}
}