/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
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

#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QPainter>
#include <QKeyEvent>

#include <DGuiApplicationHelper>
#include <DPalette>
#include <DLabel>
#include <DPushButton>
#include <DWidget>
#include <QPainterPath>

DGUI_USE_NAMESPACE
DWIDGET_USE_NAMESPACE

//导航按钮类
class NavigationButton : public DPushButton
{
    Q_OBJECT
public:
    explicit NavigationButton(QString text, DWidget* parent = nullptr);

    void initButton();

    bool needFrame;//需要画框标志位

protected:
    // QSize setHint();
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void widthChanged(int);

private:
    DLabel* m_label;
    bool isEnter;
};

#endif  // NAVIGATIONBUTTON_H
