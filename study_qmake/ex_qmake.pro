##--------------------------------------------------------
##学习QMake
##Create by tyw66
##--------------------------------------------------------
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += main.cpp

CONFIG+=testcase

#CONFIG += debug_and_release
CONFIG += build_all#在两种模式中构建

CONFIG(debug, debug|release) {
  TARGET = debug_binary
} else {
  TARGET = release_binary
}


exists(main.cpp){
    message("main.cpp file found")
}

win32:debug{
    CONFIG += console
}

message($$PWD)
message($${PWD})
message($$(PWD))
message($PWD)
message(${PWD})
message($(PWD))
message(-------------------)

DESTDIR = $$(PWD)
message(The project will be installed in $$DESTDIR)



DESTDIR = $(PWD)
  message(The project will be installed in the value of PWD)
  message(when the Makefile is processed.)


  message(Qt version: $$[QT_VERSION])
  message(Qt is installed in $$[QT_INSTALL_PREFIX])
  message(Qt resources can be found in the following locations:)
  message(Documentation: $$[QT_INSTALL_DOCS])
  message(Header files: $$[QT_INSTALL_HEADERS])
  message(Libraries: $$[QT_INSTALL_LIBS])
  message(Binary files (executables): $$[QT_INSTALL_BINS])
  message(Plugins: $$[QT_INSTALL_PLUGINS])
  message(Data files: $$[QT_INSTALL_DATA])
  message(Translation files: $$[QT_INSTALL_TRANSLATIONS])
  message(Settings: $$[QT_INSTALL_CONFIGURATION])
  message(Examples: $$[QT_INSTALL_EXAMPLES])
  message($$QMAKESPEC)


  message($$QMAKESPEC)

  linux-g++ {
      message(Linux)
  }


  win32:VERSION = 1.2.3.4 # major.minor.patch.build
  else:VERSION = 1.2.3    # major.minor.patch

 message($$_PRO_FILE_)
  message($$_PRO_FILE_PWD_)

CONTACT = firstname:middlename:surname:phone
  message($$split(CONTACT, :))


stuff = main.cpp




#contains(stuff, $$SOURCES){
#  message(ok)
#}


message(QMAKESPEC=$${QMAKESPEC})




FILE =F:/qt/Qt5.14.2/Docs/Qt-5.14.2/qtxml.qch
message($$basename(FILE))


fileName = ../1.txt
message($$clean_path($$fileName))

#返回所有已定义的变量名的列表
names = $$enumerate_vars()
for(name,names){
    message($$name)
}

message($${QT.charts.includes})
#message($$prompt(123))


#message($$files(E:\workshop\Code\*.txt))



#message($$cat(E:/workshop/Code/1.txt,false))


#message($$fromfile(../ex_process/ex_process.pro,SOURCES))




