#ifndef DBUSCONTROLLER_H
#define DBUSCONTROLLER_H


#include <QObject>
#include "dbusinterface/dbustype.h"

class LauncherInterface;
class LauncherSettingsInterface;
class FileInfoInterface;
class StartManagerInterface;
class MenuController;
class DisplayInterface;
class DBusClientManager;
class PinyinInterface;
class DockInterface;

#define Launcher_service "com.deepin.dde.daemon.Launcher"
#define Launcher_path "/com/deepin/dde/daemon/Launcher"

#define FileInfo_service "com.deepin.filemanager.Backend.FileInfo"
#define FileInfo_path "/com/deepin/filemanager/Backend/FileInfo"

#define StartManager_service "com.deepin.SessionManager"
#define StartManager_path "/com/deepin/StartManager"

#define Pinyin_service "com.deepin.api.Pinyin"
#define Pinyin_path "/com/deepin/api/Pinyin"

#define Dock_service "com.deepin.dde.dock"
#define Dock_path "/com/deepin/dde/dock"

bool appNameLessThan(const ItemInfo &info1, const ItemInfo &info2);
bool installTimeMoreThan(const ItemInfo &info1, const ItemInfo &info2);
bool useFrequencyMoreThan(const ItemInfo &info1, const ItemInfo &info2);

class DBusController : public QObject
{
    Q_OBJECT

public:
    explicit DBusController(QObject *parent = 0);
    ~DBusController();

    static QSet<QString> PreInstallAppKeys;
    void initConnect();

    void getAutoStartList();
    int getSortMethod();
    int getCategoryDisplayMode();
    void convertNameToPinyin();

    LauncherInterface* getLauncherInterface();
    StartManagerInterface* getStartManagerInterface();
    DisplayInterface* getDisplayInterface();
    DockInterface* getDockInterface();
    ItemInfo getItemInfo(QString appKey);
    ItemInfo getLocalItemInfo(QString appKey);

    void sortedByAppName(QList<ItemInfo> infos);
    void sortedByInstallTime(QList<ItemInfo> infos);
    void sortedByFrequency(QList<ItemInfo> infos);
    QList<QList<ItemInfo>> sortPingyinEnglish(QList<ItemInfo> infos);

    void loadPreInstallApps();
    QString getPreInstallAppsPath();
    bool isPreInsallAppsPathExists();

signals:

public slots:
    void init();
    void getCategoryInfoList();
    void refreshUI();
    void getInstalledTimeItems();
    void getAllFrequencyItems();
    void handleItemChanged(const QString &action, ItemInfo itemInfo, qlonglong categoryInfoId);
    void updateAppTable(QString appKey);
    void searchDone(QStringList appKeys);
    void setCategoryDisplayMode(int mode);
    void setSortMethod(int mode);
    void refreshInstallTimeFrequency();
    void filterWindowId(uint wId);
private:
    LauncherInterface* m_launcherInterface;
    LauncherSettingsInterface* m_launcherSettingsInterface;
    FileInfoInterface* m_fileInfoInterface;
    StartManagerInterface* m_startManagerInterface;
    DisplayInterface* m_displayInterface;
    DockInterface* m_dockInterface;
    MenuController* m_menuController;
    AppInstalledTimeInfoList m_appInstalledTimeInfoList;
    AppFrequencyInfoList m_appFrequencyInfoList;
    CategoryInfoList m_categoryInfoList;
    CategoryInfoList m_categoryAppNameSortedInfoList;
    DBusClientManager* m_dockClientManagerInterface;
    PinyinInterface* m_pinyinInterface;

    QMap<QString, ItemInfo> m_itemInfos;
    QMap<QString, QStringList> m_categoryAppNames;

    QStringList m_autoStartList;
    QList<ItemInfo> m_appNameSortedList;
    QList<ItemInfo> m_installTimeSortedList;
    QList<ItemInfo> m_useFrequencySortedList;
    QList<ItemInfo> m_searchList;
    QList<QList<ItemInfo>> m_pinyinEnglishInfos;

    QTimer* m_getAllCategoryInfosTimer;
};

#endif // DBUSCONTROLLER_H
