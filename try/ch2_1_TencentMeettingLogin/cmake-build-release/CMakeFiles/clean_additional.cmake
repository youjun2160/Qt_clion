# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\ch2_1_TencentMeettingLogin_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ch2_1_TencentMeettingLogin_autogen.dir\\ParseCache.txt"
  "ch2_1_TencentMeettingLogin_autogen"
  )
endif()
