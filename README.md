--SIMPLE ECS
--

includes a definition of an Entitiy with very barebones methods to get it going 
the world is composed of Entities and has some boilerplate for entity creation and destruction 
\n
--main.c
--
includes boilerplate of how it works
--ecs.h
--
\n
the actual system
/////////////////
\n
**ENTITY** ----- is the defintion of the actual entity itself including a slot for its ID(index) and its update and start methods
\n
**WORLD** ------ the main scene that includes the entities with some utilities like a *count* property that shows the current count and a *capacity* that caps the limit
