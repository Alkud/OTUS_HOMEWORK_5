#CmakeList.txt for OTUS Homework #5

#Check CMake version
cmake_minimum_required(VERSION 3.2)

#Set project name, set PROJECT_VERSION_MINOR value equal to TRAVIS_BUILD NUMBER
if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
  set (VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
else ()
  set (VERSION_PATCH 1)
endif()

project(vector_editor VERSION 0.0.${VERSION_PATCH})

set (BOOST_MIN_VERSION "1.54.0")

#Find Boost UTF component, get BOOST_LIBRARIES and BOOST_INCLUDE_DIR values
find_package(Boost COMPONENTS unit_test_framework REQUIRED)


#Set library target
add_library(document ./library/document.cpp)
add_library(event_processor ./library/event_processor.cpp)
add_library(events ./library/events.cpp)
add_library(gui_elements ./library/gui_elements.cpp)
add_library(shapes ./library/shapes.cpp)


#Set executable target
add_executable(vector_editor vector_editor.cpp)


#Set test target_link_libraries
add_executable(otus_hw_5_test otus_hw_5_test.cpp)

#Enable tests
enable_testing()
add_test(
NAME test_hw_5
COMMAND otus_hw_5_test)

#Set properties and compile options for executable target
set_target_properties(vector_editor
  PROPERTIES CXX_STANDARD 14
             CXX_STANDARD_REQUIRED ON
             COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#Set properties for test target
set_target_properties(otus_hw_5_test PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

#Link
target_link_libraries(vector_editor gui_elements event_processor)
target_link_libraries(event_processor events shapes)
target_link_libraries(events gui_elements)
target_link_libraries(shapes gui_elements)

target_link_libraries(otus_hw_5_test
  ${Boost_LIBRARIES}
  event_processor
)

install(TARGETS vector_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexandr_kudinov@mail.ru)

include(CPack)
