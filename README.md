# Chess Game
 
Authors: [Aadil Umar](https://github.com/AadilU), [Angel Ibanez](https://github.com/anglesideangel), [Steven Nguyen](https://github.com/steven1248012)

## Project Description

Creating and implementing designs to a chess game is interesting to us because we want to explore how developing a game can lead us to making more complex games in the future. We, as a team, think chess is a game where users would need strategy and logical thinking in order to win the game. Moreover, creating this type of game is very important to us as we would like to apply our programming skills and knowledge to design a game that is both competitive and fun for users to play. We plan on implementing our version of chess with C++ to focus on object oriented style programming and will use CMake to execute our program. The input for this game will be taken from the user's mouse in order to move and select their desired piece, and the output will be an updated chess board after every move so both players are able to see and know the state of the game. The features we plan to implement are the projection of a typical chess board, the chess game, showing the direction pieces are allowed to move. We plan to implement the graphics of the game using [SDL2](https://www.libsdl.org/)

## Class Diagram
![Chess Game UML](https://user-images.githubusercontent.com/102494188/166168642-aa828f73-7861-4ef9-a6eb-9a5586c59bd5.png)
In our diagram, we have 6 classes(one for each piece type), which all inherit atributes and operations from our class "chess piece". Our class "Board", which aggregates "chess piece", will make up the chess game which is composed by our class "Sqaure". We plan on updating our diagram as implementation continues and new features/classes are thought of and added. 

## Design Patterns
We plan to use the composite and the strategic design pattern to implement our code.

We picked the composite pattern because our program, creating a chess game, needed a way to implement its game board. As a group, we decided that a composite implementation would be best suited since we could use our class "square" and use it to build our chess board. The pattern made coding easier since we were able to reuse code from our "sqaure" class to make our class "chess board" which consists of 64 squares.

We also plan to implement a strategy pattern in our chess game so that our algorithm for each certain piece would be much more efficient since each piece has different actions. As a team, we decided to pick this pattern so that we would not need to implement repeatable code and functionality which would cause a lot of confusion and repetitive code. Furthermore, each chess piece will inherit functions and variables from the main class.  With this strategy being implemented in our project,we will not have duplicate and unnecessary code which would allow us to detect errors in an easier manner. 

![Strategy Class Diagram Chess Piece](https://user-images.githubusercontent.com/42853025/168699738-8720c244-2dac-4aa8-9eb2-9739971b0c46.png)

 ## Screenshots
 ###### Board Initialization:
 <img width="639" alt="Screen Shot 2022-06-02 at 11 28 41 PM" src="https://user-images.githubusercontent.com/102494188/171799835-12dd123c-b2b6-4f77-a5ec-5d2e776b0dbd.png">

###### Piece Movement with Indicator:
<img width="639" alt="Screen Shot 2022-06-02 at 11 33 17 PM" src="https://user-images.githubusercontent.com/102494188/171800258-f5c4875d-bfd3-43a4-ae02-45c31e7fc23c.png">

<img width="634" alt="image" src="https://user-images.githubusercontent.com/102494188/171932135-35e76373-f8ee-480b-8cb8-80e25ee3981c.png">

###### Piece Moved:
<img width="639" alt="Screen Shot 2022-06-02 at 11 33 23 PM" src="https://user-images.githubusercontent.com/102494188/171800344-71a9f3fe-7678-4b67-8eba-14c2d145ed5a.png">

<img width="634" alt="image" src="https://user-images.githubusercontent.com/102494188/171932199-741d43f1-c5ad-4871-86d6-427da726f47f.png">



 ## Installation/Usage
 In order to install our version of chess, you will need to:
 1) Download [SDL2](https://www.libsdl.org/download-2.0.php) for your operating system(Mac,Windows, or Linux)
 2) Follow this [guide](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php) on how to set it up on your machine
 ###### Note: if you are using windows or linux you will have alot of IDE's/Compilers to choose from. Pick the one you prefer the most. Mac users will have to download and install Xcode through the app store.
 3) Go to our repository's "code" drop down menu and download the zip file, from there you simply upload the files to your IDE/Compiler.

 ## Testing
 We tested our code for memory leaks through Xcodes helpful "instrument" application since we were unable to access valgrind. 
 ###### Memory Leak Free!
 <img width="609" alt="image" src="https://user-images.githubusercontent.com/102494188/171803350-1b84e11c-0611-4202-8e9e-1c5a4d5c8a1c.png">
 
 ###### Unit Testing
 We tested the creation of our objects using google test, but since the movement logic was too complicated for google test, we tested the actions manually.

 <img width="612" alt="Screen Shot 2022-06-03 at 3 25 52 PM" src="https://user-images.githubusercontent.com/76264953/171962238-533068c8-645b-42c5-81ba-e31694bd3018.png">

 
