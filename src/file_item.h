/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
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

#ifndef FILEITEM_H
#define FILEITEM_H

#include <QFileInfo>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidgetItem>
#include <QWidget>

#include "dimagebutton.h"
#include "label.h"
#include "line_edit.h"

DWIDGET_USE_NAMESPACE

class FileItem : public QWidget
{
    Q_OBJECT
    
public:
    FileItem(QWidget *parent=0);
    
    QFileInfo getFileInfo();
    QListWidgetItem* getItem();
    QString getRecodingFilepath();
    bool eventFilter(QObject *, QEvent *event);
    int getDuration();
    void enterEvent(QEvent *event);
    void highlight();
    void paintEvent(QPaintEvent *);
    void setFileInfo(QFileInfo info);
    void unhighlight();
    
    static const int STATUS_NORMAL;
    static const int STATUS_RENAME;
    static const int STATUS_PLAY;
    static const int STATUS_PLAY_PAUSE;
    static const int STATUS_PAUSE_PLAY;
    
public slots:
    void switchStatus(int status);
    void switchPlay();
    void switchNormal();
    void updateDurationLabel();
    
signals:
    void pause();
    void play();
    void resume();
    void stop();
    void enter();
    
private:
    DImageButton *pausePlayButton;
    DImageButton *pauseStopButton;
    DImageButton *playPauseButton;
    DImageButton *playStartButton;
    DImageButton *playStopButton;
    DImageButton *renameButton;
    Label *durationLabel;
    Label *fileIcon;
    Label *nameLabel;
    LineEdit *lineEdit;
    QFileInfo fileInfo;
    QHBoxLayout *actionLayout;
    QHBoxLayout *fileDisplayLayout;
    QHBoxLayout *fileRenameLayout;
    QHBoxLayout *infoLayout;
    QHBoxLayout *layout;
    QHBoxLayout *normalActionLayout;
    QHBoxLayout *pausePlayActionLayout;
    QHBoxLayout *playActionLayout;
    QHBoxLayout *playPauseActionLayout;
    QListWidgetItem *item;
    QString durationTemplate;
    QString nameTemplate;
    QWidget *fileDisplayContainer;
    QWidget *fileRenameContainer;
    QWidget *normalActionContainer;
    QWidget *pausePlayActionContainer;
    QWidget *playActionContainer;
    QWidget *playPauseActionContainer;
    bool isEntered;
    bool switchLock;
    int currentStatus;
    int renameBeforeStatus;
};

#endif
