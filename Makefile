all: unit_test.exe, application.exe

application.exe: qtGuiApplication/main.cpp
	cl /Zi qtGuiApplication/main.cpp -o application.exe

unit_test.exe: UnitTests/main.cpp
	cl /Zi UnitTests/main.cpp -o unit_test.exe
