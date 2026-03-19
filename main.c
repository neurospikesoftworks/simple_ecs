#include "ecs.h"

void startMan(int ID)  { printf("Man %d started\n", ID); }
void updateMan(int ID) { printf("Man %d is alive\n", ID); }

int main() {

    //Simple boilerplate test

    World world;
    World_Init(&world, 32);

    Entity_Create(&world, startMan, updateMan);
    Entity_Create(&world, startMan, updateMan);
    Entity_Create(&world, startMan, updateMan);
    Entity_Create(&world, startMan, updateMan);

    World_Start(&world);
    
    
    for(int i = 0; i < 3; i++) {
        World_Update(&world);
    }

    World_Destroy(&world);
    return 0;
}