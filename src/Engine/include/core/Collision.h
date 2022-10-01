#include "C:\Users\Filip\Desktop\stuff\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src\Engine\include\math\vector.h"

#pragma once

#define MAX_BOXES 200

class CollisionBox
{
public:
    Vector2 position;
    Vector2 size;
    unsigned char layer;
    unsigned int ID;
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
        {
            boxes[i] = nullptr;
        }
    }

    void AddBox(CollisionBox *pBox)
    {
        int index = CheckForAvail();
        if (index == -1)
        {
            return;
        }
        
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

int CheckForCollision(unsigned int ID)
    {
        int index = FindBoxID(ID);
        if (index == -1) { return 0; }

        int findIndex = FindNextBox(0, ID);
        if (findIndex == -1) { return 0; }

        int result = 0;

        do
        {
            // One Big Reliable Boy For Checking Collision
            /*
            Fun Fact:
            This large if statement is the second try at implementing this check!
            But I hope that its also the last time i have to do this!
            */
            if (boxes[index]->position.x + boxes[index]->size.x > boxes[findIndex]->position.x && 
                boxes[findIndex]->position.x + boxes[findIndex]->position.x > boxes[index]->position.x && 
                boxes[index]->position.y + boxes[index]->size.y > boxes[findIndex]->position.y && 
                boxes[findIndex]->position.y + boxes[findIndex]->position.y > boxes[index]->position.y)
            { result = 1; break; }

            findIndex = FindNextBox(findIndex + 1, ID);
        } while (findIndex != -1);
        return result;
    }

private: // Private Searching Functions

    int CheckForAvail()
    {
        for (int i = 0; i < MAX_BOXES; i++)
        {
            if (boxes[i] == nullptr)
                return i;
        }
        return -1;
    }

    int FindBoxID(unsigned int ID)
    {
        for (int i = 0; i < MAX_BOXES; i++)
        {
            if (boxes[i]->ID == ID)
            {
                return i;
            }
        }

        return -1;
    }

    int FindBoxLayer(unsigned char layer, int start)
    {
        for (int i = start; i < MAX_BOXES; i++)
        {
            if (boxes[i]->layer == layer)
            {
                return i;
            }
        }
    }

    int FindNextBox(int start, unsigned int searchAgainst)
    {
        for (int i = start; i < MAX_BOXES; i++)
        {
            if (boxes[i] != nullptr)
            {
                if (boxes[i]->ID != searchAgainst)
                    return i;
            }
        }

        return -1;
    }
};