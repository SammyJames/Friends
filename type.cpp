#include "type.hpp"

template <ETest Mode>
uint32_t GetTypeHash(const Hell::World::WereInIt<Mode>& Src)
{
    return Src.m_value;
}

template <ETest Mode>
Archive& operator<<(Archive& Ar, Hell::World::WereInIt<Mode>& Value)
{
    Ar << Value.m_value;
    return Ar;
}

template uint32_t GetTypeHash<ETest::Off>(const Hell::World::WereInIt<ETest::Off>&);
template uint32_t GetTypeHash<ETest::On>(const Hell::World::WereInIt<ETest::On>&);

template Archive& operator<< <ETest::Off>(Archive&, Hell::World::WereInIt<ETest::Off>&);
template Archive& operator<< <ETest::On>(Archive&, Hell::World::WereInIt<ETest::On>&);