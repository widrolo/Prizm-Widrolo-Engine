#pragma once

#include "fxcg/heap.h"
#include <stddef.h>
#include "./List.h"

class Allocator
{
private:
    ListNode* firstNode;
    ListNode* lastNode;

    CrashHandler* pCR;

    int highID;

public:
    void Init(CrashHandler* cr)
    {
        pCR = cr;
        firstNode = (ListNode*)sys_malloc(sizeof(ListNode));
        if (firstNode == nullptr)
        {
            cr->Crash("Allocator Init Fail");
        }
        lastNode = firstNode;
        highID = 0;
    }

    // Allocates an object and returns its ID
    int Allocate(size_t allocSize)
    {
        lastNode->nextNode = (ListNode*)sys_malloc(sizeof(ListNode));
        if (lastNode->nextNode == nullptr)
        {
            pCR->Crash("Allocator Fail");
        }
        lastNode = lastNode->nextNode;

        lastNode->ID = highID;
        highID++;

        lastNode->data.ptr = sys_malloc(allocSize);
        if (lastNode->data.ptr == nullptr)
        {
            pCR->Crash("Allocator Fail");
        }

        return lastNode->ID;
    }
};
