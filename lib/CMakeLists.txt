message("-- Linking mega2lib")

add_library(libmega2lib libmega2lib.dll)
set_target_properties(libmega2lib PROPERTIES LINKER_LANGUAGE C)
