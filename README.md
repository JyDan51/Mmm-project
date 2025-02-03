Instead of full-fledged documentation, I highlighted almost every line of the code by commenting on it.
Initially, I was working on another project. I was planning to create a full-fledged manga library using 
js or kotlin, but I got stuck in an endless cycle of dead ends and couldn't get out of it by the deadline.

And now about the program that I made. It's a simple game from my childhood named HANGMAN.
I wont describe every line of the code.
I just ask you to just play and hope you wont look for bugs here.
Ive gone crazy trying to fix them.



These are just commands to compile.
I used this guide to find this comands   https://www.youtube.com/watch?v=dQw4w9WgXcQ 

compilation commands
g++ -c main.cpp -o main.o
g++ -c Game.cpp -o Game.o
g++ -c Leaderboard.cpp -o Leaderboard.o
g++ -c SaveManager.cpp -o SaveManager.o
g++ -c Player.cpp -o Player.o

g++ main.o Game.o Leaderboard.o SaveManager.o Player.o -o hangman.exe
