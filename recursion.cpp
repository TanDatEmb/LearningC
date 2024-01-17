#include <iostream>
#include <cstdint> 

int calculateSum(int i)
{
   if(i == 0)
   {
      return 0;
   }
   return i + calculateSum(i-1);
}

int  main()
{
    int i = 0;
     std::cout << calculateSum(i);
     std::cout <<"\n===========================\n";
    return 0;
}