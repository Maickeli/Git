ADD_LIBRARY (libmi
		libmi/string.h
		libmi/stdint.h
		libmi/string/memcmp.cpp
	)

target_include_directories(libmi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libmi")