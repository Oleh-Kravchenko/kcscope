#ifndef __KCSCOPE_H
#define __KCSCOPE_H

#include <QtGui/qwidget.h>

#include <QStandardItemModel>

namespace Ui
{
	class KCScopeWidget;
}

class KCScopeWidget:public QWidget
{
Q_OBJECT

public:
	KCScopeWidget(QWidget* parent, QAbstractItemModel* model);

	virtual ~KCScopeWidget();

private:
	Ui::KCScopeWidget* ui;
};

#endif /*__KCSCOPE_H */
