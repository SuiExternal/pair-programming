use std::collections::HashMap;
use std::sync::Mutex;

pub trait KVStore {
    fn get(&self, key: &str) -> Option<String>;
    fn put(&self, key: &str, value: &str);

    fn multi_get(&self, keys: Vec<&str>) -> Vec<Option<String>> {
        keys.into_iter().map(|key| self.get(key)).collect()
    }

    fn multi_put(&self, kv_pairs: Vec<(&str, &str)>) {
        kv_pairs
            .into_iter()
            .for_each(|(key, value)| self.put(key, value));
    }
}

pub struct Server {
    store: Mutex<HashMap<String, String>>,
}

impl Server {
    pub fn new() -> Self {
        Server {
            store: Default::default(),
        }
    }
}

impl KVStore for Server {
    fn get(&self, key: &str) -> Option<String> {
        self.store.lock().unwrap().get(key).cloned()
    }

    fn put(&self, key: &str, value: &str) {
        self.store
            .lock()
            .unwrap()
            .insert(key.to_string(), value.to_string());
    }
}
