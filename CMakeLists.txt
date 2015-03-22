cmake_minimum_required (VERSION 2.6)
project (ebook)

# version number
set (Ebook_VERSION_MAJOR 0)
set (Ebook_VERSION_MINOR 0)



enable_testing()

add_executable(Ebook src/ebook.cpp)
add_test(BookTest book)
