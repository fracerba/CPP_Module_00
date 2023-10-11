#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void Contact::set_number(std::string str)
{
	this->number = str;
}

void Contact::set_secret(std::string str)
{
	this->secret = str;
}

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_number()
{
	return (this->number);
}

std::string Contact::get_secret()
{
	return (this->secret);
}
