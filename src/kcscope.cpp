#include "kcscope.h"

#include "ui_kcscope.h"
#include <qlibrary.h>
#include <qlibraryinfo.h>
#include <qhelpengine.h>
#include <qdir.h>

KCScopeWidget::KCScopeWidget(QWidget* parent, QAbstractItemModel* model):QWidget(parent), ui(new Ui::KCScopeWidget)
{
	ui->setupUi(this);

	ui->Projects->setModel(model);
}

KCScopeWidget::~KCScopeWidget()
{
	delete ui;
}

#include "kcscope.moc"
