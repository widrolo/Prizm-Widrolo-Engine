#pragma once

#include "./EngineDefines.h"
#include <fxcg/display.h>
#include <fxcg/heap.h>

#include "./Text.h"
#include "./InputManager.h"
#include "./DebugConsole.h"

class GM_GameMode;

class Game
{
private: // Function pointers
    void (*awakePtrs[__MAX_OBJECTS])(void *self, GM_GameMode*);
    void (*tickPtrs[__MAX_OBJECTS])(void *self);
    void (*drawPtrs[__MAX_OBJECTS])(void *self);
    void *selfs[__MAX_OBJECTS];
public: // Game runtime called my main()
    bool isRunning;
    GM_GameMode *pGameMode;
    WEngine::TextCanvas *pTextCanvas;
    WEngine::InputManager *pInputManger;
    WEngine::DebugConsole *pDebugConsole;

    void Awake(Game *pGame);

    // This takes care of initializing objects, that were created in the Awake function
    void Start()
    {
        // Call Reset() for every object
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            if (awakePtrs[i] == nullptr || selfs[i] == nullptr)
                continue;
            (*awakePtrs[i])(selfs[i], pGameMode);
        }
    }
    
    // This takes care of ticking the logic
    void Tick()
    {
        pInputManger->Tick();
        
        // Call Draw() for every object
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            if (tickPtrs[i] == nullptr || selfs[i] == nullptr)
                continue;
            (*tickPtrs[i])(selfs[i]);
        }

    }

    // This takes care of drawing pixels to the screen
    void Draw()
    {
        if (__RENDERING == 0)
            return;

        Bdisp_AllClr_VRAM();

        // Call Draw() for every object
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            if (drawPtrs[i] == nullptr || selfs[i] == nullptr)
                continue;
            (*drawPtrs[i])(selfs[i]);
        }

        pDebugConsole->DrawText();
        pTextCanvas->Draw(); 

        Bdisp_PutDisp_DD();
    }

    // Needs rework
    void End();
public: // Game runtime manger
    void EnginePreInit()
    {
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            awakePtrs[i] = nullptr;
            tickPtrs[i] = nullptr;
            drawPtrs[i] = nullptr;
            selfs[i] = nullptr;
        }
    }
    void EngineSetGamemode( GM_GameMode *pGM, WEngine::TextCanvas *pTC, WEngine::InputManager *pIM, WEngine::DebugConsole *pDC)
    {
        pGameMode = pGM;
        pTextCanvas = pTC;
        pInputManger = pIM;
        pDebugConsole = pDC;
    }
    // Adds an object to be called later, takes function pointers as first arument
    void AddObj(void (*awakePtr)(void *self, GM_GameMode*), void (*tickPtr)(void *self),
        void (*drawPtr)(void *self), int buffNum, void *self)
    {
        if (buffNum > __MAX_OBJECTS || buffNum < 0)
        {
            CrashNow("  Couldnt Create Actor");
        }
        awakePtrs[buffNum] = awakePtr;
        tickPtrs[buffNum] = tickPtr;
        drawPtrs[buffNum] = drawPtr;
        selfs[buffNum] = self;
    }

    void AddNewAfterAwake(void (*awakePtr)(void *self, GM_GameMode*), void (*tickPtr)(void *self),
        void (*drawPtr)(void *self), int buffNum, void *self)
    {
        if (buffNum > __MAX_OBJECTS || buffNum < 0)
        {
            CrashNow("  OUT OF MEMORY");
        }
        awakePtrs[buffNum] = awakePtr;
        tickPtrs[buffNum] = tickPtr;
        drawPtrs[buffNum] = drawPtr;
        selfs[buffNum] = self;

        (*awakePtr)(self, pGameMode);
    }

    void DeallocEverything()
    {
        for (int i = 0; i < __MAX_OBJECTS; i++)
        {
            awakePtrs[i] = nullptr;
            tickPtrs[i] = nullptr;
            drawPtrs[i] = nullptr;
            if (selfs[i] != nullptr )
            {
                sys_free(selfs[i]);
                selfs[i] = nullptr;
            }
        }
        sys_free(pGameMode);
    }

private:
    // This exists because of include order
    void CrashNow(const char* msg)
    {   
        Bdisp_AllClr_VRAM();
        PrintXY(3,  2, "  Panic Crash!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
        PrintXY(3,  3, "  No Data Saved!", TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
        PrintXY(3, 5, msg, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);
        Bdisp_PutDisp_DD();
        int dummy;
        while (true)
            GetKey(&dummy);
    }
};