
// This is the command center for the engine.
// Many engine and game features can be enable, modified or disabled is this file

// Packaging stages can be modified to not include incomplete features


#pragma once

// Packaging 
#define __FINAL 0				// This flags the final release (All othe flags must be disabled)
#define __EMULATE_FINAL 0		// This emulates the final release 
#define __DEV 1					// This enables developer mode, it allows for debugging and other features that a user shouldnt have
#define __BLEEDING_EDGE 0		// This enables features (not engine features) that are incomplete, untested or unstable

// turn stuff on or off
#define __COLLISION 1			// This disables all collision and trigger zones
#define __RENDERING 1			// This disables all rendering

// Anti Piracy
#define __FOR_WHO "   An Filip" // This is tho whoever im going to sell the game to

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

// Who is getting this copy
#if __FINAL == 1
_Pragma ("message(__FOR_WHO)")
#endif