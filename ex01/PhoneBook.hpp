#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
    private:
        Contact contact[8];
		int n;
    public:
        PhoneBook();
        ~PhoneBook();
		void erase_contact();
		void add_contact();
		void display_contact(int i);
		void search_contact();
		void set_n();
};

#endif