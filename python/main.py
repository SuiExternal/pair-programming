#!/usr/bin/env python3

from server import Server

def main():
    server = Server()

    # Challenge 1: Make it possible for these to run concurrently
    server.put("key1", "value1")
    server.put("key2", "value2")

    print(f"key1 {server.get('key1')}")
    print(f"key2 {server.get('key2')}")

    # Challenge 2: Make this atomic
    server.multi_put([("key3", "value3"), ("key4", "value4")])

    print(f"key3 {server.get('key3')}")
    print(f"key4 {server.get('key4')}")

if __name__ == "__main__":
    main()
