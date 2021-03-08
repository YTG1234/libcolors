set (source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

enable_testing ()

include_directories ("${PROJECT_SOURCE_DIR}/include")

SET (COLORTESTS black_fg_dark;cyan_bg_bright;cyan_fg_bright_underline_overline)

foreach (T ${COLORTESTS})
    message(NOTICE "Adding ${T}")
    add_executable (${T} "${source_dir}/${T}.cpp")
    target_link_libraries (${T} ${LIB_NAME})
    add_test (${T} ${T})
    set_property (TARGET ${T} PROPERTY CXX_STANDARD 17)
endforeach()
