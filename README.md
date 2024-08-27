# Welcome to My Mastermind
***

## Task
Write a program that allows the user to play the classic "Mastermind" game from the command line.
Users are able to set the answer code and number of attempts allowed - the answer is 4 digits (0-9).
After each guess, the program will display the number of well placed pieces and misplaced pieces. 

## Description
In order to solve the problem, the program must parse the user's input from the command line.
After receiving the guess input, it is compared to the answer. 
If a correct integer in the correct place is encountered, we incriment the correct count.
If a correct integer is in the incorrect place, we incriment the misplaced pieces count. 
If the user guesses correctly, the user is notified and the program ends.
If all rounds are exhausted without a correct guess, inform the user of the correct code and end.

## Installation
To install the project, type "make" in the command line while in the same directory as the game files.

## Usage
./my_mastermind [-c] [-t]
c: specifies the secret code, if no code is specified, code will be randomly generated
t: specifies number of attempts 

### The Core Team
Kimberly Arvin

_Made at [Qwasar SV -- Software Engineering School](https://qwasar.io)_
![Qwasar SV -- Software Engineering School's Logo](https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png)