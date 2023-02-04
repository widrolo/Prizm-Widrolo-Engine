#pragma once

#include "./File.h"
#include "./EngineDefines.h"

// size = sizeof(char * 2) = 2 bytes
typedef struct SaveObject
{
    short SaveData;
};

class SaveManager
{
private:
    SaveObject objs[__MAX_SAVE_OBJECTS];
    char saveBuff[__MAX_SAVE_OBJECTS * 2];
    FileReader fileReader;

    WFile saveFile;

public:
    void Init()
    {
        for (int i = 0; i < __MAX_SAVE_OBJECTS; i++)
        {
            // Reset all saves
            objs[i].SaveData = 65; // temp 65 for testing
        }

        saveFile.SetName(__SAVE_NAME);
    }

    void SetData(short ID, short data)
    {
        objs[ID].SaveData = data;
    }

    short GetData(short ID)
    {
        return objs[ID].SaveData;
    }

public: // Dangerous File Handling Functions

    void CreateNewSaveFile()
    {
        fileReader.CreateFile(&saveFile);
    }

    void SaveToFile()
    {
        char lowerByte; // 0x00FF
        char upperByte; // 0xFF00

        char *buffPtr = saveBuff;

        for (int  i = 0; i < __MAX_SAVE_OBJECTS; i++)
        {
            lowerByte = (char)(objs[i].SaveData & 0x00FF);
            *buffPtr = lowerByte;
            buffPtr++;

            upperByte = (char)((objs[i].SaveData & 0xFF00) >> 8);
            *buffPtr = upperByte;
            buffPtr++;
        }

        fileReader.OpenFile(&saveFile);
        fileReader.WriteToFile(&saveFile, buffPtr, __MAX_SAVE_OBJECTS * 2);
        fileReader.CloseFile(&saveFile);
    }

    void LoadSaveFromFile()
    {

    }
};
