cmake_minimum_required(VERSION 3.6)

set(PROJECTNAME "tests")
project(${PROJECTNAME} C CXX)

# Используем C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# qt
find_package(Qt4 COMPONENTS QtCore REQUIRED)
include(${QT_USE_FILE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(${PROJECTNAME}
    main.cpp
    calc.cpp
)

target_link_libraries(${PROJECTNAME} ${QT_LIBRARIES})

# google tests
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# --------- Нет ---------
set(LOG_FILE messages.log)
find_program(GCOVR_EXECUTABLE gcovr)

add_custom_target(coverage COMMAND ${GCOVR_EXECUTABLE} --root=${CMAKE_SOURCE_DIR}
                  --object-directory=${CMAKE_BINARY_DIR} > ${CMAKE_SOURCE_DIR}/${LOG_FILE})

add_executable(TestSerialization
               testserialization.cpp
               ${LOG_FILE})

target_compile_options(TestSerialization PRIVATE -g -O0 --coverage)
# The --coverage option is a synonym for -lgcov when linking for gcc.
# For clang, it links in a different library, libclang_rt.profile, which
# requires clang to be built with compiler-rt.

target_link_libraries(
 TestSerialization PRIVATE --coverage
 ${GTEST_LIBRARIES}
 Threads::Threads
 ${QT_LIBRARIES}
)
# -----------------------

# --------- Нет ---------
#find_program(GCOVR_EXECUTABLE gcovr)
#set(LOG_FILE messages.log)
#add_custom_target(TRG COMMAND ${GCOVR_EXECUTABLE} --root=${CMAKE_SOURCE_DIR}
#                  --object-directory=${CMAKE_BINARY_DIR} > ${LOG_FILE}
#                  ALL DEPENDS)


#add_executable(TestSerialization
#  testserialization.cpp
#  ${LOG_FILE}
#  ${TRG}
#)

#target_compile_options(TestSerialization PRIVATE --coverage)

#target_link_libraries(
#  TestSerialization
#  PRIVATE gcov
#  ${GTEST_LIBRARIES}
#  Threads::Threads
#  ${QT_LIBRARIES})
# --------------------

# ----- А это не работает -----
#enable_testing()
#add_test(NAME Test COMMAND TestSerialization)

#find_program(GCOVR_EXECUTABLE gcovr)
#if(MYLIB_COVERAGE AND GCOVR_EXECUTABLE)
#    message(STATUS "Измерение покрытия кода тестами включено")

#    target_compile_options(TestSerialization PRIVATE --coverage)
#    target_link_libraries(TestSerialization PRIVATE gcov)

#    add_custom_target(coverage
#        COMMAND
#            ${GCOVR_EXECUTABLE}
#                --root=${PROJECT_SOURCE_DIR}/include/
#                --object-directory=${CMAKE_CURRENT_BINARY_DIR}
#        DEPENDS
#            check
#    )
#elseif(MYLIB_COVERAGE AND NOT GCOVR_EXECUTABLE)
#    set(MYLIB_COVERAGE OFF)
#    message("Для замеров покрытия кода тестами требуется программа gcovr")
#endif()
# -----------------------------
