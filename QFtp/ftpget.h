#ifndef FTPGET_H
#define FTPGET_H

#include <QObject>
#include<QFtp>
#include<QFile>

class FtpGet:public QObject
{
  Q_OBJECT
public:
  FtpGet(QObject *parent=0);
  bool getFile(const QUrl &url);


signals:
  void done();

private slots:
  void ftpDone(bool error);

private:
  QFtp ftp;
  QFile file;

};

#endif // FTPGET_H
