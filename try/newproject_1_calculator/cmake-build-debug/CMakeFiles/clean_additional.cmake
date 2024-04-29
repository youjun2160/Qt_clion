# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\newproject_1_calculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\newproject_1_calculator_autogen.dir\\ParseCache.txt"
  "newproject_1_calculator_autogen"
  )
endif()
