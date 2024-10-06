#pragma once

#include <vector>
#include <qstringlist.h>

#include "producttestdata.h"


class ProductTestDataIndex {
private:

    class TypeIdGenerator
    {
    private:
        static int count;
    public:
        template<class T>
        static int GetTypeId()
        {
            static const int idCounter = count++;
            return idCounter;
        }
    };

    static QMap<QString,const ProductTestData*> testData;
    static bool isInitialized;

    static class ProductTestDataBuilder *  RegisterNewProductTestData(const QString& name);
public:

    static const std::vector<QString> Names();
    static const std::vector<const ProductTestData*> TestData();    
    static const ProductTestData * GetProductTestData(const QString& name);

    template <class T>
    static int GetTypeId() { return TypeIdGenerator::GetTypeId<T>(); }

    static QMultiMap<int, const ProductTestData*> WhereExpects(const std::unordered_set<int> &typeIds);

    static void Initialize();
};
