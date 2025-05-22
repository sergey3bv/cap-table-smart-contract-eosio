#include "eosio/action.hpp"

#include "cap_table.hpp"

CapTable::CapTable(const eosio::name& self,
                   const eosio::name& first_receiver,
                   const eosio::datastream<const char*>& ds)
    : eosio::contract(self, first_receiver, ds)
    , migrations(self, self.value)
{
}

void CapTable::add_user(const eosio::name& user,
                        const eosio::extended_asset balance,
                        const eosio::checksum160 eth_address)
{
    eosio::require_auth(this->get_self());

    const Migration_T::const_iterator duplicate =
        this->migrations.find(user.value);
    eosio::check(duplicate == this->migrations.cend(),
                 user.to_string() + " is already added");

    eosio::check(eosio::is_account(user), user.to_string() + " does not exist");
    eosio::check(balance.quantity.amount > 0, "Empty balance");
    eosio::check(eth_address.size() > 0, "Empty address");

    (void) this->migrations.emplace(this->get_self(), [&](Migration& row)
    {
        row.user = user;
        row.balance = balance;
        row.address = eth_address;
    });
}

void CapTable::remove_user(const eosio::name& user)
{
    eosio::require_auth(this->get_self());

    const Migration_T::const_iterator existing =
        this->migrations.find(user.value);
    eosio::check(existing != this->migrations.cend(),
                 user.to_string() + " is not added");

    eosio::check(existing->migrated == false,
                 "Migrated user cannot be removed");

    (void) this->migrations.erase(existing);
}
