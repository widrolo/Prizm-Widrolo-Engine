#include "stdlib.h"


namespace WEngine
{
    class Randomizer
    {
    private:
        int seed;
        short number;
    public:
        // Abstraction heaven

        void Seed(int seed)
        {
            sys_srand(seed);
        }
        void Shuffle(bool negative, int max)
        {
            number = sys_rand();

            while (number > max)
            {
                number = (int)((double)number / 2);
            }

            if (negative)
                number = (number | 0x8000); // Signs the short
        }
        int GetNum()
        {
            return number;
        }
    };
}