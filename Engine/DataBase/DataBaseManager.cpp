#include "DataBaseManager.h"

#include <sstream>

using namespace game_engine::database;

DataBaseManager::DataBaseManager() {}

DataBaseManager::~DataBaseManager() {}

bool DataBaseManager::openDatabase(const std::string& dbName) {
    const auto rc = sqlite3_open(dbName.c_str(), std::out_ptr(m_db));
    if (rc) {
        return false;
    }

    DBRequestData::databaseName = dbName;

    return true;
}

bool DataBaseManager::createRelation(const DBCreateRelationData& data) {
    if (!m_db || data.databaseName.empty()) {
        return false;
    }

    std::stringstream sql_request;
    sql_request << "CREATE TABLE IF NOT EXISTS " << data.relationName << " (";

    bool firstAttribute = true;
    for (const auto& [attributeName, attributeType] : data.attributes) {
        if (!firstAttribute) {
            sql_request << ", ";
        }

        sql_request << attributeName << " " << attributeType;
        firstAttribute = false;
    }

    sql_request << ");";

    int rc = sqlite3_exec(m_db.get(), sql_request.str().c_str(), nullptr, nullptr, nullptr);

    if (rc != SQLITE_OK) {
        return false;
    }

    DBRequestData::relationName = data.relationName;

    return true;
}

std::map<std::string, std::string> DataBaseManager::getValues(const DBMultiSelectData& data) {}
