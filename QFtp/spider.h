#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QUrl>
#include<QUrlInfo>

class Spider : public QObject
{
  Q_OBJECT
public:
  Spider(QObject *parent = 0);

  bool getDirectory(const QUrl &url);

signals:
  void done();

public slots:
  void ftpDone(bool error);
  void ftpListInfo(const QUrlInfo &urlInfo);




};

#endif // SPIDER_H
