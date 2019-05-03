#include "ftpget.h"
#include<QUrl>
#include<QFileInfo>
#include<iostream>

FtpGet::FtpGet(QObject *parent)
{
  connect(&ftp,SIGNAL(done(bool)),this,SLOT(ftpDone(bool)));
}

bool FtpGet::getFile(const QUrl &url)
{
  //  if(!url.isValid())
  //    {
  //      std::cerr<<"Error: invalid URL"<<std::endl;
  //      return false;
  //    }
  //  if(url.scheme()!="ftp")
  //    {
  //      std::cerr<<"Error ";
  //      return false;
  //    }

  QString localFileName=QFileInfo(url.path()).fileName();
  if(localFileName.isEmpty())
    localFileName="ftp.out";

  file.setFileName(localFileName);

  if(!file.open(QIODevice::WriteOnly))
    {
      //       std::cerr<<"Error:Cannot write file";
      //       return false;
    }

  ftp.connectToHost(url.host(),url.port(21));
  ftp.login();
  ftp.get(url.path(),&file);
  ftp.close();
  return true;
}


void FtpGet::ftpDone(bool error)
{
  if(error)
    {
      std::cerr<<"error";
    }
  else
    {
      std::cerr<<"file download as"<<qPrintable(file.fileName())<<std::endl;
    }
  file.close();
  emit done();

}

