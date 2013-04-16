#ifndef __KCSCOPE_PUGIN_H
#define __KCSCOPE_PUGIN_H

#include <interfaces/iplugin.h>

#include <QVariant>
#include <QStandardItemModel>

class QModelIndex;
class KUrl;
class KJob;

namespace KDevelop
{
	class IProject;
	class IDocument;
	class ParseJob;
}

class KCScopePlugin : public KDevelop::IPlugin
{
	Q_OBJECT

	public:
		KCScopePlugin(QObject* parent, const QVariantList& args);

	public slots:
		void projectClosed(KDevelop::IProject*);

		void projectOpened(KDevelop::IProject*);

	private:
		QStandardItemModel* m_model;
};

#endif /* __KCSCOPE_PUGIN_H */
