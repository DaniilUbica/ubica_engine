#pragma once

#include <sqlite3.h>

#include <map>
#include <optional>

#include "DataBaseRequestData.h"

#include "sqlite3_pointer.h"
#include "sqlite3_helpers.h"

namespace game_engine {
namespace database {

class DataBaseManager {
public:
    DataBaseManager();
    ~DataBaseManager();

    [[nodiscard]] bool openDatabase(const std::string& dbName);
    [[nodiscard]] bool createRelation(const DBCreateRelationData& data);

    template<SQLiteCompatible FieldType>
    [[nodiscard]] bool insertValue(const DBInsertData<FieldType>& data);

    template<SQLiteCompatible FieldType>
    [[nodiscard]] std::optional<FieldType> getValue(const DBSingleSelectData& data);

    [[nodiscard]] std::map<std::string, std::string> getValues(const DBMultiSelectData& data);

private:
    sqlite3_pointer<sqlite3> m_db;
};

template<SQLiteCompatible FieldType>
[[nodiscard]] bool DataBaseManager::insertValue(const DBInsertData<FieldType>& data) {
    if (data.relationName.empty() || data.databaseName.empty()) {
        return false;
    }

    std::string sql_request = "INSERT OR REPLACE INTO " + data.relationName + " (" + data.fieldName + ") VALUES (?);";
    sqlite3_pointer<sqlite3_stmt> stmt;
    const auto rc = sqlite3_prepare_v2(m_db.get(), sql_request.c_str(), -1, std::out_ptr(stmt), nullptr);
    if (rc != SQLITE_OK) {
        return false;
    }

    bindValue(stmt.get(), 1, data.value);

    return sqlite3_step(stmt.get()) == SQLITE_DONE;
}

template<SQLiteCompatible FieldType>
[[nodiscard]] std::optional<FieldType> DataBaseManager::getValue(const DBSingleSelectData& data) {
    std::optional<FieldType> result = std::nullopt;
    if (std::is_same_v<FieldType, std::nullptr_t> || data.databaseName.empty() || data.relationName.empty()) {
        return result;
    }

    std::string sql_request = "SELECT " + data.fieldToSelect + " FROM " + data.relationName;
    if (!data.whereClause.empty()) {
        sql_request += " WHERE " + data.whereClause;
    }
    sql_request += " LIMIT 1;";

    sqlite3_pointer<sqlite3_stmt> stmt;
    const auto rc = sqlite3_prepare_v2(m_db.get(), sql_request.c_str(), -1, std::out_ptr(stmt), nullptr);

    if (rc != SQLITE_OK) {
        return result;
    }

    if (sqlite3_step(stmt.get()) == SQLITE_ROW) {
        result = extractValue<FieldType>(stmt.get(), 0);
    }

    return result;
}

}
}
