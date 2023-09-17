name: UnitTests

on:
  push:
    branches:
    - main

jobs:
  build:
    runs-on: windows-latest
    steps:
    - name: Checkout code
      uses: actions/checkout@v2

    - name: Install Qt Dependencies
      run: |
        choco install qt5 -y

    - name: Build Qt Project
      run: |
        qmake -r
        nmake

    - name: Build main.cpp
      run: |
        cl /Zi main.cpp -o main.exe

    - name: Run Qt Project
      run: |
      # Replace 'your_executable.exe' with the actual name of your Qt application executable.
        .\main.exe
