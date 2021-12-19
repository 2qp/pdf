## Tool for extracting text from PDF Files using QT5

---------------------------------------------------
##### Tested Environment
- OS : Debian 11 Bullseye
- QT : 5.15.2
- QT Creator : 4.14.1
- QMake : 3.1
---------------------------------------------------
Libraries
---------------------------------------------------


# Linux instructions
```sh
#update the repo
sudo apt-get update

#libqt5pdf5
sudo apt-get install libqt5pdf5

#qt5-dev
sudo apt-get install qtpdf5-dev

#pdf5 widgets
sudo apt-get install libqt5pdfwidgets5

```

----------------------------
#### adding Qt5PDF5 to a qt project
```sh
# linking the module in .pro file

QT       += core gui pdf

# then run qmake
```
----------------------------

##### Icon Resources
```sh

<a target="_blank" href="https://icons8.com/icon/47259/remove">Remove</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>

<a target="_blank" href="https://icons8.com/icon/v16dJrelnUu6/import-pdf">Import Pdf</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>


<a target="_blank" href="https://icons8.com/icon/Zh9dun0fZ6kf/rich-text-converter">Rich Text Converter</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>

<a target="_blank" href="https://icons8.com/icon/37667/clear-symbol">Clear Symbol</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>

```
---
---
# Windows Environment
##### Tested Environment
- OS : WIndows 10 Pro
- QT : 5.15.2
- QT Creator : 6.0
- QMake : 3.1
- CMake tools : CMake 3.21.1(Qt)
---------------------------------------------------
## Prerequisites
###### Download Build Tools
 
 ```sh
https://visualstudio.microsoft.com/visual-cpp-build-tools/
```
###### Open the downloaded files and get these individual components
###### compilers, build tools and runtimes
```sh
MSVC v142 - VS 2019 C++ x64/84 Built Tools(latest visual c++ v142)
```
###### SDKs, Libraries and frameworks
```sh
windows 10 sdk 10.0.19041.0
windows 10 sdk 10.0.18362.0 [optional]

C++ ATL for latest v142 build tools(x86 & x64)
C ++ ATL for latest v142 built tools with spectre mitigations (x86 & x64)

C++ MFC for latest v142 build tools(x86 & x64)
C ++ MFC for latest v142 built tools with spectre mitigations (x86 & x64)
```
#### Qt Installer selections
```sh
[x] qt 5.15.2 -->
QTWebEngine Module
MSVC 2019 64 bit
UWP x64 (MSVC 2019)
Sources
Qt Script(Deprecated)
```

##### other tools
```sh
Python 2.7 or later
Ninja : https://github.com/ninja-build/ninja/releases
```

##### Environment variables
```sh
|| Add these to system variables Path (Depends on your locations) ||
C:\Qt\5.15.2\msvc2019_64\bin
C:\Program Files(x86)\Microsot Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64
C:\\Python27\
C:\ninja
```
---
# Building QT PDF
```sh
Search on windows search bar for "Qt 5.15.2 (MSVC 2019 64-bit)" & open
```
###### on that terminal
```sh
# change current directory
cd C:\Program Files(x86)\Microsot Visual Studio\2019\BuildTools\VC\Auxiliary\Build

# Setup Environment
(compiler) (architecture) (Windows SDK Version)
vcvarsall.bat amd64 10.0.19041.0

# Change current working dir
cd C:\Qt\5.15.2\Src\QTWebEngine

# create build dir
mkdir build

# change working dir to build
cd build

# building
qmake ../../qtwebengine -- -no-build-qtwebengine-core

# making(this will take care of ninja and gn builds)
nmake

# installing the make
nmake install
```

### running a project
###### linking the pdf module
```sh
# open .pro file & add the module
QT       += core gui pdf
```

###### Project Settings
```sh
qt creator -> tools-> options-> kits
.. and select Desktop Qt 5.15.2 MSVC2019-64bit

#compilers selections
c: Microsot Visual C++ Compiler 16.11.31911.196(amd64)

c++ : Microsot Visual C++ Compiler 16.11.31911.196(amd64)

Cmake tools : CMake 3.21.1(Qt)

# Profile selections
on the left side qt creator panel, (spanner icon)
select project-> and select the Desktop Qt 5.15.2 MSVC2019 64bit kit
disable other kits

# Then Run qmake and test the project
```
