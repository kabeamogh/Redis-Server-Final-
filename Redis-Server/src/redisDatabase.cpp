#include "../include/redisDatabase.h"
#include <unordered_map>
#include <string>
#include <vector>

RedisDatabase& RedisDatabase::getInstance(){
    static RedisDatabase instance;
    return instance;
}

void RedisDatabase::flushall(){
    kv_store.clear();
    list_store.clear();
    hash_store.clear();  
}

void RedisDatabase::SET (const std::string& key, const std::string& value){
    std::lock_guard<std::mutex> lock(db_lock);
    kv_store[key] = value;
}

bool RedisDatabase::GET (const std::string& key, std::string& value){
    std::lock_guard<std::mutex> lock(db_lock);
    // Lass uns die key finden ob die key existiert oder nicht.
    auto it = kv_store.find(key);

    if (it != kv_store.end()){ // dass bedeutet, haben wir die key gefunden.
        value = it -> second;
        return true;
    } else {
        return false;
    }
}

