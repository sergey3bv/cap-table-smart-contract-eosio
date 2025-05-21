#include "table/migration.hpp"

uint64_t Migration::primary_key() const
{
    return this->user.value;
}

eosio::checksum256 Migration::by_address() const
{
    return eosio::checksum256(this->address.extract_as_byte_array());
}

uint64_t Migration::by_migrate_status() const
{
    return this->migrated ? 1ul : 0ul;
}
