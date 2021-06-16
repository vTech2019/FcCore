
cmake_minimum_required(VERSION 3.0)

project(FcCore)

file(GLOB_RECURSE FcCoreFiles "src/*")

set(Source

    src/FcCore.h
    src/FcCore.c
)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/BINARY")
file(GLOB_RECURSE SHADER_OPENGL_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.vs" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.fs" HEX)

foreach (shader ${SHADER_OPENGL_FILE})
    file(READ ${shader} HEX_SHADER_OPENGL_FILE  HEX)
    string(REGEX MATCHALL "([A-Za-z0-9][A-Za-z0-9])" SEPARATED_HEX_SHADER_OPENGL_FILE "${HEX_SHADER_OPENGL_FILE}")
    list(JOIN SEPARATED_HEX_SHADER_OPENGL_FILE ", 0x" FORMATTED_HEX)
    message("HEX_CONTENTS: ${SEPARATED_HEX_SHADER_OPENGL_FILE}")
    string(PREPEND FORMATTED_HEX "0x")
    get_filename_component (name ${shader} NAME)
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/src/BINARY/${name}.bin "${FORMATTED_HEX}")
    message("HEX_CONTENTS: ${FORMATTED_HEX}")
endforeach()

file(GLOB_RECURSE RES_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.vs.bin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.vs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.fs.bin
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.fs
        )
        
add_library(${PROJECT_NAME} ${Source} ${FcCoreFiles})

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} X11 "libpthread.so")

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

