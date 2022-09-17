// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 2
#ifndef SICT_ACCOUNTNUMBER_H_
#define SICT_ACCOUNTNUMBER_H_
namespace sict{
#define MAX_NAME_LENGTH 40
#define MIN_BANKCODE 100
#define MAX_BANKCODE 999
#define MIN_BRANCHCODE 1
#define MAX_BRANCHCODE 220
#define MIN_ACCNO 10000
#define MAX_ACCNO 99999
	class AccountNumber{
	private:
		char _name[MAX_NAME_LENGTH + 1];
		int _bankCode;
		int _branchCode;
		int _accountNumber;
		bool _validAccNumber;
		bool display_Name;
		bool display_Number;
		void displayName() const;
		void displayNumber() const;
	public:
		void name(const char name[]);
		void accountNumber(int bankCode, int branchCode, int accountNumber);
		void display(bool dspName, bool dspNumber) const;
		bool isValid() const;
	};
}
#endif

