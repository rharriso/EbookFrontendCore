cmake_minimum_required (VERSION 3.0)
project (ebook)
include(ExternalProject)

# set the executable
add_executable(ebook src/ebook.cpp)

# version number
set (Ebook_VERSION_MAJOR 0)
set (Ebook_VERSION_MINOR 0)

set (LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/../lib)

# C++ version
add_definitions(-std=c++11)

# system libraries
# sqlite
find_library(SQLITE3_LIB sqlite3)
if(NOT SQLITE3_LIB)
  message(SEND_ERROR "Failed to find the sqlite3 library, need to install to you system.")
endif()
# pthreads
find_library(PTHREAD_LIB pthread)
if(NOT SQLITE3_LIB)
  message(SEND_ERROR "Failed to find the pthread library, need to install to you system.")
endif()
# dl
find_library(DL_LIB dl)
if(NOT DL_LIB)
  message(SEND_ERROR "Failed to find the dl library, need to install to you system.")
endif()

# add hiberlit
ExternalProject_Add(hiberlite
  SOURCE_DIR ${LIB_DIR}/hiberlite
  GIT_REPOSITORY git@github.com:paulftw/hiberlite.git
  CONFIGURE_COMMAND ""
  BUILD_IN_SOURCE 1
  BUILD_COMMAND make libhiberlite.a
  INSTALL_COMMAND ""
  )
add_dependencies(ebook hiberlite)
include_directories(${LIB_DIR}/hiberlite/include/)

# link packages
target_link_libraries(ebook 
  ${LIB_DIR}/hiberlite/libhiberlite.a
  ${SQLITE3_LIBRARY}
  ${DL_LIB}
  ${PTHREAD_LIB})

add_test(BookTest book)
