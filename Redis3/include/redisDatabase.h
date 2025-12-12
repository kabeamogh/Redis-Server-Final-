// Wir schaffen verschiedene fuctionen zum beispiel SET GET HSET HGET LPUSH LPOP DEL flushall
// was brauchen wir? eine kenntnisse auf hashmaps in general.
// Wir schliessen unordered_map vector ein
#ifndef redisdatabase_h
#define redisdatabase_h


#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>

class RedisDatabase{
    public: // Alle sind Public variables.
    // Zuerst schaffen wir die singleton function.
    static RedisDatabase& getInstance();

    // Hier kommt die flushall function.
    void flushall();

    // Die SET function gibt nix.
    // Es nehmt eine key (string) und eine value (string) als es eine hashmap is.
    void SET (const std::string& key, const std::string& value);

    // Die GET gibt uns die value wann wir die key fragen. Das gibt uns eine string zuruck.

    bool GET (const std::string& key, std::string& value);

    


    private:
    RedisDatabase() {}

    std::mutex db_lock;

    // Hier definieren wir kv_store, unsere list_store und unsere komplexiet daten store.

    std::unordered_map<std::string, std::string> kv_store;
    std::unordered_map<std::string, std::vector<std::string>> list_store;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> hash_store;



};
#endif