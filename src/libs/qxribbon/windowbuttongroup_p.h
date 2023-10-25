/**
 * Copyleft (C) 2023 maminjie <canpool@163.com>
 * SPDX-License-Identifier: MulanPSL-2.0
 **/
#ifndef WINDOWBUTTONGROUP_P_H
#define WINDOWBUTTONGROUP_P_H

#include "qxribbon_global.h"
#include <QPushButton>

QX_RIBBON_BEGIN_NAMESPACE

class WindowButtonGroup;

class WindowButton : public QPushButton
{
    Q_OBJECT
public:
    explicit WindowButton(QWidget *p = Q_NULLPTR);
};

class WindowButtonGroupPrivate : public QObject
{
    Q_OBJECT
    QX_DECLARE_PUBLIC(WindowButtonGroup)
public:
    WindowButtonGroupPrivate();

    void setupMinimizeButton(bool on);
    void setupMaximizeButton(bool on);
    void setupCloseButton(bool on);
    void updateSize();
    void resize(QSize size);
    QSize sizeHint() const;
    int groupHeight() const;
public slots:
    void buttonClicked();
public:
    WindowButton *m_closeButton;
    WindowButton *m_minimizeButton;
    WindowButton *m_maximizeButton;
    int m_closeStretch;
    int m_maxStretch;
    int m_minStretch;
    qreal m_iconScale;
};

QX_RIBBON_END_NAMESPACE

#endif // WINDOWBUTTONGROUP_P_H