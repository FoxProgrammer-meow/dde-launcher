/*
 * Copyright (C) 2018 ~ 2028 Uniontech Technology Co., Ltd.
 *
 * Author:     chenjun <chenjun@uniontech.com>
 *
 * Maintainer: chenjun <chenjun@uniontech.com>
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
 */

#ifndef LauncherUnitTest_H
#define LauncherUnitTest_H

#include <QObject>

class LauncherUnitTest : public QObject
{
    Q_OBJECT
public:
    explicit LauncherUnitTest(QObject *parent = nullptr);
    ~LauncherUnitTest();
    void initTestCase();
    void cleanupTestCase();
private slots:
    //第一个测试单元
    void case1_test();
    //第二个测试单元 测试DBusDisplay 接口
    void case2_testDisplayDBus();
    //第三个测试单元 测试DBusDock
    void case3_testDockDBus();
    //第四个测试单元 测试DBusFileInfo
    void case4_testFileInfoDBus();
    //第五个测试单元 测试DBusLauncher
    void case5_testLauncherDBus();
    //第六个测试单元 测试DBusMenu
    void case6_testMenuDBus();
    //第七个测试单元 测试DBusMenuManager
    void case7_testMenuManagerDBus();
    //第八个测试单元 测试DBusStartManager
    void case8_testStartManagerDBus();
    //第九个测试单元 测试MonitorInterface
    void case9_testMonitorInterface();
};

#endif // LauncherUnitTest_H
