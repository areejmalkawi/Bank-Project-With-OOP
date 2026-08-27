#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<ctime>
#include<string>
#include"clsString.h";


using namespace std;

class clsDate
{
private:

	short _Day;
	short _Month;
	short _Year;

	
public:

	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
		
		
	}

	

	clsDate(string StringDate) {


		vector <string> vDate = clsString::Split(StringDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year) {

		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short TotalDays, short Year) {

		clsDate MyDate = GetDateFromDayOrderInYear(Year, TotalDays);

		this->_Day = MyDate._Day;
		this->_Month = MyDate._Month;
		this->_Year = MyDate._Year;
	}

	void SetYear(short Year) {
		_Year = Year;
	}

	short GetYear() {
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	void SetMonth(short Month) {
		_Month = Month;
	}

	short GetMonth() {
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetDay(short Day) {
		_Day = Day;
	}

	short GetDay() {
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void Print() {

		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}


	static bool IsLeapYear(short Year) {

		return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0) ? true : false);
	}

	static short DaysInMonth(short Year, short Month) {

		if (Month < 1 || Month > 12) {

			return 0;
		}

		short ArrNumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : ArrNumberOfDays[Month - 1]);
	}

	short DaysInMonth() {

		return DaysInMonth(_Year, _Month);
	}

	static short GetDayOrderOfWeek(short Year, short Month, short Day) {

		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + 12 * a - 2;

		short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

		return d;
	}

	static string GetDayName(clsDate Date) {

		short DayOrder = GetDayOrderOfWeek(Date._Year, Date._Month, Date._Day);

		string WeekArr[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return WeekArr[DayOrder];
	}

	string GetDayName() {

		return GetDayName(*this);

	}

	static string GetMonthName(short Month) {

		string MonthArr[12] = {
			"Jan", "Feb", "Mar", "Apr", "May", "Jun",
			"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
		};

		return MonthArr[Month - 1];
	}

	string GetMonthName() {

		return GetMonthName(_Month);
	}

	static void PrintMonthCalender(short Year, short Month) {

		short NumberOfDays = DaysInMonth(Year, Month);
		short Current = GetDayOrderOfWeek(Year, Month, 1);

		printf("\n  ________________%s______________\n\n", GetMonthName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < Current; i++) {
			printf("     ");
		}

		for (short j = 1; j <= NumberOfDays; j++) {
			printf("%5d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}


		printf("\n  _________________________________\n");

	}

	void PrintMonthCalender() {

		return PrintMonthCalender(_Year, _Month);
	}

	static void PrintYearCalender(short Year) {

		printf("\n  _________________________________\n\n");
		printf("\t  Calender - %4d", Year);
		printf("\n  _________________________________\n");

		for (short i = 1; i <= 12; i++) {

			PrintMonthCalender(Year, i);
		}
	}

	void PrintYearCalender() {

		return PrintYearCalender(_Year);
	}

	static clsDate StringToDate(string StringDate) {

		clsDate Date;
		string StringDay = StringDate.substr(0, StringDate.find("/"));
		Date._Day = stoi(StringDay);

		StringDate = StringDate.erase(0, StringDate.find("/") + 1);
		string StringMonth = StringDate.substr(0, StringDate.find("/"));
		Date._Month = stoi(StringMonth);

		StringDate = StringDate.erase(0, StringDate.find("/") + 1);
		string StringYear = StringDate.substr(0, StringDate.length());
		Date._Year = stoi(StringYear);

		return Date;
	}


	static clsDate GetDateFromDayOrderInYear(short Year, short TotalDays) {

		clsDate Date;
		Date._Year = Year;
		Date._Month = 1;

		short RemainingDays = TotalDays;

		short DaysOfMonth = 0;

		while (true) {

			DaysOfMonth = DaysInMonth(Date._Year, Date._Month);

			if (RemainingDays > DaysOfMonth) {
				RemainingDays -= DaysOfMonth;
				Date._Month++;
			}
			else {
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day) {

		short Sum = 0;
		Sum += Day;

		for (int i = 1; i <= Month - 1; i++) {
			Sum += DaysInMonth(Year, i);
		}
		return Sum;
	}


	static clsDate DateAddDays(short AddedDays, clsDate Date) {

		short RemainingDays = AddedDays + NumberOfDaysFromTheBeginingOfTheYear(Date._Year, Date._Month, Date._Day);
		Date._Month = 1;
		short MonthDays = 0;

		while (true) {

			MonthDays = DaysInMonth(Date._Year, Date._Month);

			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12) {
					Date._Year++;
					Date._Month = 1;
				}
			}
			else {
				Date._Day = RemainingDays;
				break;
			}

		}

		return Date;
	}

	clsDate DateAddDays(short AddedDays) {

		return DateAddDays(AddedDays, *this);
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1._Year < Date2._Year) ? true : ((Date1._Year ==
			Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month ==
				Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2) {

		return IsDate1BeforeDate2(*this, Date2);
	}


	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ?
			((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDateEqualsDate2(clsDate Date2) {

		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date) {

		return (DaysInMonth(Date._Year, Date._Month) == Date._Day);
	}

	bool IsLastDayInMonth() {

		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month) {

		return Month == 12;
	}

	bool IsLastMonthInYear() {

		return IsLastMonthInYear(_Month);
	}

	static clsDate AddOneDay(clsDate& Date) {

		if (IsLastDayInMonth(Date)) {
			if (IsLastMonthInYear(Date._Month)) {
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else {
				Date._Day = 1;
				Date._Month++;
			}
		}
		else {
			Date._Day++;
		}

		return Date;
	}

	void AddOneDay() {

		AddOneDay(*this);
	}

	static clsDate GetSystemDate() {

		clsDate Date;

		time_t t = time(0);

		tm* now = localtime(&t);
		char* dt = asctime(now);



		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	static short DifferenceInDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {

		short Days = 0;

		while (IsDate1BeforeDate2(Date1, Date2)) {

			Date1 = AddOneDay(Date1);
			Days++;
		}

		return IncludeEndDay ? ++Days : Days;
	}

	short DifferenceInDates(clsDate Date2, bool IncludeEndDay = false) {

		return DifferenceInDates(*this, Date2, IncludeEndDay);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2) {

		clsDate TempDate;

		TempDate._Day = Date1._Day;
		TempDate._Month = Date1._Month;
		TempDate._Year = Date1._Year;

		Date1._Day = Date2._Day;
		Date1._Month = Date2._Month;
		Date1._Year = Date2._Year;

		Date2._Day = TempDate._Day;
		Date2._Month = TempDate._Month;
		Date2._Year = TempDate._Year;
	}

	void Swap(clsDate& Date2) {

		SwapDates(*this, Date2);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, int NumberOfDays) {

		for (int i = 1; i <= NumberOfDays; i++) {

			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(int NumberOfDays) {

		IncreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date) {

		for (int i = 1; i <= 7; i++) {
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek() {
		
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, int NumberOfWeeks) {

		for (int i = 1; i <= NumberOfWeeks; i++) {
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeeks(int NumberOfWeeks) {

		IncreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date) {

		if (Date._Month == 12) {
			Date._Month = 1;
			Date._Year++;
		}
		else {
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth = DaysInMonth(Date._Year, Date._Month);

		if (Date._Day > NumberOfDaysInCurrentMonth) {

			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth() {

		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate& Date, int NumberOfMonths) {

		for (int i = 1; i <= NumberOfMonths; i++) {

			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonths(int NumberOfMonths) {

		IncreaseDateByXMonths(*this, NumberOfMonths);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date) {

		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear() {

		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate& Date, int NumberOfYears) {

		for (int i = 1; i <= NumberOfYears; i++) {

			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	void IncreaseDateByXYears(int NumberOfYears) {

		IncreaseDateByXYears(*this, NumberOfYears);
	}

	static clsDate IncreaseDateByXYearsFaster(clsDate& Date, int NumberOfYears) {

		Date._Year += NumberOfYears;

		return Date;
	}

	void IncreaseDateByXYearsFaster(int NumberOfYears) {

		IncreaseDateByXYearsFaster(*this, NumberOfYears);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date) {

		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade() {

		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate& Date, int NumberOfDecades) {

		for (int i = 1; i <= NumberOfDecades * 10; i++) {
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	void IncreaseDateByXDecades(int NumberOfDecades) {

		IncreaseDateByXDecades(*this, NumberOfDecades);
	}

	static clsDate IncraeseDateByXDecadesFaster(clsDate& Date, int NumberOfDecades) {

		Date._Year += 10 * NumberOfDecades;

		return Date;
	}

	void IncraeseDateByXDecadesFaster(int NumberOfDecades) {

		IncraeseDateByXDecadesFaster(*this, NumberOfDecades);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date) {

		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury() {

		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date) {

		Date._Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium() {

		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date) {

		if (Date._Day == 1) {
			if (Date._Month == 1) {
				Date._Year--;
				Date._Month = 12;
				Date._Day = 31;
			}
			else {
				Date._Month--;
				Date._Day = DaysInMonth(Date._Year, Date._Month);
			}
		}
		else {
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay() {

		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, int NumberOfDays) {

		for (int i = 1; i <= NumberOfDays; i++) {

			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(int NumberOfDays) {

		DecreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {

		for (int i = 1; i <= 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek() {

		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, int NumberOfWeeks) {

		for (int i = 1; i <= NumberOfWeeks; i++) {
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByXWeeks(int NumberOfWeeks) {

		DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {

		if (Date._Month == 1) {
			Date._Month = 12;
			Date._Year--;
		}
		else {
			Date._Month--;
		}

		short LastDayInMonth = DaysInMonth(Date._Year, Date._Month);

		if (Date._Day > LastDayInMonth) {
			Date._Day = LastDayInMonth;
		}

		return Date;
	}

	void DecreaseDateByOneMonth() {

		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate& Date, int NumberOfMonths) {

		for (int i = 1; i <= NumberOfMonths; i++) {

			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByXMonths(int NumberOfMonths) {

		DecreaseDateByXMonths(*this, NumberOfMonths);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {

		Date._Year--;

		short LastDayInMonth = DaysInMonth(Date._Year, Date._Month);

		if (Date._Day > LastDayInMonth) {
			Date._Day = LastDayInMonth;
		}

		return Date;
	}

	void DecreaseDateByOneYear() {

		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate& Date, int NumberOfYears) {

		for (int i = 1; i <= NumberOfYears; i++) {

			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByXYears(int NumberOfYears) {

		DecreaseDateByXYears(*this, NumberOfYears);
	}

	static clsDate DecreaseDateByXYearsFaster(clsDate& Date, int NumberOfYears) {

		Date._Year -= NumberOfYears;

		short LastDayInMonth = DaysInMonth(Date._Year, Date._Month);

		if (Date._Day > LastDayInMonth) {
			Date._Day = LastDayInMonth;
		}

		return Date;
	}

	void DecreaseDateByXYearsFaster(int NumberOfYears) {

		DecreaseDateByXYearsFaster(*this, NumberOfYears);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date) {

		Date._Year -= 10;

		return Date;
	}

	void DecreaseDateByOneDecade() {

		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, int NumberOfDecades) {

		for (int i = 1; i <= 10 * NumberOfDecades; i++) {

			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByXDecades(int NumberOfDecades) {

		DecreaseDateByXDecades(*this, NumberOfDecades);
	}

	static clsDate DecreaseDateByXDecadesFaster(clsDate& Date, int NumberOfDecades) {

		Date._Year -= 10 * NumberOfDecades;

		return Date;
	}

	void DecreaseDateByXDecadesFaster(int NumberOfDecades) {

		DecreaseDateByXDecadesFaster(*this, NumberOfDecades);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date) {

		Date._Year -= 100;

		return Date;
	}

	void DecreaseDateByOneCentury() {

		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date) {

		Date._Year -= 1000;

		return Date;
	}

	void DecreaseDateByOneMillennium() {
		DecreaseDateByOneMillennium(*this);
	}

	

	static short GetDayOrderOfWeek(clsDate Date) {

		return GetDayOrderOfWeek(Date._Year, Date._Month, Date._Day);
	}

	short GetDayOrderOfWeek() {

		return GetDayOrderOfWeek(*this);
	}

	static bool IsEndOfWeek(clsDate Date) {

		return GetDayOrderOfWeek(Date) == 6;
	}

	bool IsEndOfWeek() {

		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {

		short DayIndex = GetDayOrderOfWeek(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd() {

		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {

		short DayIndex = GetDayOrderOfWeek(Date);
		return (DayIndex >= 0 && DayIndex <= 4);

		//return !IsWeekEnd(Date);
	}

	bool IsBusinessDay() {

		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date) {
		return (6 - GetDayOrderOfWeek(Date));
	}

	short DaysUntilTheEndOfWeek() {

		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date) {

		clsDate EndOfMonthDate;
		EndOfMonthDate._Year = Date._Year;
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Day = DaysInMonth(Date._Year, Date._Month);

		return DifferenceInDates(Date, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfMonth() {

		return  DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date) {

		clsDate EndOfYearDate;
		EndOfYearDate._Year = Date._Year;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Day = 31;

		return DifferenceInDates(Date, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear() {

		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBussinessDays(clsDate DateFrom, clsDate DateTo) {

		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo)) {

			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = AddOneDay(DateFrom);
		}

		return DaysCount;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {

		/*short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo)) {

			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = AddOneDay(DateFrom);
		}

		return DaysCount;*/

		return CalculateBussinessDays(DateFrom, DateTo);

	}

	short CalculateVacationDaysUntil(clsDate DateTo) {

		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate StartDate, short VacationDays) {

		short WeekEnds = 0;

		if (IsWeekEnd(StartDate)) {

			StartDate = AddOneDay(StartDate);
		}

		for (short i = 1; i <= VacationDays + WeekEnds; i++) {

			if (IsWeekEnd(StartDate)) {
				WeekEnds++;
			}

			StartDate = AddOneDay(StartDate);
		}

		if (IsWeekEnd(StartDate)) {
			StartDate = AddOneDay(StartDate);
		}

		return StartDate;
	}

	clsDate CalculateVacationReturnDate(short VacationDays) {

		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
	}

	bool IsDateAfterDate2(clsDate Date2) {

		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {

		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/*if (IsDate1AfterDate2(Date1, Date2))
			return enDateCompare::After;*/

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2) {

		return CompareDates(*this, Date2);
	}

	static bool IsValidDate(clsDate Date) {

		if (Date._Day < 1 || Date._Day > 31)
			return false;

		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Month == 2) {
			if (IsLeapYear(Date._Year)) {
				if (Date._Day > 29)
					return false;
			}
			else {
				if (Date._Day > 28)
					return false;
			}
		}

		short MonthDays = DaysInMonth(Date._Year, Date._Month);

		if (Date._Day > MonthDays)
			return false;

		return true;
	}

	bool IsValid() {

		return IsValidDate(*this);
	}

	
	static string DateToString(clsDate Date) {

		return to_string(Date._Day) + "/" +
			to_string(Date._Month) + "/" +
			to_string(Date._Year);
	}

	string DateToString() {

		return DateToString(*this);
	}

	static string GetSystemDateTimeString() {

		time_t t = time(0);
		tm* now = localtime(&t);

		short Year, Month, Day, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" +
			to_string(Year) + " - " + to_string(Hour) + ":" +
			to_string(Minute) + ":" + to_string(Second);
	}
};
