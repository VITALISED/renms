
##      Rename this to "config.cmake" and it'll work

## Just making the options easier to read, and so you can do -DVAR=VAL on the command line if you really want to.
function(SetIfNotDef var val)
    if (NOT DEFINED ${var})
        set(${var} ${val} PARENT_SCOPE)
    endif()
endfunction()


SetIfNotDef(CMAKE_BUILD_TYPE Release)
SetIfNotDef(SKIP_NMS_CHECK FALSE)
SetIfNotDef(NMS_EXE_DIR "C:/Your/Path/To/NMS/Exe/Dir/Here")
SetIfNotDef(FETCHCONTENT_QUIET OFF)