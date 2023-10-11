#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void PhoneBook::set_n()
{
	this->n = 0;
}

void PhoneBook::erase_contact()
{
	std::string str;

	for(int i = 0; i < 7; i++)
	{
		str = this->contact[i + 1].get_first_name();
		this->contact[i].set_first_name(str);
		str = this->contact[i + 1].get_last_name();		
		this->contact[i].set_last_name(str);
		str = this->contact[i + 1].get_nickname();
		this->contact[i].set_nickname(str);
		str = this->contact[i + 1].get_number();
		this->contact[i].set_number(str);
		str = this->contact[i + 1].get_secret();
		this->contact[i].set_secret(str);
	}
}

void PhoneBook::add_contact()
{
	static int i = 0;
	std::string str;

	if (this->n == 8)
	{
		std::cout<<"Rubrica piena, cancellato il contatto piu' vecchio\n";
		PhoneBook::erase_contact();
		this->n = 7;
	}
	std::cout<<"First name:";
	std::cin>>str;
	this->contact[i].set_first_name(str);
	std::cout<<"Last name:";
	std::cin>>str;
	this->contact[i].set_last_name(str);
	std::cout<<"Nickname:";
	std::cin>>str;
	this->contact[i].set_nickname(str);
	std::cout<<"Phone number:";
	std::cin>>str;
	this->contact[i].set_number(str);
	std::cout<<"Darkest secret:";
	std::cin>>str;
	this->contact[i].set_secret(str);
	i++;
	if(i == 8)
		i = 7;
	this->n++;
}

void PhoneBook::display_contact(int i)
{
	std::cout<<"First name: "<<this->contact[i].get_first_name()<<"\n";
	std::cout<<"Last name: "<<this->contact[i].get_last_name()<<"\n";
	std::cout<<"Nickname: "<<this->contact[i].get_nickname()<<"\n";
	std::cout<<"Phone number: "<<this->contact[i].get_number()<<"\n";
	std::cout<<"Darkest secret: "<<this->contact[i].get_secret()<<"\n";
}

std::string str_truncate(std::string str)
{
	if (str.length() > 10)
		return ((str.substr(0, 9)).append("."));
	return(str);
}

void PhoneBook::search_contact()
{
	std::string str;
	int j = 0;

	if (n == 0)
	{
		std::cout<<"Rubrica vuota, inserire dei contatti\n";
		return ;
	}
	std::cout<<std::left<<std::setw(10)<<"Index";
	std::cout<<"|";
	std::cout<<std::left<<std::setw(10)<<"First name";
	std::cout<<"|";
	std::cout<<std::left<<std::setw(10)<<"Last name";
	std::cout<<"|";
	std::cout<<std::left<<std::setw(10)<<"Nickname";
	std::cout<<"|";
	std::cout<<"\n";

	for(int i = 0; i < this->n; i++)
	{
		std::cout<< std::right<<std::setw(10)<< (char)(i + 49);
		std::cout<<"|";
		str = this->contact[i].get_first_name();
		str = str_truncate(str);
		std::cout<<std::right<<std::setw(10)<<str;
		std::cout<<"|";
		str = this->contact[i].get_last_name();
		str = str_truncate(str);
		std::cout<<std::right<<std::setw(10)<<str;
		std::cout<<"|";	
		str = this->contact[i].get_nickname();
		str = str_truncate(str);
		std::cout<<std::right<<std::setw(10)<<str;
		std::cout<<"|";
		std::cout<<"\n";
	}
	while (1)
	{
		std::cout<<"Inserire l'index del contatto da visualizzare:";
		std::cin>>str;
		j = atoi(str.c_str());
		if (j > 0 && j <= n)
			break ;
		else
			std::cout<<"Inserire un index valido\n";
	}
	PhoneBook::display_contact(j - 1);
}

int	main(void)
{
	std::string str;
	PhoneBook	book;

	book.set_n();
	while (1)
	{
		std::cout<<"In attesa di un comando:";
		std::cin>>str;
		if (str == "ADD")
			book.add_contact();
		else if (str == "SEARCH")
			book.search_contact();
		else if (str == "EXIT")
			break;
		else
			std::cout<<"Comando non valido\n";
	}
	return(0);
}