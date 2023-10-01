# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Liker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Liker_autogen.dir\\ParseCache.txt"
  "Liker_autogen"
  )
endif()
