#include <eosio/contract.hpp>
#include <eosio/name.hpp>
#include <eosio/action.hpp>
#include "eosio/asset.hpp"

#include "table/migration.hpp"

class [[eosio::contract("cap.table")]] CapTable : public eosio::contract
{
public:
    CapTable(const eosio::name& self,
             const eosio::name& first_receiver,
             const eosio::datastream<const char*>& ds);

    [[eosio::action("add")]]
    void add_user(const eosio::name& user,
                  const eosio::extended_asset balance,
                  const eosio::checksum160 eth_address);

    [[eosio::action("remove")]]
    void remove_user(const eosio::name& user);

private:
    Migration_T migrations;
};
