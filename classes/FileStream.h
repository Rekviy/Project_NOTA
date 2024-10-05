#pragma once
#ifndef _FILE_STREAM_H_
#define _FILE_STREAM_H_
#include <iostream>
#include <string>
#include <fstream>
class FileStream
{
public:
	FileStream();
	FileStream(const wchar_t* file);
	FileStream(const wchar_t* file, bool OpenFin,bool OpenFout);
	~FileStream();
	FileStream& operator=(FileStream* other);
	FileStream* operator&();
	void closeStreams();
	std::wifstream& getFin();
	std::wofstream& getFout();
	bool isFinOpened();
	bool isFoutOpened();
private:
	std::wifstream* fin = nullptr;
	std::wofstream* fout = nullptr;
	bool finOpened = false;
	bool foutOpened = false;
	void openFin(const wchar_t* file);
	void openFout(const wchar_t* file);
};





#endif