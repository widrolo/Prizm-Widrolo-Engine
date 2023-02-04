#pragma once

#include <fxcg/file.h>
#include "./CrashHandler.h"

// "\\\\fls0\\File.txt" Example name


class WFile
{
public:
    unsigned short name[64];
    int handle;
    // DO NOT CHANGE THIS VALUE BY YOURSELF
    bool isOpen;
    void SetName(const char* name)
    {
        Bfile_StrToName_ncpy(this->name, name, 64);
    }
};

class FileReader
{
private:
    CrashHandler* cr;
public:
    char readBuffer[4096];
    void Init(CrashHandler* cr)
    {
        this->cr = cr;
    }
    void CreateFile(WFile* file)
    {
        size_t size = 4096;
        int out = Bfile_CreateEntry_OS(file->name, CREATEMODE_FILE, &size);
        if (out != 0)
            cr->Crash("  Cannot create File");
    }
    void OpenFile(WFile* file)
    {
        int out = Bfile_OpenFile_OS(file->name, READWRITE, 0);
        if (out < 0)
            cr->Crash("  File does not exist");
        
        file->handle = out;
        file->isOpen = true;
    }
    void WriteToFile(WFile* file, void* buff, int buffSize)
    {
        if(!file->isOpen)
            cr->Crash("  File is not open");

        Bfile_WriteFile_OS(file->handle, buff, buffSize);
    }
    void ReadFromFile(WFile* file, int fileChunk)
    {
        if(!file->isOpen)
            cr->Crash("  File is not open");

        Bfile_ReadFile_OS(file->handle, readBuffer, 4096, fileChunk * 4096);
    }
    void CloseFile(WFile* file)
    {
        if(!file->isOpen)
            cr->Crash("  File is not open");

        Bfile_CloseFile_OS(file->handle);
        file->isOpen = false;
    }
};
