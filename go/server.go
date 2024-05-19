package main

import (
	"sync"
)

type KVStore interface {
	Get(key string) string
	Put(key, value string)
	MultiGet(keys []string) []string
	MultiPut(kvPairs [][2]string)
}

type Server struct {
	store map[string]string
	lock  sync.Mutex
}

func NewServer() *Server {
	return &Server{
		store: make(map[string]string),
	}
}

func (s *Server) Get(key string) string {
	s.lock.Lock()
	defer s.lock.Unlock()
	return s.store[key]
}

func (s *Server) Put(key, value string) {
	s.lock.Lock()
	defer s.lock.Unlock()
	s.store[key] = value
}

func (s *Server) MultiGet(keys []string) []string {
	results := make([]string, len(keys))
	for i, key := range keys {
		results[i] = s.Get(key)
	}
	return results
}

func (s *Server) MultiPut(kvPairs [][2]string) {
	s.lock.Lock()
	defer s.lock.Unlock()
	for _, pair := range kvPairs {
		s.store[pair[0]] = pair[1]
	}
}
