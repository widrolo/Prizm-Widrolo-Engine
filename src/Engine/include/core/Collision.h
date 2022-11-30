#include "./../math/vector.h"

#pragma once

#define MAX_BOXES 100

class CollisionBox
{
public:
    Vector2 position;
    Vector2 size;
    unsigned char layer;
    unsigned int ID;
};

class CollisionResult
{
public:
    bool collided;
    unsigned int otherID;
};

class CollisionManger
{
private: // Private Vars

    unsigned int avalibleID = 1;
    CollisionBox *boxes[MAX_BOXES];

public: // Public Box Array Control Functions

    CollisionManger()
    {
        for (int i = 0; i < MAX_BOXES; i++)
            boxes[i] = nullptr;
    }

    void AddBox(CollisionBox *pBox)
    {
        int index = CheckForAvail();
        if (index == -1)
            return;
        
        boxes[index] = pBox;
    }

    void RemoveBox(unsigned int ID)
    {
        for (int i = 0; i < MAX_BOXES; i++)
        {
            if (boxes[i]->ID == ID)
            {
                boxes[i] = nullptr;
                return;
            }
        }
    }

    unsigned int GenerateNewID()
    {
        avalibleID++;
        return avalibleID;
    }

public: //Public Collision Check Functions

    // TO HELL WITH THIS FUNCTION!!!
    void CheckForCollision(unsigned int ID, CollisionResult* result) 
    {                                                                
        // Find the box that is checking collision
        int index = FindBoxID(ID);
        if (index == -1) { result->collided = false; return; }

        CollisionBox box1 = *boxes[index];

        // locate other boxes
        int findIndex = FindNextBox(0, ID);
        if (findIndex == -1) { result->collided = false; return; }

        CollisionBox box2;
        while (findIndex != -1)
        {
            box2 = *boxes[findIndex];

            // One Big Reliable Boy For Checking Collision

            if (box1.position.x + box1.size.x > box2.position.x && 
                box2.position.x + box2.position.x > box1.position.x && 
                box1.position.y + box1.size.y > box2.position.y && 
                box2.position.y + box2.position.y > box1.position.y)
            { 
                result->collided = true;
                result->otherID = findIndex;
                return;
            }

            findIndex = FindNextBox(findIndex + 1, ID);
        }

        result->collided = false;
        return;
    }

private: // Private Searching Functions

    int CheckForAvail()
    {
        for (int i = 0; i < MAX_BOXES; i++)
            if (boxes[i] == nullptr)
                return i;
        return -1;
    }

    int FindBoxID(unsigned int ID)
    {
        for (int i = 0; i < MAX_BOXES; i++)
            if (boxes[i]->ID == ID)
                return i;

        return -1;
    }

    int FindBoxLayer(unsigned char layer, int start)
    {
        for (int i = start; i < MAX_BOXES; i++)
            if (boxes[i]->layer == layer)
                return i;
    }

    int FindNextBox(int start, unsigned int searchAgainst)
    {
        for (int i = start; i < MAX_BOXES; i++)
            if (boxes[i] != nullptr)
                if (boxes[i]->ID == searchAgainst) //possible bug!
                    return i;

        return -1;
    }
};