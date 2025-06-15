file(GLOB_RECURSE ALL_FILES "${TOP_LEVEL_PATH}/*.cpp")

add_executable(${PROJECT_NAME} ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} cryptopp::cryptopp)

target_include_directories(${PROJECT_NAME} PUBLIC 
${TOP_LEVEL_PATH}/CommonCode
${LIB_LEVEL_PATH}/cryptopp
)
