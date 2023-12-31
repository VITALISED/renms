set(RENMS_COMMON_HEADERS logging/logger.h memory/hook.h memory/memory.h
                         memory/vtable.h thread/thread.h
)
set(RENMS_COMMON_SOURCES logging/logger.cpp memory/memory.cpp platform/wine.cpp
                         thread/thread.cpp
)

add_library(renms_common ${RENMS_COMMON_HEADERS} ${RENMS_COMMON_SOURCES})
