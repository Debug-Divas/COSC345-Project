all: main.exe unit_test.exe

main.exe: qtGuiApplication/main.cpp
	cl /Zi qtGuiApplication/main.cpp -o main.exe

unit_test.exe: UnitTests/main.cpp
	cl /Zi UnitTests/main.cpp -o unit_test.exe
