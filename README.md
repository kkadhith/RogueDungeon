# RogueDungeon RPG
 
Authors: [Nathan Lee](https://github.com/ENathanLee) [Adhith Karthikeyan](https://github.com/kkadhith) [Elijah Fang](https://githhub.com/efang006) 
 
## Project Description
 * This project is interesting as an opportunity to design a game and experience the challenges in doing so.
 * We will primarily be using C++ as the backbone of our project. Additionally, we will be using Cmake. The C++ standard library provides everything we need to make this game. 
 * Player input to determine their choices throughout the game. Some examples include player creation, location, and enemies. Decisions made by the player will impact how the game plays out. Since the entire program will be done in the command line, the output will be in ascii.
 * One design pattern we will incorporate in this project is an abstract factory pattern. Throughout the game, the main character will be leveling up and increasing their stats. To simplify the creation of players / classes, a simple "factory" will be implemented. Within this class, class selection can be implemented easily based on the player's unique choice(s).
 * Another design pattern that we will incorporate is the composite pattern. For instance, hostile enemies such as Zombies or Dragonsare inherited from the Hostile class, which allows the fight method to be implemented easily between Hostile and Player classes.
## Class Diagram
![FactoryPattern](https://user-images.githubusercontent.com/24882134/120295803-599b1100-c27c-11eb-9072-2bd24f34e6b9.png)

This class diagram is a representation of the Abstract Factory Design pattern as well as a composite pattern. Firstly, the `selectRole()` method outputs a unique Player class such as an Assassin or Archer. Secondly, Players are able to fight against Hostile enemies due to the use of a composite pattern. Items provide buffs to the player and Hostile enemies have unique fighting methods.

 
 ## Screenshots
 ![Screenshot 2021-06-01 105058](https://user-images.githubusercontent.com/81644831/120368940-80326980-c2c7-11eb-9495-03a2d0e16a1a.png)
 ![Screenshot 2021-06-01 105316](https://user-images.githubusercontent.com/81644831/120369011-95a79380-c2c7-11eb-9bef-a5d66efc1aab.png)

 ## Installation/Usage
 In order to play this text based RPG, first clone the repo. Next, run CMake, which will create a test file used for testing purposes and `main`, which is the game executable. Running `./main` will allow you to play the game and instructions on how to navigate the menu will be displayed.
 ## Testing
 We validated this project using the Google Test module, which can be run locally after cloning the repo. For our tests, we wanted to make sure our constructors were initializing instances of player and hostile objects correctly, so we tested the constructors. We also tested if our mutator functions, like fight(Entity*), were calculating any changes to variables correctly.
 
