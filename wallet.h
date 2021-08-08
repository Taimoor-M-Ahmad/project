#pragma once
class wallet {
	int wallet_address;//integer address
	float no_of_coins;//float coins no 
public:
	void set_wallet_address(int add) {
		wallet_address = add;
	}
	void set_coins(float c) {
		no_of_coins = c;
	}
	int get_wallet_address() {
		return wallet_address;
	}
	float get_no_of_coins() {
		return no_of_coins;
	}
	float deduct_coins(float coins) {
		no_of_coins = no_of_coins - coins;
	}
};