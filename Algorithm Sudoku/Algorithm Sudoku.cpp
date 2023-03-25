#include <iostream>
#include "Map.h"
#include "Generator.h"






int main()
{
    srand(time(NULL));
    rand();

    Map map{};
    map.generate();
    map.show();

    Generator a{};
    a.generation(&map);
    map.show();
   
    
    
}