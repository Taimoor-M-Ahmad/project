#pragma once
#include "Transaction.h"
class block {
	transaction** Tlist = new transaction * [3];
public:
	void add_transaction(transaction* T, int n) {
		Tlist[n] = new transaction;
		Tlist[n]->set_amount(T->get_amount());
		Tlist[n]->set_digital_signature(T->get_digital_signature());
		Tlist[n]->set_reciever_key(T->get_receiver_public_key());
		Tlist[n]->set_sender_key(T->get_sender_key());
	}
	void print_block(int n) {
		for (int i = 0; i < n; i++) {
			Tlist[i]->print_transaction();
		}
	}
};