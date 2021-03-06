include_directories("${PROJECT_SOURCE_DIR}/third_party/includes")
include_directories("${PROJECT_SOURCE_DIR}/util")
include_directories("${PROJECT_SOURCE_DIR}/bson")
include_directories("${PROJECT_SOURCE_DIR}/cache")
include_directories("${PROJECT_SOURCE_DIR}/filesystem")
include_directories("${PROJECT_SOURCE_DIR}/db")
include_directories("${PROJECT_SOURCE_DIR}/tx")
include_directories("${PROJECT_SOURCE_DIR}/command")
include_directories("${PROJECT_SOURCE_DIR}/driverbase")

add_executable(test-driverbase main.cpp)
IF (NOT WIN32)
add_executable(test-performance testperformance.cpp)
ENDIF (NOT WIN32)

IF (LINUX)
	target_link_libraries (test-driverbase djon-client djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}gtest.a ${LIBRARY_PREFIX}gtest_main.a rt uuid)
	target_link_libraries (test-performance djon-client djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}gtest.a ${LIBRARY_PREFIX}gtest_main.a rt uuid)
ENDIF (LINUX)
IF (DARWIN)
	target_link_libraries (test-driverbase djon-client djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}gtest.a ${LIBRARY_PREFIX}gtest_main.a)
	target_link_libraries (test-performance djon-client djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}gtest.a ${LIBRARY_PREFIX}gtest_main.a)
ENDIF (DARWIN)

IF (WIN32)
	target_link_libraries (test-driverbase djon-client djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}gtest${LIBRARY_SUFFIX} ${LIBRARY_PREFIX}gtest_main${LIBRARY_SUFFIX})
ENDIF (WIN32)

IF (NOT WIN32)
	add_custom_command(TARGET test-performance
		POST_BUILD
		COMMAND cp ${PROJECT_SOURCE_DIR}/driverbase/tests/*.csv ${PROJECT_BINARY_DIR}/driverbase/tests/)
ENDIF (NOT WIN32)

IF (WIN32)
	add_custom_command(TARGET test-performance
		POST_BUILD
		COMMAND copy ${PROJECT_SOURCE_DIR}/driverbase/tests/*.csv ${PROJECT_BINARY_DIR}/driverbase/tests/)
ENDIF (WIN32)

add_test(test-driverbase test-driverbase)

