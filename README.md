# Autumn Engine
Autumn Bomb LTD 2D Engine made with SFML for graphics and C++ for the language

Autumn Engine is a 2D engine designed to be used in-house by Autumn Bomb LTD and for various Game Jams. This engine will be used to build multiple 2D games of varying genres with multiple systems that can be utilised. 

The systems planned for implementation are:

Scene Manager - Used for adding scenes, managing the current scene, loading and unloading scenes (Done)\
GUI/UI Library - This will be used for creating UI elements such as HUD components, buttons, titles, menus (Done)\
Input handling - Ability to get input from multiple sources such as a Keyboard (Done)\
Resource Loader - Used to load assets such as sprites, textures, sounds, txt/json files and caches them so they can't be loaded more than once (Done)\

Entity Component System - This will be used to manage every entity that exists in the game, ability to add components such as Transforms and Rigidbodys(Implementing)
Game State System - This will be used to control the state of the game going from the SplashScreen -> Main Menu -> Game(Implementing)

2D Renderer - Renders anything 2D to the screen, has optimisations such as Sprite Batching to reduce draw calls\
Collision Detection - This will be an overall system to detect collisions from multiple objects such as AABB, Circle v Cirlce, Circle v Point\
Particle System - Used to add effect to entities such as smoke, blood, ground dust\
2D Animation System - Used to animate different Entities and GUI components, such as buttons, sprites, splashscreen\
Shaders - This class will be used to add effects to sprites and other entities\
Physics System - Used to apply gravity, force and velocity to entities during gameplay \
Level Editor - Will be used with an application called "Tiled" for 2D games to fast-track level building instead of placing each tile by coords in code\
Sound Class - Used to add sounds, music and access each sound and music in-game by name

Once all these systems are in place, the developers will design and build a test scene with everything included to show off the engines capabilities. The engine will also be tested through Game Jams to figure out if there are any issues, missing features or bugs that need to be fixed.
