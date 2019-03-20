# Prepends a prefix to all the paths passed in as arguments
function(prepend outVar prefix)
    set(listVar "")

    foreach(file ${ARGN})
        list(APPEND listVar "${prefix}/${file}")
    endforeach()

    set(${outVar} "${listVar}" PARENT_SCOPE)
endfunction()

find_program(
    CLANG_FORMAT
    NAMES "clang-format"
    DOC "Path to clang-format executable"
)

function(add_clang_format_target srcs)
    if(CLANG_FORMAT)
        prepend(FMT_FILES "${CMAKE_CURRENT_SOURCE_DIR}" ${srcs})

        add_custom_target(
            clang-format
            COMMAND "${CLANG_FORMAT}" "-i" "-style=file" ${FMT_FILES}
        )
    else()
        message(WARN "clang-format not found")
    endif()
endfunction()
