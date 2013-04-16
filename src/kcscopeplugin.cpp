#include "kcscope.h"
#include "kcscopeplugin.h"

#include <interfaces/icore.h>
#include <interfaces/iuicontroller.h>
#include <interfaces/iprojectcontroller.h>
#include <interfaces/iproject.h>
#include <KPluginFactory>
#include <KLocalizedString>
#include <KAboutData>
#include <QTreeView>

K_PLUGIN_FACTORY(KCScopeFactory, registerPlugin<KCScopePlugin>(); )

K_EXPORT_PLUGIN(
	KCScopeFactory(
		KAboutData(
			"kdevkcscope","kdevkcscope",
			ki18n("KCScope"), "0.1",
			ki18n("KDevPlatform KCScope plugin"),
			KAboutData::License_GPL
		)
	)
)

using namespace KDevelop;

class KDevProjectViewFactory: public KDevelop::IToolViewFactory
{
	public:
		KDevProjectViewFactory(QAbstractItemModel* model):model(model) {}
		
		virtual QWidget* create(QWidget* parent = 0)
		{
			KCScopeWidget* view = new KCScopeWidget(parent);

			return(view);
		}

		virtual Qt::DockWidgetArea defaultPosition() { return Qt::LeftDockWidgetArea; }

		virtual QString id() const
		{
			return("org.kdevelop.KCScopePlugin");
		}

	private:
		QAbstractItemModel *model;
};

KCScopePlugin::KCScopePlugin(QObject* parent, const QVariantList&):KDevelop::IPlugin(KCScopeFactory::componentData(), parent)
{
	m_model = new QStandardItemModel(this);

	core()->uiController()->addToolView(i18n("KCScope"), new KDevProjectViewFactory(m_model));

	connect(core()->projectController(), SIGNAL(projectOpened(KDevelop::IProject*)), this, SLOT(projectOpened(KDevelop::IProject*)));
	connect(core()->projectController(), SIGNAL(projectClosed(KDevelop::IProject*)), this, SLOT(projectClosed(KDevelop::IProject*)));
}

void KCScopePlugin::projectOpened(IProject* p)
{
	m_model->appendRow(new QStandardItem(p->name()));
}

void KCScopePlugin::projectClosed(IProject* p)
{
	QList <QStandardItem*> items = m_model->findItems(p->name());

	if(!items.isEmpty()) {
		QStandardItem* it = items.takeFirst();

		m_model->removeRow(it->row());
	}
}
