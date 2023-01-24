#pragma once

struct ListNode
{
    int ID;
    union data
    {
        void* ptr;
        int num;
    }data;
    ListNode* nextNode;
};
