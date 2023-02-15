#include "./EngineDefines.h"
#include "./../math/vector.h"

#pragma once


namespace WEngine
{
    class CollisionBox
    {
    private:
        Vector2 position;
        Vector2 size;
        unsigned char layer;
        unsigned int ID;
    public: 
        void MakeBox(Vector2 position, Vector2 size, unsigned char layer, unsigned int ID)
        {
            this->position = position;
            this->size = size;
            this->layer = layer;
            this->ID = ID;
        }

        void SetBoxInfo(Vector2 position, Vector2 size)
        {
            this->position = position;
            this->size = size;
        }

        unsigned int GetID()
        {
            return ID;
        }
        unsigned char GetLayer()
        {
            return layer;
        }
        Vector2 GetPosition()
        {
            return position;
        }
        Vector2 GetSize()
        {
            return size;
        }
    };

    class CollisionResult
    {
    public:
        bool collided;
        unsigned int otherID;

        void Reset()
        {
            collided = false;
            otherID = 0;
        }
    };

    class CollisionManger
    {
    private: // Private Vars

        unsigned int avalibleID = 1;
        CollisionBox *boxes[__MAX_COLLISION_BOXES];

    public: // Public Box Array Control Functions

        void Init()
        {
            for (int i = 0; i < __MAX_COLLISION_BOXES; i++)
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
            for (int i = 0; i < __MAX_COLLISION_BOXES; i++)
            {
                if (boxes[i]->GetID() == ID)
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

        void CheckForCollision(unsigned int ID, CollisionResult* result) 
        {
            if (__COLLISION == 0)
                return;
            // Setup
            result->collided = false;

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

                // Fast pixel perfect collision checking 

                if (box1.GetPosition().x + box1.GetSize().x > box2.GetPosition().x &&
                    box2.GetPosition().x + box2.GetSize().x > box1.GetPosition().x &&
                    box1.GetPosition().y + box1.GetSize().y > box2.GetPosition().y &&
                    box2.GetPosition().y + box2.GetSize().y > box1.GetPosition().y)
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
            for (int i = 0; i < __MAX_COLLISION_BOXES; i++)
                if (boxes[i] == nullptr)
                    return i;
            return -1;
        }

        int FindBoxID(unsigned int ID)
        {
            for (int i = 0; i < __MAX_COLLISION_BOXES; i++)
                if (boxes[i]->GetID() == ID)
                    return i;

            return -1;
        }

        int FindBoxLayer(unsigned char layer, int start)
        {
            for (int i = start; i < __MAX_COLLISION_BOXES; i++)
                if (boxes[i]->GetLayer() == layer)
                    return i;
        }

        int FindNextBox(int start, unsigned int searchAgainst)
        {
            for (int i = start; i < __MAX_COLLISION_BOXES; i++)
                if (boxes[i] != nullptr)
                    if (boxes[i]->GetID() != searchAgainst) //possible bug!
                        return i;

            return -1;
        }
    };
}