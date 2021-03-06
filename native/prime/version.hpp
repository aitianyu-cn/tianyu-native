/**
 * @file version.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-16
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.version?view=net-6.0
 */

#ifndef __DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__

#include "./core.hxx"
#include "./string.hpp"

namespace dty
{
    class Version final : public virtual dty::TianyuObject,
        public virtual dty::collection::IEquatable<dty::Version>,
        public virtual dty::collection::ICompareable<dty::Version>
    {
        using Int32Property = dty::Property<int32>;
        using Int16Property = dty::Property<int16>;

        __PUB__ IPropertyGetter<int32> __REFERENCE__ Major;
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Minor;
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Build;
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Revision;
        __PUB__ IPropertyGetter<int16> __REFERENCE__ MajorRevision;
        __PUB__ IPropertyGetter<int16> __REFERENCE__ MinorRevision;

        __PRI__ Int32Property __VARIABLE__ _Major;
        __PRI__ Int32Property __VARIABLE__ _Minor;
        __PRI__ Int32Property __VARIABLE__ _Build;
        __PRI__ Int32Property __VARIABLE__ _Revision;
        __PRI__ Int16Property __VARIABLE__ _MajorRevision;
        __PRI__ Int16Property __VARIABLE__ _MinorRevision;

        __PUB__ Version();
        __PUB__ Version(const Version __REFERENCE__ other);
        __PUB__ Version(dty::String    __VARIABLE__ version);
        __PUB__ Version(const ::string __VARIABLE__ version);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor, int32 __VARIABLE__ build);
        __PUB__ Version(int32 __VARIABLE__ major, int32 __VARIABLE__ minor, int32 __VARIABLE__ build, int32 __VARIABLE__ revision);

        __PUB__ static Version __VARIABLE__ Parse(dty::String  __VARIABLE__ version);
        __PUB__ static Version __VARIABLE__ Parse(const string __VARIABLE__ version);

        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual bool     __VARIABLE__ Equals(dty::TianyuObject __REFERENCE__ other) override;
        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;

        __PUB__ Version     __REFERENCE__ operator =(const Version __REFERENCE__ version);

        __PUB__ static bool __VARIABLE__ TryParse(dty::String __VARIABLE__ version, Version __REFERENCE__ result);
        __PUB__ static bool __VARIABLE__ TryParse(const string __VARIABLE__ version, Version __REFERENCE__ result);

#pragma region dty::collection::IEquatable and ICompareable interface
        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator ==(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Version __REFERENCE__ other) override;
#pragma endregion
    };
}

#endif // !__DTY_COMMON_NATIVE_PRIME_VERSION_H_PLUS_PLUS__