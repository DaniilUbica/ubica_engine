#pragma once

#include <sqlite3.h>

#include <memory>
#include <map>

#include "DataBaseRequestData.h"
#include "sqlite3_pointer.h"

namespace game_engine {
namespace database {

class DataBaseManager {
public:
    ~DataBaseManager();

    static std::shared_ptr<DataBaseManager> instance();

    bool openDatabase(const std::string& dbName);
    bool createRelation(const DBCreateRelationData& data);

    template<SQLiteCompatible FieldType>
    bool insertValue(const DBInsertData<FieldType>& data);

    template<SQLiteCompatible FieldType>
    FieldType getValue(const DBSingleSelectData& data);

    std::map<std::string, std::string> getValues(const DBMultiSelectData& data);

private:
    DataBaseManager();
    DataBaseManager(const DataBaseManager&) = delete;
    void operator=(const DataBaseManager&) = delete;

    inline static std::weak_ptr<DataBaseManager> m_instance;

    sqlite3_pointer<sqlite3> m_db;
};

}
}
