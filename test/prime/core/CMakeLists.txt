set(DTY_NATIVE_TEST_PRIME_CORE_NAME ${DTY_NATIVE_TEST_PRIME_NAME}.core)

message("            构建: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME})

# 构建测试 - dty.common.native.test.prime.core.event
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.event)
add_executable(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.event
    
    event.cpp
    
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/event.cpp
)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.event 

    ${DTY_NATIVE_TEST_NAME}.core
)

# 构建测试 - dty.common.native.test.prime.core.iterator
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.iterator)
add_executable(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.iterator
    
    iterator.cpp
    src/filter_result.cpp
    src/iterator_entity.cpp
    src/iterator_object.cpp
)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.iterator 

    ${DTY_NATIVE_TEST_NAME}.core
)

# 构建测试 - dty.common.native.test.prime.core.property
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.property)
add_executable(${DTY_NATIVE_TEST_PRIME_CORE_NAME}.property property.cpp)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.property 

    ${DTY_NATIVE_TEST_NAME}.core
)

# 构建测试 - dty.common.native.test.prime.core.pointer
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.pointer)
add_executable(${DTY_NATIVE_TEST_PRIME_CORE_NAME}.pointer smartpointer.cpp)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.pointer 

    ${DTY_NATIVE_TEST_NAME}.core
)

# 构建测试 - dty.common.native.test.prime.core.formatter
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.formatter)
add_executable(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.formatter 
    
    formatter.cpp

    ${PROJECT_SOURCE_DIR}/native/prime/core/src/formatter.cpp
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/parse.base.cpp
)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.formatter 

    ${DTY_NATIVE_TEST_NAME}.core
)

# 构建测试 - dty.common.native.test.prime.core.basetype
message("                执行: " ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.basetype)
add_executable(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.basetype 
    
    basetype.cpp
    src/basetype_boolean.cpp
    src/basetype_integer.cpp

    ${PROJECT_SOURCE_DIR}/native/prime/core/src/boolean.cpp
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/double.cpp
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/float.cpp
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/formatter.cpp
    ${PROJECT_SOURCE_DIR}/native/prime/core/src/parse.base.cpp
)
target_link_libraries(
    ${DTY_NATIVE_TEST_PRIME_CORE_NAME}.basetype 

    ${DTY_NATIVE_TEST_NAME}.core
)

message("            构建-完成")