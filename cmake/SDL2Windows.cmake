if(NOT MSVC)
	link_directories(${SDL2_LIB_DIR})
endif()

file(GLOB PROJECT_DEPS ${SDL2_LIBRARIES}/*.dll)

foreach(dep IN LISTS PROJECT_DEPS)
	file(COPY ${dep} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()
