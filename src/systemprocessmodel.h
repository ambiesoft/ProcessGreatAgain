#ifndef SYSTEMPROCESSMODEL_H
#define SYSTEMPROCESSMODEL_H

#include <QAbstractItemModel>
#include <QSet>

class SystemProcessModel : public QAbstractItemModel
{
    Q_OBJECT
    using P = QAbstractItemModel;
    QSet<int> all_;
public:
    SystemProcessModel() : QAbstractItemModel(nullptr){}

    Q_INVOKABLE virtual QModelIndex index(int row, int column,
                                          const QModelIndex &parent = QModelIndex()) const {
        return createIndex(row,column);
    }

    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex &child) const {
        return QModelIndex();
    }

    Q_INVOKABLE virtual QModelIndex sibling(int row, int column, const QModelIndex &idx) const{
        return P::sibling(row,column,idx);
    }
    Q_INVOKABLE virtual int rowCount(const QModelIndex &parent = QModelIndex()) const {
        return all_.count();
    }
    Q_INVOKABLE virtual int columnCount(const QModelIndex &parent = QModelIndex()) const {
        return 1;
    }
    Q_INVOKABLE virtual bool hasChildren(const QModelIndex &parent = QModelIndex()) {
        return false;
    }

    Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const {
        switch(role)
        {
        case Qt::DisplayRole:
            return QString::number(index.row());
        }
        return QVariant();
    }


    void setRawData(const QSet<int>& all);
};

#endif // SYSTEMPROCESSMODEL_H
