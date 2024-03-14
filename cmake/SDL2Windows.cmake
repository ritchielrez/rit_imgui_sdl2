if(NOT MSVC)
	set(SDL2_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-Windows-MinGW/lib")
	set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-Windows-MinGW/include")
	set(SDL2_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-Windows-MinGW/bin")
	include_directories(${SDL2_INCLUDE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-Windows-MinGW/include/SDL2")
	link_directories(${SDL2_LIB_DIR})
endif()

file(GLOB PROJECT_DEPS ${SDL2_LIBRARIES}/*.dll)

foreach(dep IN LISTS PROJECT_DEPS)
	file(COPY ${dep} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()