#pragma once

#include "fxcg/heap.h"
#include <stddef.h>

namespace WEngine
{
    class Allocator
    {
    private:
        CrashHandler* pCR;

    public:
        void Init(CrashHandler* cr)
        {
            pCR = cr;
        }

        void *AllocateEZ(size_t allocSize)
        {
            void *ptr = sys_malloc(allocSize);
            if (ptr == nullptr)
            {
                pCR->Crash("Allocator Fail");
            }

            return ptr;
        }
    };
}