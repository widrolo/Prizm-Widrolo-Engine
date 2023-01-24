#pragma once

#include "fxcg/heap.h"
#include <stddef.h>
#include "./List.h"

class Allocator
{
private:
    ListNode* firstNode;
    ListNode* lastNode;

    int highID;

public:
    void Init()
    {
        firstNode = (ListNode*)sys_malloc(sizeof(ListNode));
        if (firstNode == nullptr)
        {
            // Handle an exception
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
            // Handle an exception
        }
        lastNode = lastNode->nextNode;

        lastNode->ID = highID;
        highID++;

        lastNode->data.ptr = sys_malloc(allocSize);
        if (lastNode->data.ptr == nullptr)
        {
            // Handle an exception
        }

        return lastNode->ID;
    }
};
