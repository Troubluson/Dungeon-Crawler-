# Meeting Notes
In this file, you are required to take notes for your weekly meetings.
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting 01.11.2021 14::00
The first meeting of the group was held via discord. The goal of the meeting is to decide what features we want to include in the dungeon crawler and start writing the project plan. A google drive document was created to start writing the project plan. A lot of the meeting was spent discussing what features we want to implement in the dungeon crawler and adding them to the project plan.

**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Tried to understand how CMake and SFML works with little success.

2. Mikael
   Read about SFML but hasn't got it working

3. Henrik
   Found a github repository with instructions how to use SFML which could be useful.

4. Oskar
   Overview of dungeon crawlers and looked a bit into making the graphics.


## Challenges

1. None of the group members have experience working with the libraries which we want to use.
2. It is still unclear how time consuming it will be to implement additional features.

## Actions
1. Everyone should review what has been written to the project plan and make additions.
2. New meeting 2.11 at 1 pm when the assistant has hopefully answered our questions.

## Project status
Nothing concrete has been done to the project yet. We started writing the project plan and chose what features we want to implement in the game. Some general information about the project was also added to the project.

### TODOs
1. Jonas: Ask the teaching assitant if WSL should be used and how we should get SFML working. We also need to make sure that our development environment is compatible with the testing done on the school computers.
2. Henrik: Configure GitLab to have correct labels and boards.
3. Oskar: Watch tutorial to get more familiar with git.
4. Mikael: Same as Oskar.

# Meeting 02.11.2021 13::00
The goal of this meeting was to get SFML working for every group member. We held the meeting in discord as all future meetings will also be held. We got SFML working on 3 out of 4 group members computers. We are hoping to get the last computer set up with SFML later this day. We also decided to use Sourcetree to interact with git. Henrik had used this software earlier so he educated the rest of the group on how to use it.

**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Got SFML working and was able to compile and run a sample program.

2. Mikael
   Got SFML working and was able to compile and run a sample program. Also sourcetree is installed and working.

3. Henrik
   Got SFML working and was able to compile and run a sample program.

4. Oskar
   Was nearly able to get SFML working during the meeting. Will probably get it working later today.


## Challenges

1. Sourcetree seems to want VSC closed when operating.
2. Sourcetree also does not correctly show which rows have been added, modified and removed.

## Actions
1. Everyone should install SFML correctly
2. Everyone should install sourcetree correctly

## Project status
We now have SFML working on most of our computers. Next time we can focus on thinking about class relations and working further on our project plan.

### TODOs
1. Jonas: Install sourcetree. Investigate sourcetree for better functionality
2. Henrik: Get sourcetree setup correctly. Investigate sourcetree for better functionality
3. Oskar: Get SFML working and install sourcetree. Investigate sourcetree for better functionality
4. Mikael: Investigate sourcetree for better functionality.


# Meeting 08.11.2021 15::00
A small checkup on what we are going to do this week.

**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael


## Challenges

1. Figure out architectual pattern and other design decisions

## Actions
1. Makes Issues and start working on basic game features
2. Get more comfortable with SFML

## Project status
We have a sprite that can move!

### TODOs
1. Jonas
   Start to work on character classes
2. Mikael
   Look into projectiles and game updating
3. Henrik
   Starts doing architectual decisions and other things later in the week
4. Oskar
   Add walking animation

# Meeting 11.11.2021 13::00
A little recap on what we've done since monday and discuss issues.

**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Been thinking about methods and other features of characters, monster etc.

2. Mikael
   Got projectiles, aiming and collision detection working, also "deltatime"

3. Henrik
   Nothing, been doing other work

4. Oskar
   Looked into room implementation

## Challenges

1. Same as last time
2. How we are going to implement Move method (or class? ) in a logical way.

## Actions
1. Work on the current features and start reviewing and merging branches when done
2. Get our base classes implemented in a good way.

## Project status


# Meeting 16.11.2021 13::00
We started the meeting with disussing what has been done on the project. We started merging some branches into main as we have a lot of branches with some working features and we wanted to avoid merge issues if we develop the branches further. The majority of the meeting was spent on doing these merges and handling the merge requests. As a result of the meeting the branches with the roomtiles and characters were merged.

**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Managed to implement moving monsters into the game. Have looked at the other members code and thought about how    the implementation of the player and monsters will work with the code already created.

2. Mikael
   Continued to work on projectiles.

3. Henrik
   Read up on game architecture, roguelikes and their design. Discussed game design with Oskar. Started constructing weapon and combat classes.

4. Oskar
   Implemented rooms with walls.

## Challenges

1. We have to wait for Mikael to access his computer from Helsinki in order to merge the projectiles.

## Actions
1. Continue to work with our Todo:s.

## Project status
We have some basic features like movement and projectiles implemented to some extent.

### TODOs
1. Jonas: Implement a bar with the hitpoints for the monsters. Create a game bar at the bottom to display some stats etc.
2. Henrik: Continue implementing combat, weapons and powerups and maybe improving code structure
3. Oskar: Adding collisions with walls, make it possible to move between rooms and implement a walking animation.
4. Mikael: Continue to work on projectiles and restrict their range. Help Henrik with the weapons.

# Meeting 23.11.2021 15::15
Started meeting with discussing a lot of problems we have had while working with git. Talked through some game structure implementations.
**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Implemented basic form of health bar for player, still in progress

2. Mikael
   Implemented a projectiles that do damage to enemies. Clamped player position between the walls of our rectangular room and now projectiles collide with the walls. Also found a file for pixelperfect collsion checks between sprites online.

3. Henrik
   Worked weapon classes, helped with merging, fixed other group members code and penetrating projectiles. Added more issues with Mikael into the gitlab.

4. Oskar
   Added animation to player character, worked on a other collision class (which may be unused, could be used if we add platform the player can push), started looking at how to implement the map/dungeon (interconnetec rooms)

## Challenges

1. challenges with circular dependencies, struggled with the project structur and we all have had issues working with git. Oskar hasn't gotten clang-formatting to work. A lot of merging issues. Documatation is a bit lacking at the moment as well.

## Actions
1. Starting documation to keep track of the growing project (extra meeting to go through how we will do this), members getting a more familiar overlook on the existing code.

## Project status
We have a basic form of monsters, weapons, projectiles, rooms and player which we will continue to work upon. We have to start accelerating the progress, which should be easier now when we have a basic forms of these things we have already implemented.

### TODOs
1. Jonas: Work on the monster types, add different AIs to the monsters and improve game bar UI.
2. Henrik: Implement the rest of weapons we want to add.
3. Oskar: Start working on the map structure, add rooms that you can walk between and change how the rooms generate.
4. Mikael: Implement a check that checks if tile is walkable before allowing characters to move. Implement cooldowns for shooting and a dash function.



# Meeting 29.11.2021 11::15
Started the meeting with a slight worry about the approaching deadline.
**Participants**:
1. Jonas
2. Oskar
3. Henrik
4. Mikael

## Summary of works
1. Jonas
   Implemented two diffrent monsters. One seeking monster which attacks the player and one randomly moving monster.

2. Mikael
   Implemented a dash ability that might need to change. Done research on the best way to Implement cooldowns. Still a bit confused.

3. Henrik
   Done a lot of house keeping. Implemented a working wall collision detection. Gottten doxygen working.

4. Oskar
   Started working on map and how the player walks from one room to another. Worked on a death function and on power ups. Fine tuned some sprites.

## Challenges

1. Henrik had a lot of struggles with interfaces. Jonas computer experiences a bug where the monsters spawn in the wrong location. We all struggled with our code beeing too messy and having duplicated code.

## Actions
1. Starting documation to keep track of the growing project (extra meeting to go through how we will do this), members getting a more familiar overlook on the existing code.

## Project status
We have most of the crucial game features are now implemented but we are now struggling with time and our code being a little messy. Next step is to make our player able to enter and exit rooms. Then we soon have a quite playable game. We are still lacking in documentation and testing.

### TODOs
1. Jonas: Make one more monster class. Help henrik with developing powerups. Develop some AI types for the monsters.
2. Henrik: Find a test framework. Continue developing weapons, powerups and collsions. Maybe look into some UI stuff. 
3. Oskar: Make player able to walk from room to a diffrent room.
4. Mikael: Make the cooldown work. Help with AI development. Maybe start working on a leveling up system.
