
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(demo main.cpp)

install(TARGETS demo DESTINATION bin)