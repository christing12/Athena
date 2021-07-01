

# static library + project name for visual studio
set(LIB_NAME AthenaEngine)

project(${LIB_NAME} LANGUAGES CXX)


# var for compiling with pch files later on


set(CORE_INC
    Timer.h
    CoreIncludes.h
)
list(TRANSFORM CORE_INC PREPEND "Core/")
source_group("Core" FILES ${CORE_INC})

set (ALL_SRC_NO_PCH

)

set(BASE_INC
    AthenaAPI.h
    pch.h
)
source_group(" " FILES ${BASE_INC} pch.cpp)


set(ALL_HEADER_FILES
    ${BASE_INC}
    ${CORE_INC}
)

set(ALL_SRC_FILES
    ${ALL_SRC_NO_PCH}
    pch.cpp
)

# --------------- COMPILING PROJECT IN A LIBRARY --------------------- #
add_library(${LIB_NAME} STATIC ${ALL_HEADER_FILES} ${ALL_SRC_FILES})


# ---------------- SETTING UP PRECOMPILED HEADER FILES + FLAGS FOR COMPILATION ----#
# use pch with /Yu flag
set_source_files_properties(${ALL_SRC_NO_PCH}
    PROPERTIES 
        COMPILE_FLAGS /Yu"pch.h"
)

# create pch with /Yc flag
set_source_files_properties(pch.cpp
    PROPERTIES
        COMPILE_FLAGS /Yc"pch.h"
)
