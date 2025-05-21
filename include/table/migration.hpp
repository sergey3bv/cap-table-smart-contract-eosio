#include <cstdint>
#include <eosio/name.hpp>
#include <eosio/asset.hpp>
#include <eosio/fixed_bytes.hpp>
#include <eosio/multi_index.hpp>

struct [[eosio::table, eosio::contract("cap.table")]] Migration
{
public:
    eosio::name user;
    eosio::extended_asset balance;
    bool migrated = false;
    eosio::checksum160 address;

public:
    uint64_t primary_key() const;

    // Secondary key to iterate over addresses
    // Note: bigger checksum, because 160 is not allowed as secondary index
    eosio::checksum256 by_address() const;
    // Tertiary key to iterate over migrate status
    uint64_t by_migrate_status() const;

    using secondary_key = eosio::const_mem_fun<Migration,
                                               eosio::checksum256,
                                               &Migration::by_address>;
    using tertiary_key = eosio::const_mem_fun<Migration,
                                              uint64_t,
                                              &Migration::by_migrate_status>;
};

using Migration_T = eosio::multi_index<"migrations"_n, Migration,
      eosio::indexed_by<"by.address"_n, Migration::secondary_key>,
      eosio::indexed_by<"by.migrate"_n, Migration::tertiary_key>>;
