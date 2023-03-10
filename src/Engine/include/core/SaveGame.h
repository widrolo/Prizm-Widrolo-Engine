#pragma once

#include "./File.h"
#include "./EngineDefines.h"

namespace WEngine
{
    // size = sizeof(char * 2) = 2 bytes
    struct SaveObject
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
                objs[i].SaveData = 0;
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
            char *buffPtr = saveBuff;

            for (int i = 0; i < __MAX_SAVE_OBJECTS; i++)
            {
                buffPtr[i * 2] = objs[i].SaveData;
                buffPtr[(i * 2) + 1] = (objs[i].SaveData >> 8);
            }

            fileReader.OpenFile(&saveFile);
            fileReader.WriteToFile(&saveFile, buffPtr, __MAX_SAVE_OBJECTS * 2);
            fileReader.CloseFile(&saveFile);
        }

        // TODO: fix loading issue
        void LoadSaveFromFile()
        {
            fileReader.OpenFile(&saveFile);
            fileReader.ReadFromFile(&saveFile, 0);

            for (int i = 0; i < __MAX_SAVE_OBJECTS; i++)
            {
                //objs[i].SaveData =  fileReader.readBuffer[(i * 2) + 1]| ((short)fileReader.readBuffer[i * 2] << 8);
                objs[i].SaveData = fileReader.readBuffer[i * 2] | ((short)fileReader.readBuffer[(i * 2) + 1] << 8);
            }


            fileReader.CloseFile(&saveFile);
        }
    };
}