/***********************************************************************
*PointDownload
*Copyright (C) 2014  PointTeam
*
* Author:     Match <2696627729@qq.com>
* Maintainer: Match <2696627729@qq.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/

#ifndef MIDDLESENDER_H
#define MIDDLESENDER_H

#define REFRESH_TIMER 2000

#include <QObject>
#include <QTimer>
#include <QDebug>
#include "SysData/dataflow.h"
#include "SysData/getspeed.h"

class MiddleSender : public QObject
{
    Q_OBJECT
    //将c++数据暴露给qml使用
    Q_PROPERTY(double cpuUsage READ getCpuUsage WRITE setCpuUsage NOTIFY sendCpuUsageChange)
    Q_PROPERTY(double downSpeed READ getDownSpeed WRITE setDownSpeed NOTIFY sendDownSpeedChange)
    Q_PROPERTY(double upSpeed READ getUpSpeed WRITE setUpSpeed NOTIFY sendUpSpeedChange)
    Q_PROPERTY(double diskUsage READ getDiskUsage WRITE setDiskUsage NOTIFY sendDiskUsageChange)
    Q_PROPERTY(QString dataList  READ getDataList  WRITE setDataList NOTIFY sendDataListChange)

public:
    explicit MiddleSender(QObject *parent = 0);

    double getCpuUsage();
    void setCpuUsage(double usage);
    double getDownSpeed();
    void setDownSpeed(double speed);
    double getUpSpeed();
    void setUpSpeed(double speed);
    double getDiskUsage();
    void setDiskUsage(double usage);
    QString getDataList();
    void setDataList(QString tmpList);

signals:
    void sendCpuUsageChange();
    void sendDownSpeedChange();
    void sendUpSpeedChange();
    void sendDiskUsageChange();
    void sendDataListChange();

public slots:
    void updateDate();      //由计时器触发的实时刷新使用率的槽

private:
    double cpuUsage;
    double downSpeed;
    double upSpeed;
    double diskUsage;
    QString dataList;//星期一至星期日的数据列表
};

#endif // MIDDLESENDER_H
