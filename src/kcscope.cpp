#include "kcscope.h"

#include "ui_kcscope.h"
#include <qlibrary.h>
#include <qlibraryinfo.h>
#include <qhelpengine.h>
#include <qdir.h>

KCScopeWidget::KCScopeWidget(QWidget* parent):QWidget(parent), ui(new Ui::KCScopeWidget)
{
	ui->setupUi(this);
}

KCScopeWidget::~KCScopeWidget()
{
	delete ui;
}

#include "kcscope.moc"
