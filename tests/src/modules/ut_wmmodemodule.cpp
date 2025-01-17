/*
* Copyright (C) 2019 ~ 2020 Deepin Technology Co., Ltd.
*
* Author:     zhangyunfeng <zhangyunfeng@uniontech.com>
* Maintainer: zhangyunfeng <zhangyunfeng@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ut_wmmodemodule.h"

#define protected public
#include "wmmodemodule.h"
#include "model.h"
#undef protected

ut_wmmodemodule_test::ut_wmmodemodule_test()
{

}

TEST_F(ut_wmmodemodule_test, WMModeModule)
{
    WMModeModule* test_module = new WMModeModule();
    ASSERT_TRUE(test_module);
    ASSERT_TRUE(test_module->m_layout);
    ASSERT_TRUE(test_module->m_efficientWidget);
    ASSERT_TRUE(test_module->m_fashionWidget);
    EXPECT_EQ(true,test_module->m_first);
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, updateBigIcon)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->updateBigIcon();
    EXPECT_EQ(test_module->m_fashionWidget->m_size.width(),
              test_module->m_fashionWidget->m_borderWidget->width());
    EXPECT_EQ(test_module->m_fashionWidget->m_size.height(),
              test_module->m_fashionWidget->m_borderWidget->height());
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, updateSmallIcon)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->updateSmallIcon();
    EXPECT_EQ(test_module->m_fashionWidget->m_size.width(),
              test_module->m_fashionWidget->m_borderWidget->width());
    EXPECT_EQ(test_module->m_fashionWidget->m_size.height(),
              test_module->m_fashionWidget->m_borderWidget->height());
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, updateSelectBtnPos)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->updateSelectBtnPos();
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, onWMModeChanged)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->onWMModeChanged(Model::WM_2D);
    EXPECT_TRUE(test_module->m_efficientWidget->m_borderWidget->m_checked);
    EXPECT_FALSE(test_module->m_fashionWidget->m_borderWidget->m_checked);

    test_module->onWMModeChanged(Model::WM_3D);
    EXPECT_FALSE(test_module->m_efficientWidget->m_borderWidget->m_checked);
    EXPECT_TRUE(test_module->m_fashionWidget->m_borderWidget->m_checked);
     
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, setFirst)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->setFirst(true);
    EXPECT_TRUE(test_module->m_first);

    test_module->setFirst(false);
    EXPECT_FALSE(test_module->m_first);
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, keyPressEvent)
{
    WMModeModule* test_module = new WMModeModule();
    QKeyEvent keyEvent(QEvent::KeyPress,Qt::Key_Left,Qt::NoModifier);
    test_module->m_model->setWmType(Model::WM_2D);
    test_module->keyPressEvent(&keyEvent);

    QKeyEvent keyEvent1(QEvent::KeyPress,Qt::Key_Right,Qt::NoModifier);
    test_module->m_model->setWmType(Model::WM_3D);
    test_module->keyPressEvent(&keyEvent1);
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, paintEvent)
{
    WMModeModule* test_module = new WMModeModule();
    QPaintEvent *event;
    test_module->m_model->setWmType(Model::WM_3D);
    test_module->paintEvent(event);
    test_module->m_model->setWmType(Model::WM_2D);
    test_module->paintEvent(event);

    test_module->m_first = false;
    test_module->m_model->setWmType(Model::WM_3D);
    test_module->paintEvent(event);
    test_module->m_model->setWmType(Model::WM_2D);
    test_module->paintEvent(event);
     
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, onSetModeNormal)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->onSetModeNormal();
    test_module->deleteLater();
}

TEST_F(ut_wmmodemodule_test, onSetModeEfficient)
{
    WMModeModule* test_module = new WMModeModule();
    test_module->onSetModeEfficient();
    test_module->deleteLater();
}
