/**
 * @file utilize.hh(native/core)
 * @author senyun.yao
 * @brief 用于天宇平台的公用组件核心 包含跨平台支持、基础C++支持以及用于Tianyu Framework的测试组件核心
 * @brief AiTianyu Platform Public Common Core (C++ only)
 *        including supporting for cross platform, basic supporting for C++ and Test Components Core of Tianyu Framework
 *
 * @version 0.1
 * @date 2021-11-09
 * @date 2021-12-28
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_COMMON_NATIVE_DTY_CORE_H_XX__
#define __DTY_COMMON_NATIVE_DTY_CORE_H_XX__

 //
// ################################################################################################
// ################################################################################################
// ################################################################################################
// Cross Platform Definition
// ################################################################################################
// ################################################################################################
// ################################################################################################
#pragma region cross platform
 /**
  * Environment Defs:
  * https://sourceforge.net/p/predef/wiki/OperatingSystems/
  *
  */

  /**
   * @brief 检查是否为Windows操作系统平台
   * @brief Check for MS Windows
   */
#ifdef _WIN32
   // 检查64bit操作系统
   // Check for 64bit OS
#ifdef _WIN64
/**
 * @brief 定义__DTY_WIN描述当前系统为：微软 Windows
 * @brief Define __DTY_WIN to describe current system is: Microsoft Windows
 */
#define __DTY_WIN 1
#else
/**
 * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
 * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
 */
#define __DTY_ERR_64 1
#endif // !_WIN64
#endif // !_WIN32

 /**
  * @brief 检查是否为Mac OS操作系统平台
  * @brief Check for Apple MacOS
  */
#if defined(__APPLE__) || defined(__MACH__)
  /**
   * @brief 定义__DTY_APF描述当前系统为：Apple MacOS
   * @brief Define __DTY_APF to describe current system is: Apple MacOS
   */
#define __DTY_APF 1
#include "TargetConditionals.h" // import mac infor header
#if TARGET_IPHONE_SIMULATOR
   /**
    * @brief 当前系统为Apple平台Iphone模拟器
    * @brief Current system is Apple OS for Iphone Simulator
    */
#define __DTY_AIS 1
#elif TARGET_OS_IPHONE
   /**
    * @brief 当前系统为Apple IOS
    * @brief Current system is Apple OS for Iphone
    */
#define __DTY_AIP 1
#elif TARGET_OS_MAC
   /**
    * @brief 当前系统为Apple MacOS
    * @brief Current system is Apple OS for Mac
    */
#define __DTY_AMC 1
#else
   /**
    * @brief 未知的Apple系统平台
    * @brief Throw error for Unknown Apple Platform
    */
#error Unknown Apple Platform
#endif
#endif // !defined(__APPLE__) || defined(__MACH__)

    /**
     * @brief 检查是否为Linux操作系统平台
     * @brief Check for Linux
     */
#if defined(__linux__) || defined(__gnu_linux__)
#if defined(__LP64__) || defined(__x86_64__) || defined(__amd64)
     /**
      * @brief 定义__DTY_LNX描述当前系统为：Linux系列
      * @brief Define __DTY_LNX to describe current system is: Linux Serials System
      */
#define __DTY_LNX 1
#else
     /**
      * @brief 定义__DTY_ERR_64设置错误状态：当前系统需要64bit环境
      * @brief Define __DTY_ERR_64 to set error state: 64bit OS is required
      */
#define __DTY_ERR_64 1
#endif
#endif // !defined(__linux__) || defined(__gnu_linux__)

      /**
       * @brief 检查64bit操作系统状态
       * @brief Check state of 64bit OS
       */
#ifdef __DTY_ERR_64
#error Tianyu Platform require 64bit OS
#endif // !__DTY_ERR_64

       /**
        * @brief 检查操作系统兼容性
        * @brief Check OS supportable state
        */
#if !defined(__DTY_WIN) && !defined(__DTY_APF) && !defined(__DTY_LNX)
#error Unknown OS is not supported for Tianyu Platform
#endif // !!defined(__DTY_WIN) && !defined(__DTY_APF) && !defined(__DTY_LNX)

#ifdef __cplusplus
namespace dty
{
    /**
     * @brief 定义天宇平台支持的平台
     * @brief Defination for Tianyu Native Platform Supported
     */
    enum class PlatformID : signed int
    {
        MacOSX = 6,
        Other = 7,
        Unix = 4,
        Windows = 1
    };
}
#endif // !__cplusplus

#pragma endregion

// ################################################################################################
// ################################################################################################
// ################################################################################################
// Basic Definition in Pure C mode
// ################################################################################################
// ################################################################################################
// ################################################################################################
#pragma region pure c mode definition

// 天宇开发模式标志
#define __DTY_DEV_MODE__    1


 // 字符类型有符号数最小值
#define __SIGNED_CHAR_MIN__     (-128)
// 字符类型有符号数最大值
#define __SIGNED_CHAR_MAX__     127
// 字符类型无符号数最小值
#define __UNSIGNED_CHAR_MIN__   0
// 字符类型无符号数最大值
#define __UNSIGNED_CHAR_MAX__   0xFF

// 8位整数类型有符号数最小值
#define __SIGNED_INT8_MIN__     (-128)
// 8位整数类型有符号数最大值
#define __SIGNED_INT8_MAX__     127
// 8位整数类型无符号数最小值
#define __UNSIGNED_INT8_MIN__   0
// 8位整数类型无符号数最大值
#define __UNSIGNED_INT8_MAX__   0xFF

// 16位整数类型有符号数最小值
#define __SIGNED_INT16_MIN__    (-32768)
// 16位整数类型无符号数最小值
#define __SIGNED_INT16_MAX__    32767
// 16位整数类型无符号数最小值
#define __UNSIGNED_INT16_MIN__  0
// 16位整数类型无符号数最大值
#define __UNSIGNED_INT16_MAX__  0xFFFF

// 32位整数类型有符号数最小值
#define __SIGNED_INT32_MIN__    (-2147483647 - 1)
// 32位整数类型无符号数最小值
#define __SIGNED_INT32_MAX__    2147483647
// 32位整数类型无符号数最小值
#define __UNSIGNED_INT32_MIN__  0
// 32位整数类型无符号数最大值
#define __UNSIGNED_INT32_MAX__  0xFFFFFFFF

// 64位整数类型有符号数最小值
#define __SIGNED_INT64_MIN__    (-9223372036854775807 - 1)
// 64位整数类型无符号数最小值
#define __SIGNED_INT64_MAX__    9223372036854775807
// 64位整数类型无符号数最小值
#define __UNSIGNED_INT64_MIN__  0
// 64位整数类型无符号数最大值
#define __UNSIGNED_INT64_MAX__  0xFFFFFFFFFFFFFFFF

// 前向引用 标志 用于标识未定义实体的方法、结构体、类等元素
#define __PREDEFINE__
// 前向引用 标志 用于标识__PREDEFINE__定义的方法、结构体、类等元素的实现
#define __PREREALIZ__
// 默认实现 标志 用于标识可重载函数和拓展类型、数据的默认实现
#define __DEFAULT__
// 构造函数 标志 用于标识类的构造函数（包含模拟OO）
#define __CONSTRUCTOR__
// 析构函数 标志 用于标识类的析构函数（包含模拟OO）
#define __DESTRUCTOR__
// 复制构造函数 标志 用于标识类的复制构造函数（包含模拟OO）
#define __COPYSTRUCTOR__
// 值类型 标志 用于标识以值类型保存、传递的属性、变量和参数
#define __VARIABLE__
// 数组类型 后缀 用于标识当前值类型保存为数组
#define __ARRAY__ []
// 名    称：指针类型 标志 用于标识以指针类型保存、传递的属性、变量和参数
#define __POINTER__ *
#define __DPOINTER__ **
// 指针→值类型转换 标志 用于标识指针类型到值类型的转换
#define __PTR_TO_VAR__ *
// 值→指针类型转换 标志 用于标识值类型到指针类型的转换
#define __VAR_TO_PTR__ &
// 方法/函数纯输入参数 标志 用于标识方法与函数的参数类型为输入
#define __INPUT__
// 方法/函数纯输出参数 标志 用于标识方法与函数的参数类型为输出
#define __OTPUT__
// 方法/函数输入输出参数 标志 用于标识方法与函数的参数类型既可以进行输入也可作为返回
#define __INOUT__
// 传入实例标志 标志 用于标识方法的传入参数为当前操作的实例（用于C语言的模拟OO）
#define __INSTE__


#ifdef __cplusplus
 // C语言编译模式 标志 用于标识所修饰的元素以C语言的方式进行编译
#define __CMODE__ extern "C"
#endif // !__cplusplus

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus && __CMODE__ {

    // pure C mode

#pragma region redefine for base data type
// 无符号字符 数据类型
typedef      unsigned char __VARIABLE__ uchar;
// 有符号字节 数据类型
typedef        signed char __VARIABLE__ sbyte;
// 无符号字节 数据类型
typedef      unsigned char __VARIABLE__ byte;
// 有符号16位整数 数据类型
typedef       signed short __VARIABLE__ int16;
// 无符号16位整数 数据类型
typedef     unsigned short __VARIABLE__ uint16;
// 有符号32位整数 数据类型
typedef         signed int __VARIABLE__ int32;
// 无符号32位整数 数据类型
typedef       unsigned int __VARIABLE__ uint32;
// 有符号64位整数 数据类型
typedef   signed long long __VARIABLE__ int64;
// 无符号64位整数 数据类型
typedef unsigned long long __VARIABLE__ uint64;
// 对象类型（任意类型） 数据类型 指针类型
typedef               void __POINTER__  object;
// 字符串类型 数据类型 指针类型
typedef               char __POINTER__  string;

#ifndef __cplusplus
// 布尔类型 数据类型
typedef      unsigned char __VARIABLE__ bool;

#define TRUE ((bool)1)
#define TRUE ((bool)0)
#endif // !__cplusplus }

#pragma endregion

// 定义用于tianyu native的通用id字节长度
__DEFAULT__ const int32 __VARIABLE__ dty_native_id_default_size = 16;

#ifdef __cplusplus
}
#endif // !__cplusplus }

#ifndef __cplusplus
#define NULL ((void __POINTER__)0)
#endif // !__cplusplus }

#pragma endregion

// ################################################################################################
// ################################################################################################
// ################################################################################################
// C++ Basic Definition
// ################################################################################################
// ################################################################################################
// ################################################################################################
#pragma region cpp definition

#ifdef __DTY_DEV_MODE__
/**
 * @brief 该标识指示当前天库是否可以支持不安全的内存操作 
 * @brief The flag that allow unsafe memory operations in Tianyu Library when it is defined
 */
 // #define __DTY_UNSAFE_MODE__ "Tianyu Library Unsafe Mode"
 // #define __DTY_DEEP_LEARNING_MODE__
 // #define __DTY_SMART_POINTER_COPY_WEAK_MODE__
#else
#if __cplusplus < 201700
#error library needs C++17 or later
#endif
#endif // !__DTY_DEV_MODE__

    // 公有访问权标志 指示修饰的函数与属性外部可访问
#define __PUB__ public:
// 私有访问权标志 指示修饰的函数与属性外部不可访问
#define __PRI__ private:
// 继承访问权标志 指示修饰的函数与属性子类可访问
#define __PRO__ protected:

// 构造函数返回值替换宏定义
#define __construction__
// 复制构造函数返回值替换宏定义
#define __cp_construct__
// 析构函数返回值替换宏定义
#define __destruction__

// 纯虚函数后缀
#define __pure_virtual_fun = 0
// 纯虚常函数后缀
#define __pure_const_fn const = 0
// 函数重载
#define __override_func override
// 常函数重载
#define __override_cfun const override

// 引用类型 标志 用于标识以引用类型保存、传递的属性、变量和参数
#define __REFERENCE__ &
// 指针引用类型 标志 用于标识以指针引用类型保存、传递的属性、变量和参数
#define __PTRREFER__ *&

// 指针→引用类型转换 标志 用于标识指针类型到引用类型的转换
#define __PTR_TO_REF__ *
// 引用→指针类型转换 标志 用于标识引用类型到指针类型的转换
#define __REF_TO_PTR__ &
// 引用→值类型转换 标志 用于标识引用类型到值类型的转换
#define __REF_TO_VAR__
// 值→引用类型转换 标志 用于标识值类型到引用类型的转换
#define __VAR_TO_REF__

// abstract class define
#define abstract
// define interface that is an abstract class
#define _interface abstract class

// null value for pointer, must to be used by adding "::" ahead (::null)
constexpr auto null = nullptr;

// #################################################################################################
// The Core APIs for Tianyu Native
// String Base APIs: in order to do some string operations without including a huge header files
// #################################################################################################

#pragma region c_string basic APIs
int32    __VARIABLE__ strlen(const ::string __VARIABLE__ str);

::string __VARIABLE__ uc2str(uchar __VARIABLE__ ch);
// ::string __VARIABLE__ sb2str(sbyte __VARIABLE__ sb, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ b2str(::byte __VARIABLE__ b, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ s2str(int16 __VARIABLE__ s, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ us2str(uint16 __VARIABLE__ us, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ i2str(int32 __VARIABLE__ i, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ ui2str(uint32 __VARIABLE__ ui, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ l2str(int64 __VARIABLE__ l, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ ul2str(uint64 __VARIABLE__ ul, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ f2str(float __VARIABLE__ f, const ::string __VARIABLE__ formatter);
// ::string __VARIABLE__ d2str(double __VARIABLE__ d, const ::string __VARIABLE__ formatter);
#pragma endregion

// #################################################################################################
// Data Type definition for Tianyu Class base
// Tianyu Type Helper (Type<T>)
// Tianyu ToString Interface (IToString)
// Tianyu Object Base (TianyuObject)
// 
// Tianyu Class Type Marco Definition
// #################################################################################################

namespace dty
{
    // general data type class
    // get a name and type id to indicate a specified type
    __PREDEFINE__ template<typename T> class Type;

    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType();
    __PREDEFINE__ template<typename T> Type<T>  __VARIABLE__ GetType(T __REFERENCE__ obj);
    /**
     * @brief internal default function: to get a general object full name from a template type
     *        (specified object).
     *
     * @tparam T template type
     * @param obj specified object
     * @return __DEFAULT__::string return a full name of the specified object
     *
     * @warning Pay attention: MUST to release the return value before it is discarded.
     */
    __PREDEFINE__ template<typename T> ::string __VARIABLE__ _dty_native_cpp_default_to_string(T __REFERENCE__ obj) noexcept;

    /**
     * @brief Tianyu Type Operation Object
     *
     * @tparam T Type
     */
    template<typename T> class Type final
    {
        // static object for each object
        // to make diffs for different data type
        __PRI__ static bool __VARIABLE__ _dummy;

        __PRI__::string __VARIABLE__ _Name;
        __PRI__ uint64  __VARIABLE__ _Id;
        __PRI__ uint64  __VARIABLE__ _InstanceHash;

        __PRI__ __construction__ Type();
        __PRI__ __construction__ Type(uint64        __VARIABLE__  instance);
        __PUB__ __cp_construct__ Type(const Type<T> __REFERENCE__ other);
        __PUB__ __destruction__  ~Type();

        __PUB__::string __VARIABLE__ Name() const;
        __PUB__ uint64  __VARIABLE__ Id();
        __PUB__ uint64  __VARIABLE__ InstanceHashCode();

        friend Type<T>  __VARIABLE__ GetType<T>();
        friend Type<T>  __VARIABLE__ GetType<T>(T __REFERENCE__ obj);
        friend ::string __VARIABLE__ _dty_native_cpp_default_to_string<T>(T __REFERENCE__ obj) noexcept;
    };

    /**
     * @brief Convert an object to string type
     * @note must to convert to a pointer that can be delete by caller, like Console.WriteLine(obj),
     *       when ToString is called in Console function implicitly, the ToString return should confirm
     *       the string can be released.
     *
     * @warning if the ToString function does just return a reference pointer, unexpected things will happen.
     *          Please make sure the incorrect realization does not be used for basic components of Tianyu
     *          Library.
     */
    _interface IToString
    {
        __PUB__ virtual __destruction__ ~IToString() { }

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __pure_virtual_fun;
    };

    // Tianyu Object 
    // this is a basic object type for Tianyu Native and all of the sub type in Tianyu Native
    // this is a hierarchy root for Data Type in Tianyu Native
    // Tianyu Object provides the basic and generic interfaces.
    abstract class TianyuObject : public virtual dty::IToString
    {
        __PRO__         __construction__ TianyuObject();
        __PUB__ virtual __destruction__  ~TianyuObject() __override_func;

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept __override_func;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId();
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode();

        __PUB__ virtual bool __VARIABLE__ IsNull();
        __PUB__ virtual bool __VARIABLE__ Equals(TianyuObject __REFERENCE__ obj);
        __PUB__ virtual bool __VARIABLE__ operator==(TianyuObject __REFERENCE__ obj);

        __PUB__ static  bool __VARIABLE__ IsNull(TianyuObject __REFERENCE__ obj);
    };
}

// internal macro definition for tianyu class type
#define _ty_class(cname, ...) class cname : __VA_ARGS__

// Macro Definition for Tianyu Class Type
// Default externed from dty::TianyuObject, provide external functions
#define _class(cname, ...) _ty_class(cname, public virtual dty::TianyuObject, ##__VA_ARGS__)

// Macro Definition for Tianyu Class final Type
// Default externed from dty::TianyuObject, provide external functions
#define _sealed(cname, ...) _ty_class(cname final, public virtual dty::TianyuObject, ##__VA_ARGS__)

// Macro Definition for clearly enum define
// enum class
#define _enum enum class

#pragma endregion

// #################################################################################################
// #################################################################################################
// #################################################################################################
// The Core APIs for Tianyu Native Implementation
// #################################################################################################
// #################################################################################################
// #################################################################################################

#pragma region dty-core implementation
// #################################################################################################
// #################################################################################################
// Import all of the Template class implementation files
// #################################################################################################
// #################################################################################################
#define __TEMPLATE_DEF__ template<typename T>
#define __DTY_TYPE_DEF__ dty::Type<T>
#define __GET_TYPE_DEF__ dty::GetType
 //
//#######################################################################################
// Implementation for GetType API
//#######################################################################################
#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

#include <typeinfo>

__TEMPLATE_DEF__ __DTY_TYPE_DEF__ __GET_TYPE_DEF__()
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __DTY_TYPE_DEF__ type;
#ifdef __GNUC__
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
    if (0 != status)
    {
        int32 length = ::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
    }
#else // !__GNUC__
    int32 length = ::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

    return type;
}

__TEMPLATE_DEF__ __DTY_TYPE_DEF__ __GET_TYPE_DEF__(T& obj)
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __DTY_TYPE_DEF__ type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
    if (0 != status)
    {
        int32 length = ::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
    }
#else // !__GNUC__
    int32 length = ::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

    return type;
}

__TEMPLATE_DEF__::string dty::_dty_native_cpp_default_to_string(T& obj) noexcept
{
    __DTY_TYPE_DEF__ otype = __GET_TYPE_DEF__(obj);
    ::string str = otype._Name;

    otype._Name = ::null;

    return str;
}

//#######################################################################################
// Implementation for Type class
//#######################################################################################

__TEMPLATE_DEF__ bool __DTY_TYPE_DEF__::_dummy = false;

__TEMPLATE_DEF__ __construction__ __DTY_TYPE_DEF__::Type()
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(0ULL)
{ }

__TEMPLATE_DEF__ __construction__ __DTY_TYPE_DEF__::Type(uint64 instance)
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(instance)
{ }

__TEMPLATE_DEF__ __cp_construct__ __DTY_TYPE_DEF__::Type(const __DTY_TYPE_DEF__& other)
    : _Name(::null),
    _Id(other._Id),
    _InstanceHash(other._InstanceHash)
{
    __DTY_TYPE_DEF__& copy = const_cast<__DTY_TYPE_DEF__&>(other);
    this->_Name = copy._Name;

    copy._Name = ::null;
}

__TEMPLATE_DEF__ __destruction__  __DTY_TYPE_DEF__::~Type()
{
    if (::null != this->_Name)
        delete [](this->_Name);
}

__TEMPLATE_DEF__::string __DTY_TYPE_DEF__::Name() const
{
    return this->_Name;
}

__TEMPLATE_DEF__ uint64 __DTY_TYPE_DEF__::Id()
{
    return this->_Id;
}

__TEMPLATE_DEF__ uint64 __DTY_TYPE_DEF__::InstanceHashCode()
{
    return this->_InstanceHash;
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __DTY_TYPE_DEF__
#undef __GET_TYPE_DEF__

#pragma endregion

// #################################################################################################
// #################################################################################################
// #################################################################################################
// The Core for Tianyu Native Test
// #################################################################################################
// #################################################################################################
// #################################################################################################
#pragma region dty-test-core
#ifdef __DTEST_CORE__
#ifdef __cplusplus
//
// import the core definition of Tianyu Native
#include "stdio.h"
#include <iostream>

namespace dty::test
{
    _enum TestState : int32
    {
        Success = 0,
        Failed = -1,
        Skipped = -2
    };

    _enum TestType : int32
    {
        Skipped = 0,
        Expect = 1,
        Assert = 2
    };

    // Test Object
    // test object to provide the basic APIs for test result exporter and some expect/assert
    // operations.
    // each test item must to use the object to record the test progress.
    class TestObject final : public virtual dty::TianyuObject
    {
        __PRI__ TestState __VARIABLE__  _State;


        __PUB__         __construction__ TestObject();
        __PUB__ virtual __destruction__  ~TestObject() __override_func;

        __PUB__ TestState __VARIABLE__ GetState();

        __PRI__ void      __VARIABLE__ SetState(bool __VARIABLE__ result);

        // ##############################################################################################################
        // expects area
        // ##############################################################################################################

        __PUB__ void __VARIABLE__ Set();
        __PUB__ void __VARIABLE__ Skip();
        __PUB__ void __VARIABLE__ Unset();

        __PUB__ bool __VARIABLE__ IsNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNull(dty::TianyuObject __REFERENCE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(object __VARIABLE__ obj);
        __PUB__ bool __VARIABLE__ IsNotNull(dty::TianyuObject __REFERENCE__ obj);

        __PUB__ bool __VARIABLE__ IsEmpty(const ::string __VARIABLE__ str);
        __PUB__ bool __VARIABLE__ IsNotEmpty(const ::string __VARIABLE__ str);

        __PUB__ bool __VARIABLE__ ToBeTrue(bool __VARIABLE__ value);
        __PUB__ bool __VARIABLE__ ToBeFalse(bool __VARIABLE__ value);

        __PUB__ bool __VARIABLE__ EQ(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ NE(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ GT(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ LT(const ::string __VARIABLE__ str1, const ::string __VARIABLE__ str2);
        __PUB__ bool __VARIABLE__ StrLenIs(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenIsNot(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenGT(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);
        __PUB__ bool __VARIABLE__ StrLenLT(const ::string __VARIABLE__ str, int32 __VARIABLE__ len);

        __PUB__ bool __VARIABLE__ EQ(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ NE(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ GT(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);
        __PUB__ bool __VARIABLE__ LT(dty::TianyuObject __REFERENCE__ val1, dty::TianyuObject __REFERENCE__ val2);

        // ##############################################################################################################
        // template expects and asserts
        // ##############################################################################################################

        __PUB__ template<typename T> bool __VARIABLE__ EQ(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ NE(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ GT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
        __PUB__ template<typename T> bool __VARIABLE__ LT(T __VARIABLE__ val1, T __VARIABLE__ val2) noexcept;
    };

    template<typename T> bool dty::test::TestObject::EQ(T val1, T val2) noexcept
    {
        bool result = val1 == val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool dty::test::TestObject::NE(T val1, T val2) noexcept
    {
        bool result = val1 != val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool dty::test::TestObject::GT(T val1, T val2) noexcept
    {
        bool result = val1 > val2;

        this->SetState(result);
        return result;
    }

    template<typename T> bool dty::test::TestObject::LT(T val1, T val2) noexcept
    {
        bool result = val1 < val2;

        this->SetState(result);
        return result;
    }

    // test function
    // use a test function delegate to import a test item
    using TestDelegate = void __VARIABLE__(__POINTER__)(TestObject __REFERENCE__ tobj);

    __PREDEFINE__ class TestEntity;

    using TestSpecDelegate = void __VARIABLE__(__POINTER__)(TestEntity __REFERENCE__ entity);

    // test entity
    // as its name showing, each test should start a test entity to process the actual tests.
    // for each test group, test entity could be created multiable times and there are not
    // dependent with each other.
    class TestEntity final : public virtual dty::TianyuObject
    {
        __PRI__ bool       __VARIABLE__  _ConsolePrint;
        __PRI__::string    __VARIABLE__  _EntityName;
        __PRI__::string    __VARIABLE__  _LogFile;
        __PRI__ FILE       __POINTER__   _LogStream;
        __PRI__ bool       __VARIABLE__  _LogOwner;
        __PRI__ TestState  __VARIABLE__  _State;
        __PRI__ bool       __VARIABLE__  _Asserted;
        __PRI__ int32      __VARIABLE__  _Level;
        __PRI__ int32      __VARIABLE__  _SuccessCount;
        __PRI__ int32      __VARIABLE__  _SkippedCount;
        __PRI__ int32      __VARIABLE__  _FailureCount;

        __PRI__         __construction__ TestEntity
        (
            const ::string __VARIABLE__  entityName,
            TestEntity     __REFERENCE__ pentity,
            FILE           __POINTER__   file,
            int32          __VARIABLE__  level,
            bool           __VARIABLE__  console_print
        );
        __PUB__         __construction__ TestEntity
        (
            const ::string __VARIABLE__ entityName,
            int32          __VARIABLE__ argc,
            char           __POINTER__  argv __ARRAY__
        );
        __PUB__         __cp_construct__ TestEntity(const TestEntity __REFERENCE__ entity);
        __PUB__ virtual __destruction__  ~TestEntity() __override_func;

        __PUB__ TestState  __VARIABLE__ GetState();
        __PUB__ void       __VARIABLE__ StartSpec(const ::string __VARIABLE__ entityName, TestSpecDelegate __VARIABLE__ spec);
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const ::string   __VARIABLE__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException
        );
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const ::string   __VARIABLE__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException,
            bool             __VARIABLE__ depPreState
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item,
            bool           __VARIABLE__ ignore_exception
        );
        __PUB__ void       __VARIABLE__ RunExceptionTest
        (
            const ::string __VARIABLE__ test_name,
            const ::string __VARIABLE__ test_description,
            TestDelegate   __VARIABLE__ test_item
        );

        // ###################################################################################################################
        // const char* define
        // ###################################################################################################################

        __PRI__         __construction__ TestEntity
        (
            const char __POINTER__   entityName,
            TestEntity __REFERENCE__ pentity,
            FILE       __POINTER__   file,
            int32      __VARIABLE__  level,
            bool       __VARIABLE__  console_print
        );
        __PUB__         __construction__ TestEntity(const char __POINTER__ entityName, int32 __VARIABLE__ argc, char __POINTER__ argv __ARRAY__);

        __PUB__ void       __VARIABLE__ StartSpec(const char __POINTER__ entityName, TestSpecDelegate __VARIABLE__ spec);
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const char       __POINTER__ entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException
        );
        __PUB__ void       __VARIABLE__ StartSpec
        (
            const char       __POINTER__  entityName,
            TestSpecDelegate __VARIABLE__ spec,
            bool             __VARIABLE__ ignoreException,
            bool             __VARIABLE__ depPreState
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item
        );
        __PUB__ void       __VARIABLE__ RunTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item,
            bool         __VARIABLE__ ignore_exception
        );
        __PUB__ void       __VARIABLE__ RunExceptionTest
        (
            const char   __POINTER__  test_name,
            const char   __POINTER__  test_description,
            TestDelegate __VARIABLE__ test_item
        );

        __PRI__ void       __VARIABLE__ NotifyState(TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ Record(int32 __VARIABLE__ level = 0);
        __PRI__ void       __VARIABLE__ Record(const ::string __VARIABLE__ name, const ::string __VARIABLE__ description, TestState __VARIABLE__ state);
        __PRI__ void       __VARIABLE__ EndRecord();
    };

    constexpr int32 _dty_test_entity_fail_param_too_few = -1;
    constexpr int32 _dty_test_entity_fail_param_pre_more = -2;
    constexpr int32 _dty_test_entity_fail_file_open = -3;
}

using TO = dty::test::TestObject;
using TD = dty::test::TestDelegate;
using TSD = dty::test::TestSpecDelegate;
using TE = dty::test::TestEntity;
using TS = dty::test::TestState;
using TT = dty::test::TestType;
using N = const ::string;

#define TestsEntry_Main() \
    int32 __VARIABLE__ main(int32 __VARIABLE__ argc,char __POINTER__ argv __ARRAY__)

#define TestEntityCreator(entityName, entityDes) dty::test::TestEntity entityName(entityDes, argc, argv)

#define Test_Main_Return(testEntity) return (int32)(testEntity .GetState())

#define RUNTEST(testName, testDes)                                                                      \
    void TestEntry_TestRunner(dty::test::TestEntity&);                                                  \
    TestsEntry_Main()                                                                                   \
    {                                                                                                   \
        try                                                                                             \
        {                                                                                               \
            TestEntityCreator(TEntity, testDes);                                                        \
            TestEntry_TestRunner(TEntity);                                                              \
            Test_Main_Return(TEntity);                                                                  \
        }                                                                                               \
        catch(int32 err)                                                                                \
        {                                                                                               \
            switch (err)                                                                                \
            {                                                                                           \
                case dty::test::_dty_test_entity_fail_param_too_few:                                    \
                    std::cout << "Test Program need at least 1 parameter." << std::endl;                \
                    break;                                                                              \
                case dty::test::_dty_test_entity_fail_param_pre_more:                                   \
                    std::cout << "Program parameter error with wrong pre '-' character." << std::endl;  \
                    break;                                                                              \
                case dty::test::_dty_test_entity_fail_file_open:                                        \
                    std::cout << "Output file open failed!" << std::endl;                               \
                    break;                                                                              \
                default:                                                                                \
                    std::cout << "Unknown Error" << std::endl;                                          \
                    break;                                                                              \
            }                                                                                           \
        }                                                                                               \
        catch(...)                                                                                      \
        {                                                                                               \
            std::cout << "Unknown Error" << std::endl;                                                  \
        }                                                                                               \
        return -1;                                                                                      \
    }                                                                                                   \
    void TestEntry_TestRunner(dty::test::TestEntity& testName)

#define TEST_MAIN(des) RUNTEST(entity, (const ::string)des)

#define TEST_SPEC(specName, statements)                                                  \
    entity.StartSpec((const ::string)specName, [](dty::test::TestEntity& entity) -> void \
        statements                                                                       \
    )

#define TEST_ITEM(itemName, itemDes, statements)    \
    entity.RunTest(                                 \
        (const ::string)itemName,                   \
        (const ::string)itemDes,                    \
        [](dty::test::TestObject& tobj) -> void     \
        statements                                  \
    )

#endif // !__cplusplus
#endif // !__DTEST_CORE__

#pragma endregion

#endif // !__DTY_COMMON_NATIVE_DTY_CORE_H_XX__
