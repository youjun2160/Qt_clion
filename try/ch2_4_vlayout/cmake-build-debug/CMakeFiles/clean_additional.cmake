# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ch2_4_vlayout_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ch2_4_vlayout_autogen.dir\\ParseCache.txt"
  "ch2_4_vlayout_autogen"
  )
endif()
