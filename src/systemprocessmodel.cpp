#include <QSet>
#include "systemprocessmodel.h"



void SystemProcessModel::setRawData(const QSet<int>& all)
{
    beginResetModel();
    all_=all;
    endResetModel();
}
