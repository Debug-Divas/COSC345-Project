all: main.exe unit_test.exe

main.exe: qtGuiApplication/main.cpp
	cl /Zi qtGuiApplication/main.cpp -o main.exe

unit_test.exe: UnitTests/UnitTests.cpp
	cl /Zi UnitTests/UnitTests.cpp -o unit_tests.exe
