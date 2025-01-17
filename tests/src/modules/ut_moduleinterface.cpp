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

#include "ut_moduleinterface.h"

#define protected public
#include "moduleinterface.h"
#undef protected

ut_moduleinterface_test::ut_moduleinterface_test()
{

}

TEST_F(ut_moduleinterface_test, ModuleInterface)
{
    ModuleInterface* test_module = new ModuleInterface();
    ASSERT_TRUE(test_module);
    ASSERT_TRUE(test_module->m_model);
    ASSERT_TRUE(test_module->m_worker);
    ASSERT_TRUE(test_module->m_selectBtn);
    ASSERT_TRUE(test_module->m_updateSelectBtnTimer);
    test_module->deleteLater();
}

TEST_F(ut_moduleinterface_test, setIconType)
{
    ModuleInterface* test_module = new ModuleInterface();
    test_module->setIconType(Model::Big);
    test_module->setIconType(Model::Small);
    test_module->deleteLater();
}

TEST_F(ut_moduleinterface_test, resizeEvent)
{
    ModuleInterface* test_module = new ModuleInterface();
    QResizeEvent event(QSize(test_module->width(),test_module->height()),QSize(120,120));
    test_module->resizeEvent(&event);
    EXPECT_TRUE(test_module->m_updateSelectBtnTimer->isActive());
    test_module->m_updateSelectBtnTimer->stop();
    test_module->deleteLater();
}
