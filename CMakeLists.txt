enable_testing()
find_package(GTest REQUIRED) # Find the google testing framework on your system
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES}) # Replace ${PROJECT_NAME} with your target name