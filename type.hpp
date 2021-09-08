
#pragma once

#include <cstdint>

#define BROKEN 0

enum class ETest
{
    Off,
    On,
};

struct Archive
{
    Archive& operator<<(uint32_t Value)
    {
        return *this;
    }
};

namespace Hell::World
{
    template <ETest> class WereInIt;
}

template <ETest Mode>
uint32_t GetTypeHash(const Hell::World::WereInIt<Mode>& Src);

template <ETest Mode>
Archive& operator<<(Archive& Ar, Hell::World::WereInIt<Mode>& Value);

namespace Hell::World
{
    template <ETest Mode>
    class WereInIt
    {
    public:
    private:
        uint32_t m_value = ~0u;

#if BROKEN
        friend Archive& operator<<(Archive&, WereInIt<Mode>&);
        friend uint32_t GetTypeHash(const WereInIt<Mode>&);
#else
        friend Archive& (::operator<< <>)(Archive&, WereInIt<Mode>&);
        friend uint32_t (::GetTypeHash<>)(const WereInIt<Mode>&);
#endif
    };
}