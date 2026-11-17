@echo off
if exist bin\blackjack.exe del bin\blackjack.exe

g++ src/main.cpp src/game/*.cpp src/gui/*.cpp src/other/*.cpp -IC:\SFML\include -LC:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -o bin/blackjack.exe

if exist bin\blackjack.exe ( 
	echo Build successful.
	if not exist bin\assets xcopy /E /I /Y assets bin\assets
	bin\blackjack.exe
) else ( 
	echo Build failed.
)

pause
cls