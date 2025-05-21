project(cap_table)

find_package(cdt)

add_subdirectory(table)
add_contract(cap.table cap_table cap_table.cpp ${CAP_TABLE_SOURCES})
target_include_directories( cap_table PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( cap_table ${CMAKE_SOURCE_DIR}/../ricardian )
