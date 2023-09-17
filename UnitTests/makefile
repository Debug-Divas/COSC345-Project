main.exe: install-qt-dependencies
    cl /Zi main.cpp -o main.exe

install-qt-dependencies:
    choco install qt5 -y
    # You may need to customize this depending on your specific needs

clean:
    del main.exe
