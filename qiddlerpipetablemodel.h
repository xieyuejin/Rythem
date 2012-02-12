#ifndef QIDDLERPIPETABLEMODEL_H
#define QIDDLERPIPETABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QSharedPointer>
#include "rypipedata.h"
class QiddlerPipeTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit QiddlerPipeTableModel(QObject *parent = 0);
    ~QiddlerPipeTableModel();
    QMap<int,RyPipeData_ptr > pipesMap;
    QVector<RyPipeData_ptr > pipesVector;

    int rowCount( const QModelIndex & parent ) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
public slots:
    void addItem(RyPipeData_ptr p);
    void removeItems();
    void removeAllItem();

    RyPipeData_ptr getItem(int column);

    void updateItem(RyPipeData_ptr p);

signals:
	//signals emit when connections are added/updated/removed
    void connectionAdded(RyPipeData_ptr p);
    void connectionUpdated(RyPipeData_ptr p);
    void connectionRemoved(RyPipeData_ptr p);

public slots:

private:
    int pipeNumber;
};

#endif // QIDDLERPIPETABLEMODEL_H
