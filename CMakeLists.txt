﻿# CMakeList.txt: проект CMake для Project_NOTA; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Project_NOTA")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Project_NOTA "Project_NOTA.cpp" "Project_NOTA.h"  "classes/Note.cpp"  "classes/Note.h" "classes/FileStream.cpp" "classes/FileStream.h" "classes/Settings.h" "classes/Settings.cpp" "classes/commands.h" "classes/commands.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Project_NOTA PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
