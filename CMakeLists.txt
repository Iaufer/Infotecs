cmake_minimum_required(VERSION 3.10)
project(SQLite)

set(SQLITE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sqlite-amalgamation-3260000")

set(SQLITE_SOURCES
    ${SQLITE_SOURCE_DIR}/shell.c
    ${SQLITE_SOURCE_DIR}/sqlite3.c
)

add_library(SQLite SHARED ${SQLITE_SOURCES})

if(WIN32)
    set_target_properties(SQLite PROPERTIES OUTPUT_NAME sqlite3)
endif()

if(UNIX)
    set_target_properties(SQLite PROPERTIES OUTPUT_NAME sqlite3)
endif()

add_executable(MySQLiteApp main.cpp)

target_link_libraries(MySQLiteApp PRIVATE SQLite)

if(WIN32)
    target_compile_options(SQLite PRIVATE /W3)
    target_compile_definitions(SQLite PRIVATE SQLITE_API=__declspec(dllexport))
endif()

if(UNIX AND NOT APPLE)
    target_compile_options(SQLite PRIVATE -Wall)
    target_compile_definitions(SQLite PRIVATE SQLITE_API=)
endif()

target_include_directories(MySQLiteApp PRIVATE ${SQLITE_SOURCE_DIR})