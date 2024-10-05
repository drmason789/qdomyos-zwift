#pragma once

#include <vector>
#include <qstringlist.h>

#include "producttestdatabuilder.h"


class ProductTestDataIndex {
private:
    static QMap<QString,const ProductTestData*> testData;
    static bool isInitialized;      
public:
    static const std::vector<QString> Names();
    static const std::vector<const ProductTestData*> TestData();
    static ProductTestDataBuilder *  RegisterNewProductTestData(const QString& name);
    static const ProductTestData * GetProductTestData(const QString& name);

    static void Initialize();
};
