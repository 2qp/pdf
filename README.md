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


#### instructions
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
