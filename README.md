# Chess Game
 
Authors: [Aadil Umar](https://github.com/AadilU), [Angel Ibanez](https://github.com/anglesideangel), [Steven Nguyen](https://github.com/steven1248012)

## Project Description

Creating and implementing designs to a chess game is interesting to us because we want to explore how developing a game can lead us to making more complex games in the future. We, as a team, think chess is a game where users would need strategy and logical thinking in order to win the game. Moreover, creating this type of game is very important to us as we would like to apply our programming skills and knowledge to design a game that is both competitive and fun for users to play. We plan on implementing our version of chess with C++ to focus on object oriented style programming and will use CMake to execute our program. The input for this game will be taken from the user's keyboard in order to move and select their desired piece, and the output will be an updated chess board after every move so both players are able to see and know the state of the game. The features we plan to implement are the projection of a typical chess board, the chess game, show the direction pieces are allowed to move, the ability to save and reload a game, and finally the ability to play against a computer.

## Class Diagram
![Chess Game UML](https://user-images.githubusercontent.com/102494188/166168642-aa828f73-7861-4ef9-a6eb-9a5586c59bd5.png)
In our diagram, we have 6 classes(one for each piece type), which all inherit atributes and operations from our class "chess piece". Our class "Board", which aggregates "chess piece", will make up the chess game which is composed by our class "Sqaure". We plan on updating our diagram as implementation continues and new features/classes are thought of and added. 

We plan to use the composite and the strategic design pattern to implement our code.

We picked the composite pattern because our program, creating a chess game, has several classes that can build off of one standard class, such as our pieces. We implemented our board using the composite pattern and will implement our pieces using it. The pattern helped us write better code as it kept us from re-writing code we already implemented and kept it easier to understand.

We also plan to implement a strategy pattern in our chess game so that our algorithm for each certain piece would be much more efficient since each piece has different actions. As a team, we decided to pick this pattern so that we would not need to implement repeatable code and functionality which would cause a lot of confusion and repetitive code. Furthermore, each chess piece will inherit functions and variables from the main class.  With this strategy being implemented in our project,we will not have duplicate and unnecessary code which would allow us to detect errors in an easier manner. 




 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
