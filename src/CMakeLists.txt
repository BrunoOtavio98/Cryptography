file(GLOB_RECURSE ALL_FILES "${TOP_LEVEL_PATH}/*.cpp")

add_executable(${PROJECT_NAME} ${ALL_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${TOP_LEVEL_PATH}/CommonCode)