#pragma once
#ifndef _NOTA_H_
#define _NOTA_H_
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
//#include <cassert>
#include "classes/Note.h"
#include "classes/commands.h";
#ifndef _UNICODE
#define _UNICODE
#endif
#ifndef UNICODE
#define UNICODE
#endif

void createNote(std::vector<Note*>& list);
void deleteNote(std::vector<Note*>& list);
void loadAllNote(std::vector<Note*>& list);
void NoteUI(Note* note);
int writeNote(Note* note);
int readNote(Note* note);
void UI(std::vector<Note*> &list);
#endif