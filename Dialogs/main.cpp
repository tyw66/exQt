#include<QApplication>
#include"mainboard.h"
int main(int argc,char* argv[])
{
  QApplication a(argc, argv);
  MainBoard board;
  board.show();
  return a.exec();

}
