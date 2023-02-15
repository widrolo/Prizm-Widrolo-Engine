
#pragma once

namespace WEngine
{
    class WMath
    {
    public:
        static int Wfloor(double v)
        {
            int t;
            if(v<0){
               t=(int)v +(-1);
               return t;
            }
            else return v;
        }
        static int Wceil(double v)
        {
            if(v-(int)v==0)
                return v;
            else
            return Wfloor(v)+1;
        }

        static float Wsqrt(float num)
        {
            // Some real magic
            float sqrt = num / 2;
            float temp = 0;
            while(sqrt != temp){
                temp = sqrt;
                sqrt = ( num/temp + temp) / 2;
            }
            return sqrt;
        }

        static float Wsquare(float num)
        {
            return num * num;
        }

        static float Wdist(Vector2 v1, Vector2 v2)
        {
            return Wsqrt(Wsquare(v2.x - v1.x) + Wsquare(v2.y - v1.y));
        }
        static float Wdist(Vector2f v1, Vector2f v2)
        {
            return Wsqrt(Wsquare(v2.x - v1.x) + Wsquare(v2.y - v1.y));
        }
    };
}
