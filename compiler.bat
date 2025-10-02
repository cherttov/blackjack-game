@echo off
if exist bin\blackjack.exe del bin\blackjack.exe

g++ src/main.cpp src/game/*.cpp src/gui/*.cpp src/other/*.cpp -IC:\SFML\include -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -o bin/blackjack.exe

if exist bin\blackjack.exe ( 
	echo SFML: 2.6.1
	echo.
	echo Build successful.
	bin\blackjack.exe
) else ( 
	echo Build failed. 
)

pause
cls