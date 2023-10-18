#include <iostream>
#include <string>

class BankAccount{
	public:
		std::string name;
		double balance = 400.00;
		double bank = 150.59;

		void showBal() {

			std::cout << "Your balance: $" << balance << '\n';
			std::cout << "Your bank account has: $" << bank << '\n';
			std::cout << '\n';
		}

		void deposit() {

			std::cout << "Amount to deposit: $";
			double amount;
			std::cin >> amount;
			std::cout << '\n';

			if (amount < 0) {
				std::cout << "Error: Invalid number.\n";
				showBal();
			}
			else if (amount > balance) {
				std::cout << "Error: Insufficient funds.\n";
			}
			else {
				balance -= amount;
				bank += amount;
				std::cout << "Successfuly deposited: $" << amount << '\n';
				showBal();
			}
		}

		void withdraw() {

			std::cout << "Amount to withdraw: $";
			double amount;
			std::cin >> amount;
			
			if (amount > bank) {
				std::cout << "Error: You've exceeded your bank's limit.\n";
			}
			else if(amount < 0) {
				std::cout << "Error: Invalid Number. \n";
			}
			else {
				balance += amount;
				bank -= amount;

				std::cout << "Successfully withdrew: " << amount;
				std::cout << '\n';
				showBal();
			}
		}
};

int main() {

	BankAccount account;
	std::string name = account.name;

	std::cout << "Enter the name of your bank account: ";
	std::getline(std::cin, name);
	std::cout << '\n';

	std::cout << "Welcome " << name << '!' << '\n';

	account.showBal();

	account.deposit();

	account.withdraw();

}