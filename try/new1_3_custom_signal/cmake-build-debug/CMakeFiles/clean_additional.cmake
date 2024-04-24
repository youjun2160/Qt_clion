# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\new1_3_custom_signal_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\new1_3_custom_signal_autogen.dir\\ParseCache.txt"
  "new1_3_custom_signal_autogen"
  )
endif()
