use crate::server::KVStore;

mod server;

fn main() {
    let server = server::Server::new();

    // Challenge 1: Make it possible for these to run concurrently
    server.put("key1", "value1");
    server.put("key2", "value2");

    println!("key1 {}", server.get("key1").unwrap());
    println!("key2 {}", server.get("key2").unwrap());

    // Challenge 2: make this atomic!
    server.multi_put(vec![("key3", "value3"), ("key4", "value4")]);

    println!("key3 {}", server.get("key3").unwrap());
    println!("key4 {}", server.get("key4").unwrap());
}
