/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "projectexplorer_export.h"

#include <QPointer>
#include <QWidget>

#include <utils/fancymainwindow.h>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

namespace ProjectExplorer {

class Project;
class Target;

namespace Internal {

class SelectorModel;
class SelectorTree;
class ProjectItem;

enum {
    ContextMenuItemAdderRole // To augment a context menu, data has a QMenu*
        = Qt::UserRole + 1,
    ItemActivaterRole,       // This item got activated and is now responsible for the central widget
    ActiveWidgetRole,        // This item's widget to be shown as central widget.
    ActiveIndexRole,          // This is the index of the currently selected item in the tree view

    ProjectDisplayNameRole   // Shown in the project selection combobox
};

class ProjectWindow : public Utils::FancyMainWindow
{
    Q_OBJECT

public:
    ProjectWindow();

private:
    void contextMenuEvent(QContextMenuEvent *event) override;

    void updatePanel();
    void openContextMenu(const QPoint &pos);
    void registerProject(Project *project);
    void deregisterProject(Project *project);
    void startupProjectChanged(Project *project);
    void projectSelected(int index);
    void itemActivated(const QModelIndex &index);
    ProjectItem *itemForProject(Project *project) const;

    SelectorModel *m_selectorModel;
    SelectorTree *m_selectorTree;
    QDockWidget *m_selectorDock;
    QComboBox *m_projectSelection;
};

} // namespace Internal
} // namespace ProjectExplorer
