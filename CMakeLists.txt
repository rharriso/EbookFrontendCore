cmake_minimum_required (VERSION 3.0)
project (ebook)
include(ExternalProject)

# set the executable
add_executable(ebook src/ebook.cpp)

# version number
set (Ebook_VERSION_MAJOR 0)
set (Ebook_VERSION_MINOR 0)

# C++ version
add_definitions(-std=c++11)

# sqlite
find_path(SQLITE3_INCLUDE_DIR sqlite3.h)
find_library(SQLITE3_LIBRARY sqlite3)
if(NOT SQLITE3_INCLUDE_DIR)
  message(SEND_ERROR "Failed to find sqlite3.h. make sure the dev package is installed.")
endif()
if(NOT SQLITE3_LIBRARY)
  message(SEND_ERROR "Failed to find the sqlite3 library")
endif()


# link packages
target_link_libraries(ebook
  ${SQLITE3_LIBRARY}
  )

enable_testing()
add_test(BookTest book)
