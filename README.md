# Generic Text RPG
 
Authors: [Nathan Lee](https://github.com/ENathanLee) [Adhith Karthikeyan](https://github.com/kkadhith) [Elijah Fang](https://githhub.com/efang006) 
 
## Project Description
 * This project is interesting as an opportunity to design a game and experience the challenges in doing so.
 * We will primarily be using C++ as the backbone of our project. Additionally, we will be using Cmake. The C++ standard library provides everything we need to make this game. 
 * Player input to determine their choices throughout the game. Some examples include player creation, location, and enemies. Decisions made by the player will impact how the game plays out. Since the entire program will be done in the command line, the output will be in ascii.
 * One design pattern we will incorporate in this project is an abstract factory pattern. Throughout the game, the main character will be leveling up and increasing their stats. Enemies must dynamically adapt to each "stage" in the game i.e., early, mid, and late stages of the game. Some weapons are stronger and enemies toward the late stages of the game will use strong weapons to challenge the main character. To simplify the creation of groups of hostile enemies, a general factory "HostileFactory" is responsible for creating different "sets" of enemies.  
 * Another design pattern that we will incorporate is the decorator pattern. In almost all RPGs, weapons/tools can be upgraded or modified. A single weapon can have many combinations of modifications, and creating a subclass for every modification of a weapon/tool can quickly get overwhelming. A decorator can simplify this problem since a single class can modify the base weapon(s).

## Class Diagram
![Generic Text RPG(1)](![FactoryPattern](https://user-images.githubusercontent.com/24882134/120287862-80554980-c274-11eb-818b-35d22580e153.png)

This class diagram is a representation of the Abstract Factory Design pattern, since a single "EntityFactory" creates a factory that then creates entities that change based on the stages of the game (Early, Mid, Late). The diagram is not a complete representation of the game--we believe we need a better understanding of Factory Design Patterns, which will be gone over next week in class. Since this game has many different entities, objects, and customization features, it quickly becomes very complex. We believe our model needs improvement, so we will be getting TA guidance for our diagram design.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
