#pragma once

#include <map>
#include <type_traits>
#include <concepts>

namespace game_engine {
namespace database {

template<typename T>
concept SQLiteCompatible = std::is_same_v<T, int> ||
                          std::is_same_v<T, double> ||
                          std::is_same_v<T, std::string> ||
                          std::is_same_v<T, const char*> ||
                          std::is_same_v<T, std::nullptr_t> ||
                          std::is_same_v<T, long> ||
                          std::is_same_v<T, long long> ||
                          std::is_same_v<T, float>;

enum class DBRequestType {
    NONE = -1,
    CREATE_RELATION = 0,
    INSERT,
    INSERT_OR_REPLACE,
    SELECT
};

struct DBRequestData {
    inline static std::string databaseName = "";
    inline static std::string relationName = "";
    DBRequestType type = DBRequestType::NONE;

    virtual ~DBRequestData() {};
};

struct DBCreateRelationData : DBRequestData {
    std::map<std::string, std::string> attributes;
};

template<SQLiteCompatible FieldType>
struct DBInsertData : DBRequestData {
    std::string fieldName;
    FieldType value;
};

struct DBSingleSelectData : DBRequestData {
    std::string fieldToSelect;
    std::string whereClause = "";
};

struct DBMultiSelectData : DBRequestData {
    std::vector<std::string> fieldsToSelect;
    std::string whereClause = "";
    bool selectAll = false;
};

}
}
