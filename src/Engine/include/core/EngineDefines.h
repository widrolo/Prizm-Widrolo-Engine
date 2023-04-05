
// This is the command center for the engine.
// Many engine and game features can be enable, modified or disabled is this file

// Packaging stages can be modified to not include incomplete features


#pragma once

// Game loop defines
#define __LOOP_HALT 1			// Sets a pause time before another tick can happen

// Packaging 
#define __FINAL 0				// This flags the final release (All other flags must be disabled)
#define __EMULATE_FINAL 0		// This emulates the final release 
#define __DEV 1					// This enables developer mode, it allows for debugging and other features that a user shouldnt have
#define __BLEEDING_EDGE 1		// This enables features (not engine features) that are incomplete, untested or unstable

// turn stuff on or off
#define __COLLISION 1			// This disables all collision and trigger zones
#define __RENDERING 1			// This disables all rendering
#define __TEXT		1			// This disables all text

// Text buffer
#define __TEXT_BUFFER_SIZE 128	// This is the size of the text buffer used for text rendering
#define __TEXT_BUFFER_AMMOUNT 6 // This is the ammount of text buffer available

// Object counts
#define __MAX_OBJECTS 64		// How many objects can be stored to be started, ticked and drawn
#define __MAX_COLLISION_BOXES 64// How many collision boxes can exist

// Save Game
#define __MAX_SAVE_OBJECTS 64	// How many save objects can exist
#define __SAVE_NAME "\\\\fls0\\Debug.wsv"

// Events
#define __MAX_EVENTS 16			// How many events exist
#define __MAX_SUBSCRIBERS 16	// How many objects can subscribe to an event

// DO NOT TOUCH
// Check is the developer is retarded
#if __FINAL == 1
	#if __EMULATE_FINAL == 1 || __DEV == 1 || __BLEEDING_EDGE == 1
		#error "Disable any other flag while using __FINAL"
	#endif
#endif

// Inform the developer of turned off features
#if __COLLISION == 0
	#pragma message("Collision is turned off. Edit EngineDefines.h to enable it again")
#endif
#if __RENDERING == 0
	#pragma message("Rendering is turned off. Edit EngineDefines.h to enable it again")
#endif
#if __TEXT == 0
	#pragma message("Text is turned off. Edit EngineDefines.h to enable it again")
#endif

// Engine Macros

#define ENGINE_BOOT GM_GameMode *pGameMode = (GM_GameMode*)sys_malloc(sizeof(GM_GameMode)); pGameMode->InitGame(pGame); pGame->EngineSetGamemode(pGameMode, pGameMode->GetTextCanvas(), pGameMode->GetInputManager(), pGameMode->GetDebugConsole());
#define NEW_OBJECT(x, y, z) x *y = (x*)pGameMode->GetAllocator()->AllocateEZ(sizeof(x)); pGame->AddObj(&y->Reset, &y->Tick, &y->Draw, z, y);
#define NEW_OBJECT_AFTER(x, y, z) x *y = (x*)self->gameMode->GetAllocator()->AllocateEZ(sizeof(x)); self->gameMode->GetGameSession()->AddNewAfterAwake(&y->Reset, &y->Tick, &y->Draw, z, y);

