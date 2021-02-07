#!/bin/python

def Settings( **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-I.', '-I../godot-cpp/godot_headers', '-I../godot-cpp/include' ,'-I../godot-cpp/include/core', '-I../godot-cpp/include/gen', '-I../src'],
  }
