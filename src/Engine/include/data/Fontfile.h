#pragma once

#include <fxcg/display.h>
#include "./../core/EngineDefines.h"

#if __TEXT == 1
// Standart upper case Letters

color_t F_LETTER_A[64] = { 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_B[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_C[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_D[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_E[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_F[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_G[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_H[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_I[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_J[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_K[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_O[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_L[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_M[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_N[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_P[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_Q[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_R[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_S[64] = { 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_T[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_U[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_V[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_W[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_X[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_Y[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_LETTER_Z[64] = { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };

// Standart Symbols

color_t F_SYMBOL_SPACE[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_AMPERSAND[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_BACK_SLASH[64] = { 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_COLON[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_COMMA[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_DOLLAR[64] = { 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_EQUALS[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_EXCLAMATION[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_FULL_STOP[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_GREATER_THAN[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_LEFT_BRACKET[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_LEFT_CURLY_BRACKET[64] = { 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_LEFT_SQUARE_BRACKET[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_LESS_THAN[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_MINUS[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_MULTIPLY[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_PERCENT[64] = { 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x8660, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff0, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_PLUS[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_POUND[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_QUESTION[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_QUOTE[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_RIGHT_BRACKET[64] = { 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_RIGHT_CURLY_BRACKET[64] = { 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_RIGHT_SQUARE_BRACKET[64] = { 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_SEMICOLON[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_SLASH[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_TILDE[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_UNDERSCORE[64] = { 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };
color_t F_SYMBOL_VERTICAL_SLASH[64] = { 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0x0000, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8, 0xfff8,  };

#endif
