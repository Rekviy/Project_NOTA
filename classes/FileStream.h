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
	void closeStreams();
	void closeFinStream();
	void closeFoutStream();
	void openStreams(const wchar_t* file);
	void openFinStream(const wchar_t* file);
	void openFoutStream(const wchar_t* file);
	std::wifstream& getFin();
	std::wofstream& getFout();
	FileStream& operator=(const FileStream&) = delete;
	FileStream(const FileStream&) = delete;
private:
	std::wifstream fin;
	std::wofstream fout;
	void openFin(const wchar_t* file, std::wifstream& fin);
	void openFout(const wchar_t* file, std::wofstream& fout);
};
#endif