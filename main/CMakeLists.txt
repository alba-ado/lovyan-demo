idf_component_register( SRC_DIRS "." INCLUDE_DIRS "." )

#Delete the redundant options when warnings are fixed
component_compile_options(-Wno-unknown-pragmas -Wno-missing-field-initializers -std=gnu++2a)