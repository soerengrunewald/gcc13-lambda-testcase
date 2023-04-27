project('sample', ['c', 'cpp'],
  default_options : [
    'cpp_std=c++17',
    'optimization=0',
    'warning_level=3',
  ],
)

lib = shared_library('some', 'somelib.c', soversion: 1)

executable('sample', 'main.cc', link_with : lib)

