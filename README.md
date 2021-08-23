# Autumn Engine
Autumn Bomb LTD 2D Engine made with SFML for graphics and C++ for the language

Autumn Engine is a 2D engine designed to be used in-house by Autumn Bomb LTD and for various Game Jams. This engine will be used to build multiple 2D games of varying genres with multiple systems that can be utilised. 

The systems planned for implementation are:

Scene Manager - Used for adding scenes, managing the current scene, loading and unloading scenes (Done)\
GUI/UI Library - This will be used for creating UI elements such as HUD components, buttons, titles, menus (Done)\
Input handling - Ability to get input from multiple sources such as a Keyboard (Done)\
Resource Loader - Used to load assets such as sprites, textures, sounds, txt/json files and caches them so they can't be loaded more than once (Done)\
Collision Detection - This will be an overall system to detect collisions from multiple objects such as AABB, Circle v Cirlce, Circle v Point (Done)\
Game State System - This will be used to control the state of the game going from the SplashScreen -> Main Menu -> Game (Done)

Entity Component System - This will be used to manage every entity that exists in the game, ability to add components such as Transforms and Rigidbodys(Implementing)\

Particle System - Used to add effect to entities such as smoke, blood, ground dust\
2D Animation System - Used to animate different Entities and GUI components, such as buttons, sprites, splashscreen\
Shaders - This class will be used to add effects to sprites and other entities\
Physics System - Used to apply gravity, force and velocity to entities during gameplay \
Level Editor - Will be used with an application called "Tiled" for 2D games to fast-track level building instead of placing each tile by coords in code\
Sound Class - Used to add sounds, music and access each sound and music in-game by name

2D Renderer - Renders anything 2D to the screen, has optimisations such as Sprite Batching to reduce draw calls (Backburner)

Editor:

We have also began work on the visual editor the engine will use, for this we are using the Dear ImGui API for rendering any UI element needed. This editor is currently in the works and will have features such as:

Inspector - Used for controlling Entities and Objects\
Scene Hierarchy - Used to adding Entities and Objects into a Scene\
Console - Used for logging messages from the engine\
Content Browser - Used for controlling assets and scenes for a given project\
Game Viewport - Used to design and create levels and games in editor\
Animation - Used to create 2D animations from Spritesheets 
Properties Window - Used to add components onto Entities and Objects
Stats - Used to display stats for the Engine such as FPS, Frametime, Entities in scene, Drawcalls, Batches and more.

Once all these systems are in place, the developers will design and build a test scene with everything included to show off the engines capabilities. The engine will also be tested through Game Jams to figure out if there are any issues, missing features or bugs that need to be fixed.

License:
This engine as of 12/08/2021 is currently for private use by Autumn Bomb LTD. This is subject to change as more features are added and the engine becomes more useable.

Discord:
https://discord.gg/bf7Uy6EUxa Here is a link to the discord channel we are currently using. Feel free to join and ask questions and have a chat :D

Screenshots:

Editor (WIP):
![image](https://user-images.githubusercontent.com/48921196/130524053-ea34b4d8-dbb0-4013-847f-0b46a801e8f6.png)

Without Editor:

![image](https://user-images.githubusercontent.com/48921196/128703243-b9ce015b-ed96-43bd-918d-a72e19910b0b.png)
![image](https://user-images.githubusercontent.com/48921196/128703304-a0adf6b9-30ac-451b-85e0-f639c01c95e1.png)
![image](https://user-images.githubusercontent.com/48921196/128703331-5ae3c798-547d-42dd-a568-10563f764b26.png)

