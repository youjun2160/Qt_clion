# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\new1_4_five_major_components_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\new1_4_five_major_components_autogen.dir\\ParseCache.txt"
  "new1_4_five_major_components_autogen"
  )
endif()
