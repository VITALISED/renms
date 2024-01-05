set(PKGNAME MONO)
include(FindPkgConfig)
pkg_search_module(${PKGNAME} REQUIRED ${PKGNAME})
mark_as_advanced(${PKGNAME}_FOUND ${PKGNAME}_CFLAGS ${PKGNAME}_STATIC_LDFLAGS)
find_package_handle_standard_args(
    ${PKGNAME} ${PKGNAME}_FOUND ${PKGNAME}_CFLAGS ${PKGNAME}_STATIC_LDFLAGS
)
target_compile_options(${PROJECT_NAME} PRIVATE ${${PKGNAME}_CFLAGS})
target_link_options(${PROJECT_NAME} PRIVATE ${${PKGNAME}_STATIC_LDFLAGS})
