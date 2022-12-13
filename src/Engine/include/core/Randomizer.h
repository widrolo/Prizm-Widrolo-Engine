#include "stdlib.h"

class Randomizer
{
private:
    int seed;
    int number;
public:
    // Abstraction heaven

    void Seed(int seed)
    {
        sys_srand(seed);
    }
    void Shuffle(int min, int max)
    {
        number = sys_rand();

        double newNum = number;

        omg:
        while (newNum < min)
        {
            while (newNum < min)
            {
                newNum * 2;
            }
            newNum / 2;
        }

        if (newNum < min)
            goto omg;
        
        number = newNum;
        ret
    }
    int GetNum()
    {
        return number;
    }
};
