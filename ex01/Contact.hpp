#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string number;
        std::string secret;
    public:
        Contact();
        ~Contact();
		void set_first_name(std::string str);
        void set_last_name(std::string str);
        void set_nickname(std::string str);
        void set_number(std::string str);
        void set_secret(std::string str);
		std::string get_first_name(void);
        std::string get_last_name(void);
        std::string get_nickname(void);
        std::string get_number(void);
        std::string get_secret(void);
};

#endif
