#include<QCoreApplication>
#include<ftpget.h>
#include<QStringList>
#include<QUrl>

int main(int argc,char * argv[])
{
  QCoreApplication app(argc,argv);
  QStringList arg=QCoreApplication::arguments();


  FtpGet getter;
  if(!getter.getFile(QUrl(arg[1])))
    return 1;

  QObject::connect(&getter,SIGNAL(done()),&app,SLOT(quit()));

  return app.exec();

}
