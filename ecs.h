#ifndef ECS_H
#define ECS_H

#include <stdio.h>
#include <stdlib.h>


typedef void (*EntityCallback)(int ID);

typedef struct {
    int ID;
    EntityCallback Start;
    EntityCallback Update;    
} Entity;

typedef struct {
    int capacity;
    int count;
    Entity* entities;
} World;



// Initialize the world
static inline void World_Init(World* w, int capacity) {
    w->capacity = capacity;
    w->count = 0;
    w->entities = (Entity*)calloc(capacity, sizeof(Entity));
}

// Create an entity with less typing
static inline void Entity_Create(World* w, EntityCallback start, EntityCallback update) {
    if (w->count >= w->capacity) return;
    
    int index = w->count++;
    w->entities[index].ID = index;
    w->entities[index].Start = start;
    w->entities[index].Update = update;
}

// Logic Loops
static inline void World_Start(World* w) {
    for(int i = 0; i < w->count; i++) {
        if(w->entities[i].Start) w->entities[i].Start(w->entities[i].ID);
    }
}

static inline void World_Update(World* w) {
    for(int i = 0; i < w->count; i++) {
        if(w->entities[i].Update) w->entities[i].Update(w->entities[i].ID);
    }
}

// Cleanup
static inline void World_Destroy(World* w) {
    free(w->entities);
}

#endif