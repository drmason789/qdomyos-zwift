#pragma once

#include <vector>
#include <qstringlist.h>

#include "producttestdata.h"
#include "typeidgenerator.h"

class ProductTestDataIndex {
private:
    static QMap<QString,const ProductTestData*> testData;
    static bool isInitialized;

    static class ProductTestDataBuilder *  RegisterNewProductTestData(const QString& name);
public:

    static const std::vector<QString> Names();
    static const std::vector<const ProductTestData*> TestData();    
    static const ProductTestData * GetProductTestData(const QString& name);

    template <class T>
    static DeviceTypeId GetTypeId() { return TypeIdGenerator::GetTypeId<T>(); }

    static QMultiMap<DeviceTypeId, const ProductTestData*> WhereExpects(const std::unordered_set<DeviceTypeId> &typeIds);

    static void Initialize();
};
