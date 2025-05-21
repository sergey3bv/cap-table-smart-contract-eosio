#include "cap_table.hpp"

CapTable::CapTable(const eosio::name& self,
                   const eosio::name& first_receiver,
                   const eosio::datastream<const char*>& ds)
    : eosio::contract(self, first_receiver, ds)
{
}

void CapTable::hi(const eosio::name& nm ) {
    eosio::print("Hello, ", nm);
}
