#ifndef HOST_BROWSER_H
#define HOST_BROWSER_H

#include <QFileSystemModel>
#include "views/browser.h"

// HostBrowser, a Browser class used for the local/host system
class HostBrowser : public Browser
{
	Q_OBJECT

public:
	HostBrowser(QWidget* parent = 0, Qt::WindowFlags flags = 0);

protected:
	void AddCustomToolBarActions();
	void GoToRoot();
	void OnModelItemDoubleClick(const QModelIndex& index);

private:
	QAction* m_homeAction;
	QFileSystemModel* m_model;

private slots:
	void GoToHome();
};

#endif