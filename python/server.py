from threading import Lock

class KVStore:
    def get(self, key):
        raise NotImplementedError
    
    def put(self, key, value):
        raise NotImplementedError
    
    def multi_get(self, keys):
        return [self.get(key) for key in keys]
    
    def multi_put(self, kv_pairs):
        for key, value in kv_pairs:
            self.put(key, value)

class Server(KVStore):
    def __init__(self):
        self.store = {}
        self.lock = Lock()

    def get(self, key):
        with self.lock:
            return self.store.get(key, None)

    def put(self, key, value):
        with self.lock:
            self.store[key] = value
