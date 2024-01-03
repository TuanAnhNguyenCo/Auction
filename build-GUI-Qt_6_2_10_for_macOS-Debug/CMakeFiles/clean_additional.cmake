# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/auction_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/auction_autogen.dir/ParseCache.txt"
  "auction_autogen"
  )
endif()
