# COSC345-Project
![](https://github.com/Debug-Divas/COSC345-Project/assets/133945255/0ecb8e30-c168-44ce-aae8-2d179e21d62f)


## Description
-   The COSC345 project is a semester long project that is built using "two or more publicly available data sets (on different topics) that can be combined to add meaning to something, and build an app that uses that combined data for the betterment of the user or society".

## Our App
-   Our idea for the app is to make public information about MPs published on the parliament website easily viewable and searchable to the public. With the purpose of making people more informed about who they’re voting for especially in regards to the upcoming election. 

## Reports
-   [Assignment 1 - Report.pdf](https://github.com/Debug-Divas/COSC345-Project/blob/main/Assignment%201%20-%20Report.pdf)

-   [Retrospective](https://github.com/Debug-Divas/COSC345-Project/blob/a8f4f831a3b4ec6060aab7e8cfc9dbcb1ba77f7c/Retrospective%20-%20Debug%20Diva.pdf)

## How To Run the artefact
-   In the COSC345-Project Repository, go to Actions
-   On the left side-bar click on Windows Release then click on the latest passed workflow run
-   In the Artifacts section click on the zip file to download
-   Extract the downloaded zip file twice. Navigate to the `release` folder inside the newly extracted folder using the terminal
-   Run the command `./sqlite_qt.exe`

## Static Analysis Report

Of the 34 total issues with the code base, 32 of these issues are code style such as unused variable names and inconsistent applications of camel case, and 28 of the 32 originate from the web scraping code and other files that are not directly related to the main app itself. Because of this, we felt comfortable in prioritizing other more important work over rectifying these issues as they have no real effect on how the app runs and behaves.

Our continuous integration pipeline generates a makefile for our unit test program in order to get a code coverage report. However, the makefile appears to generate with faulty formatting that cannot be fixed manually because the file generates dynamically each time the Github actions workflow is activated (every time we push to main). Because of this, the CI pipeline fails mere lines before it can generate the code coverage, and with only a little guidance we have been unable to rectify this.

## Doxygen
[![Documentation](https://img.shields.io/badge/Documentation-Doxygen-blue.svg)](https://debug-divas.github.io/COSC345-Project/)

## Code Coverage Report 
[![C/C++ CI](https://codecov.io/gh/Debug-Divas/COSC345-Project/badge.svg?token=NA60E5SJRD)](https://app.codecov.io/gh/Debug-Divas/COSC345-Project)
## Github Actions
![Build](https://github.com/Debug-Divas/COSC345-Project/actions/workflows/windows_release.yml/badge.svg)

## Codacy Integration
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/1d03bbe8a8cf4618b91768661abe8e03)](https://app.codacy.com/gh/Debug-Divas/COSC345-Project/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

## Questionnaire
[![Questionnaire](https://img.shields.io/badge/Questionnaire-Google_form-purple.svg)](https://forms.gle/WD8rRjTr6eL4nhxh6)

## Trello
[![Task manager](https://img.shields.io/badge/Task_manager-Trello-red.svg)](https://trello.com/b/0s8Y3Pmd/cosc345)
