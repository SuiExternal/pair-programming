#include <unordered_map>
#include <string>
#include <vector>
#include <optional>
#include <mutex>

class KVStore {
public:
    virtual std::optional<std::string> get(const std::string& key) const = 0;
    virtual void put(const std::string& key, const std::string& value) = 0;

    std::vector<std::optional<std::string>> multi_get(const std::vector<std::string>& keys) const {
        std::vector<std::optional<std::string>> results;
        for (const auto& key : keys) {
            results.push_back(get(key));
        }
        return results;
    }

    void multi_put(const std::vector<std::pair<std::string, std::string>>& kv_pairs) {
        for (const auto& [key, value] : kv_pairs) {
            put(key, value);
        }
    }
};

class Server : public KVStore {
    mutable std::mutex store_mutex;
    std::unordered_map<std::string, std::string> store;

public:
    Server() = default;

    std::optional<std::string> get(const std::string& key) const override {
        std::lock_guard<std::mutex> lock(store_mutex);
        auto it = store.find(key);
        if (it != store.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    void put(const std::string& key, const std::string& value) override {
        std::lock_guard<std::mutex> lock(store_mutex);
        store[key] = value;
    }
};
