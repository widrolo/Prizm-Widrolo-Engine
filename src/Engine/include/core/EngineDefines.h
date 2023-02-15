
// This is the command center for the engine.
// Many engine and game features can be enable, modified or disabled is this file

// Packaging stages can be modified to not include incomplete features


#pragma once

// Packaging 
#define __FINAL 0				// This flags the final release (All othe flags must be disabled)
#define __EMULATE_FINAL 0		// This emulates the final release 
#define __DEV 1					// This enables developer mode, it allows for debugging and other features that a user shouldnt have
#define __BLEEDING_EDGE 1		// This enables features (not engine features) that are incomplete, untested or unstable

// turn stuff on or off
#define __COLLISION 1			// This disables all collision and trigger zones
#define __RENDERING 1			// This disables all rendering
#define __TEXT		1			// This disables all text

// Text buffer
#define __TEXT_BUFFER_SIZE 256	// This is the size of the text buffer used for text rendering
#define __TEXT_BUFFER_AMMOUNT 6 // This is the ammount of text buffer available

// Object counts
#define __MAX_OBJECTS 64		// How many objects can be stored to be started, ticked or drawn
#define __MAX_COLLISION_BOXES 64// How many collision boxes can exist

// Save Game
#define __MAX_SAVE_OBJECTS 64	// How many save objects can exist
#define __SAVE_NAME "\\\\fls0\\Debug.wsv"

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

#define ENGINE_SETUP GM_GameMode PGAMEMODE;
#define ENGINE_AWAKE PGAMEMODE.InitGame(pGame); pGame->EngineSetGamemode(&PGAMEMODE, PGAMEMODE.GetTextCanvas());
#define ENGINE_DRAW(x)	Bdisp_AllClr_VRAM(); x pTextCanvas->Draw(); Bdisp_PutDisp_DD();
#define NEW_OBJECT(x, y, z) x *y = (x*)PGAMEMODE.GetAllocator()->AllocateEZ(sizeof(x)); pGame->AddObj(&y->Reset, &y->Tick, &y->Draw, z, y);

