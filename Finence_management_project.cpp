// Finence_management_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"Header.h"

registration::registration()
{
	string username, password;
	cout << "welcome to registration we will register your username and password" << endl;
	cout << "enter the username";
	cin >> username;
	cout << "enter the password";
	cin >> password;
	user.insert({ username, password });
}

void registration::login()
{
	string username, password;
	cout << "thank you for login please enter your registered username and password" << endl;
	cout << "enter the username";
	cin >> username;
	cout << "enter the password";
	cin >> password;
	for (auto itr = user.begin(); itr != user.end(); ++itr)
	{
		while (1)
		{
			if (itr->first == username)
			{
				cout << "username is ok" << endl;
				currentUser = username;
				break;
			}
			else
			{
				cout << "username is incorrect" << endl;
				cout << "enter new username" << endl;
				cin >> username;
			}
		}
		while (1)
		{
			if (itr->second == password)
			{
				cout << "password is ok" << endl;
				break;
			}
			else
			{
				cout << "password is incorrect" << endl;
				cout << "enter new password" << endl;
				cin >> password;
			}
		}
		status_flag = true;
	}
}
bool registration::get_status()
{
	return status_flag;
}
string registration::get_current_user()
{
	return currentUser;
}

int detail::savingamount = 100;

void tracking_expense::enter_data(string catagory, int amount, string date)
{
	detail p;
	p.category = catagory;
	p.amount = amount;
	p.date = date;

	if (p.savingamount > amount)
		p.savingamount -= amount;
	else
	{
		cout << "saving amount has low money" << endl;
	}

	expense_tracker.push_back(p);
}
void  tracking_expense::total_amount()
{
	check_list();
	int total = 0;
	for (auto itr : expense_tracker)
	{
		total = total + itr.amount;
	}
	cout << "Total amount of expenses: " << total << endl;
}

void tracking_expense::get_max_amount()
{
	check_list();
	int max = 0;

	for (auto itr : expense_tracker)
	{
		if (max < itr.amount)
		{
			max = itr.amount;
		}

	}
	cout << "max amount of expenses: " << max << endl;
}

void tracking_expense::get_min_amount()
{
	check_list();
	int min = 0;
	for (auto itr : expense_tracker)
	{
		if (min > itr.amount)
		{
			min = itr.amount;
		}

	}
	cout << "max amount of expenses: " << min << endl;
}
void tracking_expense::show_data()
{
	check_list();
	cout << " catagory" << " | " << "amount" << " | " << "date" << " | " << "savingamount" << " | " << endl;
	for (auto itr : expense_tracker)
	{
		cout << itr.category << " | " << itr.amount << " | " << itr.date << " | " << itr.savingamount << " | " << endl;
	}
}
void tracking_expense::check_list()
{
	try {
		if (expense_tracker.empty())
		{

			throw std::runtime_error("tracker is empty");
		}
	
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return;
	}

}

bool tracking_expense::check_date(string date1)
{

	check_list();

	for (auto itr : expense_tracker)
	{
		if (itr.date == date1)
		{

			return 1;
		}

	}
	return 0;


}
void tracking_expense::get_range_date_amount(const string& date1, const string& date2)
{
	int amount = 0;
	bool flag1 = check_date(date1);
	bool flag2 = check_date(date2);
	if (flag1 == 1 && flag2 == 1)
	{

		for (auto itr : expense_tracker)
		{
			if (itr.date >= date1 && itr.date <= date2)
				amount = amount + itr.amount;
		}
		cout << "amount from " << date1 << " to " << date2 << " is " << amount << endl;
	}
	else
	{
		cout << "incvalide date" << endl;

	}
}
void tracking_expense::delete_expense(const string& category)
{
	check_list();
	for (auto itr : expense_tracker)
	{
		if (itr.category == category)
		{
			expense_tracker.pop_back();
			return ;
		}
	}
	cout << "No expense entry found with category: " << category << endl;
}
void tracking_expense::show_value_based_on_catagory(string category)
{
	check_list();

	cout << " catagory " << " | " << " amount " << " | " << "date" << " | " << "saving amount" << endl;
	for (auto itr : expense_tracker)
	{
		if (itr.category == category)
		{
			cout << itr.category<<" | "<< itr.amount << " | " << itr.date << " | " << itr.savingamount << endl;
		} 
	}
}


void tracking_income::enter_data( string  category, int amount,  string date)
{
	detail p;
	p.category = category;
	p.amount = amount;
	p.date = date;


	p.savingamount += amount;


	income_tracker.push_back(p);
}
void tracking_income::check_list()
{
	try {
		if (income_tracker.empty())
		{

			throw std::runtime_error("tracker is empty");
		}

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return;
	}

}
void  tracking_income::total_amount()
{
	check_list();
	int total = 0;
	for (auto itr : income_tracker)
	{
		total = total + itr.amount;
	}
	cout << "Total amount of expenses: " << total << endl;
}

void tracking_income::get_max_amount()
{
	check_list();
	int max = 0;

	for (auto itr : income_tracker)
	{
		if (max < itr.amount)
		{
			max = itr.amount;
		}

	}
	cout << "max amount of expenses: " << max << endl;
}

void tracking_income::get_min_amount()
{
	check_list();
	int min = 0;
	for (auto itr : income_tracker)
	{
		if (min > itr.amount)
		{
			min = itr.amount;
		}

	}
	cout << "max amount of expenses: " << min << endl;
}
void tracking_income::show_data()
{
	check_list();
	cout << " catagory" << " | " << "amount" << " | " << "date" << " | " << "savingamount" << " | " << endl;
	for (auto itr : income_tracker)
	{
		cout << itr.category << " | " << itr.amount << " | " << itr.date << " | " << itr.savingamount << " | " << endl;

	}
}
bool tracking_income::check_date(string date1)
{
	check_list();
	for (auto itr : income_tracker)
	{
		if (itr.date == date1)
		{

			return 1;
		}

	}
	return 0;

}
void tracking_income::get_range_date_amount(const string& date1, const string& date2)
{
	bool flag1 = check_date(date1);
	bool flag2 = check_date(date2);
	if (flag1 == 1 && flag2 == 1)
	{
		int amount = 0;
		for (auto itr : income_tracker)
		{
			if (itr.date >= date1 && itr.date <= date2)
				amount = amount + itr.amount;
		}
		cout << "amount from " << date1 << " to " << date2 << " is " << amount << endl;
	}
	else
	{
		cout << "invalid date" << endl;

	}
}
void tracking_income::delete_expense(const string& category)
{
	check_list();
	for (auto itr : income_tracker)
	{
		if (itr.category == category)
		{
			income_tracker.pop_back();
			return; 
		}
	}
	cout << "No income entry found with category: " << category << endl;
}
void tracking_income::show_value_based_on_catagory(string category)
{
	check_list();

	cout << " catagory " << " | " << " amount " << " | " << "date" << " | " << "saving amount" << endl;
	for (auto itr : income_tracker)
	{
		if (itr.category == category)
		{
			cout << itr.category << " | " << itr.amount << " | " << itr.date << " | " << itr.savingamount << endl;
		}
	}
}
vector<detail>tracking_expense::expense_tracker;
vector<detail>tracking_income::income_tracker;



budget_tracker::budget_tracker(unique_ptr<tracking_strategy> track) : tracker(std::move(track))
{
	
	// Parameterized cobtrutor of budget_tracker
}
void budget_tracker::print_menu()
{
	std::cout << "Welcome to the budget tracking application!" << std::endl;
	std::cout << "1. Enter expense/income" << std::endl;
	std::cout << "2. Show financial data" << std::endl;
	std::cout << "3. Get maximum amount" << std::endl;
	std::cout << "4. Get minimum amount" << std::endl;
	std::cout << "5. Get total amount" << std::endl;
	std::cout << "6. dispalying data in date_range" << std::endl;
	std::cout << "7. deleting data  on the basis of catagory" << std::endl;
	std::cout << "8. Serching data on the basis of catagory " << std::endl;
	std::cout << "9. exit " << std::endl;
}
void budget_tracker::managing_data()
{
	int choice;
	std::unordered_map<int, std::function<void()>> actions = {
	{1, [&]() {   string catagory, date;
				int amount;
				cout << "please enter the catory you want expense or income" << endl;
				cin >> catagory;
				cout << "please enter the amount you want expense or income" << endl;
				cin >> amount;
				cout << "please enter the date you want expense or income" << endl;
				cin >> date;
				tracker->enter_data(catagory,amount,date);
				cout << "enter data suceesfully" << endl;
		}},
	{2, [&]() { tracker->show_data();}},
	{3, [&]() { tracker->get_max_amount(); }},
	{4, [&]() { tracker->get_min_amount(); }},
	{5, [&]() { tracker->total_amount(); }},
	{6, [&]() { string date1,date2;
	cout << "enter the date1,and date 2" << endl;
		cin >> date1;
		cin >> date2;
		tracker->get_range_date_amount(date1,date2); }},
	{7, [&]() { string catagory;
	      cout << "enter the catagory you want to delete" << endl;
		  cin >> catagory;
		  tracker->delete_expense(catagory);
		}},
	{8, [&]() {string catagory;
		  cout << "enter the catagory you want to delete" << endl;
		  cin >> catagory;
		  tracker->show_value_based_on_catagory(catagory);}},
	{9, [&]() { return; } }
	};

	while (true) {
		std::cout << "\n";
		print_menu();
		std::cout << "\nEnter your choice which operation you want:\n ";
		std::cin >> choice;

		auto it = actions.find(choice);
		if (it != actions.end()) {
			it->second(); // Execute the corresponding function
		}
		else {
			std::cout << "INVALID CHOICE :-(" << std::endl;
		}
	}
}



void type_of_traking()
{
	cout << "hello welcome to your tracking app " << endl;
	cout << " if you want to add income  press i" << endl;
	cout << "if you want to  add your expense press e" << endl;
	cout << "entr your choice" << endl;

}

int main()
{
	char ch;
	std::unique_ptr<tracking_income> inc = std::make_unique<tracking_income>();
	std::unique_ptr<tracking_expense> exp = std::make_unique<tracking_expense>();

	std::unique_ptr<budget_tracker> bgt = NULL;
	registration r;
	r.login();
	if (r.get_status())
	{
		cout << "Welcome, " << r.get_current_user() << std::endl;
		cout << "you login" << endl;

		while (1)
		{
			type_of_traking();
			cin >> ch;
			switch (ch)
			{
			case 'i':
				 bgt = make_unique<budget_tracker>(move(inc));
				break;
			case 'e':
				 bgt = make_unique<budget_tracker>(move(exp));
				break;
			default:
				cout << "you entered wromng character" << endl;
				break;
			}
			
			bgt->managing_data();
		}
	}
	else
	{
		cout << "you enterworng" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
