#include <eosio/contract.hpp>
#include <eosio/name.hpp>
#include <eosio/action.hpp>

#include "table/migration.hpp"

class [[eosio::contract("cap.table")]] CapTable : public eosio::contract
{
public:
    CapTable(const eosio::name& self,
             const eosio::name& first_receiver,
             const eosio::datastream<const char*>& ds);

    [[eosio::action("hi")]]
    void hi(const eosio::name& nm);

    using hi_action = eosio::action_wrapper<"hi"_n, &CapTable::hi>;

private:
    Migration_T migrations;
};
