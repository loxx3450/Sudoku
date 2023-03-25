#include <iostream>
#include "Map.h"
#include "Generator.h"






int main()
{
    srand(time(NULL));
    rand();

    Map map{};
    while (true)
    {
        map.generate();
        if (map.isMade())
        {
            map.show();
            break;
        }
    }
    



    
    
    
}