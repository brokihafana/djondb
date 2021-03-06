include_directories("${PROJECT_SOURCE_DIR}/util")
include_directories("${PROJECT_SOURCE_DIR}/bson")
include_directories("${PROJECT_SOURCE_DIR}/cache")
include_directories("${PROJECT_SOURCE_DIR}/filesystem")
include_directories("${PROJECT_SOURCE_DIR}/db")
include_directories("${PROJECT_SOURCE_DIR}/tx")
include_directories("${PROJECT_SOURCE_DIR}/command")
include_directories("${PROJECT_SOURCE_DIR}/network")

add_library(djon-clientStatic STATIC djondbconnection.cpp djondbconnectionmanager.cpp dqlParser.cpp dqlLexer.cpp)
add_library(djon-client SHARED djondbconnection.cpp djondbconnectionmanager.cpp dqlParser.cpp dqlLexer.cpp)
IF (NOT WIN32)
	install (TARGETS djon-client 
		DESTINATION /usr/lib
		PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
	install (FILES djondb_client.h 
   	DESTINATION /usr/include)
ENDIF (NOT WIN32)

IF (WIN32)
	add_definitions(/clr )	
	#	set( refs "System.dll" )
	STRING(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
	STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})

	include_directories("${PROJECT_SOURCE_DIR}/third_party/includes")

	install (TARGETS djon-client 
		DESTINATION lib
		PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
	install (FILES djondb_client.h DESTINATION include)
ENDIF (WIN32)

IF (LINUX)
	target_link_libraries (djon-client djon-network djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}antlr3c.a pthread ${LIBRARY_PREFIX}v8_base.a ${LIBRARY_PREFIX}v8_snapshot.a uuid rt)
ENDIF (LINUX)
IF (WIN32)
	target_link_libraries (djon-client djon-network djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}/antlr3c.lib ${LIBRARY_PREFIX}/pthreadVC2.lib ${LIBRARY_PREFIX}/v8.lib ${LIBRARY_PREFIX}/v8_base.lib ${LIBRARY_PREFIX}/v8_snapshot.lib)
ENDIF (WIN32)
IF (DARWIN)
	target_link_libraries (djon-client djon-network djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util ${LIBRARY_PREFIX}antlr3c.a pthread ${LIBRARY_PREFIX}v8_base.a ${LIBRARY_PREFIX}v8_snapshot.a)
	#target_link_libraries (djon-client djon-network djon-command djon-tx djon-db djon-filesystem djon-cache djon-bson djon-util antlr3c pthread ${LIBRARY_PREFIX}v8_base.a ${LIBRARY_PREFIX}v8_snapshot.a)
ENDIF (DARWIN)
