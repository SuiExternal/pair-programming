package main

import (
	"fmt"
)

func main() {
	server := NewServer()

	// Challenge 1: Make it possible for these to run concurrently
	server.Put("key1", "value1")
	server.Put("key2", "value2")

	fmt.Printf("key1 %s\n", server.Get("key1"))
	fmt.Printf("key2 %s\n", server.Get("key2"))

	// Challenge 2: make this atomic!
	server.MultiPut([][2]string{{"key3", "value3"}, {"key4", "value4"}})

	fmt.Printf("key3 %s\n", server.Get("key3"))
	fmt.Printf("key4 %s\n", server.Get("key4"))
}
