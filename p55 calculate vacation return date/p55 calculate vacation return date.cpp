#include <iostream>
#include <ctime>
using namespace std;





struct stDate
{
    short day;
    short month;
    short year;
};

short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

stDate readStDate()
{
    stDate Date;

    Date.day = readNumber("Please Enter a Day ");
    Date.month = readNumber("Please Enter a Month ");
    Date.year = readNumber("Please Enter a Year ");

    return Date;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

short numberOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

short orderOfDay(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short orderOfDay(stDate Date)
{
    return orderOfDay(Date.year, Date.month, Date.day);
}

string nameOfDay(short order)
{
    if (order == 0)
        return "Sun";

    else if (order == 1)
        return "Mon";

    else if (order == 2)
        return "Tue";

    else if (order == 3)
        return "Wed";

    else if (order == 4)
        return "Thur";

    else if (order == 5)
        return "Fri";

    else if (order == 6)
        return "Sat";
    else
        return "Wrong day input";
}

bool isEndOfWeek(stDate Date)
{
    return orderOfDay(Date) == 6;
}

bool isWeekEnd(stDate Date)
{
    short dayOrder = orderOfDay(Date);
    return dayOrder == 5 || dayOrder == 6;
}

int dateDiff(stDate Date1, stDate Date2, bool isIncludeEndDay = false)
{
    int numberOfDays = 0;

    for (short year = Date1.year; year < Date2.year; year++)
        numberOfDays += numberOfDaysInYear(year);

    if (Date1.year == Date2.year)
    {
        for (short month = Date1.month; month < Date2.month; month++)
            numberOfDays += numberOfDaysInMonth(Date1.year, month);
    }

    numberOfDays += Date2.day - Date1.day;

    return (isIncludeEndDay) ? ++numberOfDays : numberOfDays;
}

void printDate(string msg, stDate Date)
{
    cout << msg;
    cout << nameOfDay(orderOfDay(Date)) << " , ";
    cout << Date.day << "/" << Date.month << "/" << Date.year << "\n";
}

bool isDayIsLastDay(stDate Date)
{
    return Date.day == numberOfDaysInMonth(Date.year, Date.month);
}

bool isMonthIsLastMonth(stDate Date)
{
    return Date.month == 12;
}

stDate increaseDateByOneDay(stDate Date)
{
    if (isDayIsLastDay(Date))
    {
        if (isMonthIsLastMonth(Date))
        {
            Date.month = 1;
            Date.year++;
        }
        else
            Date.month++;

        Date.day = 1;
    }
    else
        Date.day++;

    return Date;
}

stDate vacationReturnDate(stDate DateFrom, short vacation)
{
    while (vacation >= 0)
    {
        DateFrom = increaseDateByOneDay(DateFrom);
        if (isWeekEnd(DateFrom))
            continue;
        vacation--;
    }
    return DateFrom;
}




int main()
{
    stDate startDate, returnDate;

    cout << "Vacation starts:\n";
    startDate = readStDate();
    //startDate.day = 1;
    //startDate.month = 1;
    //startDate.year = 2022;
    cout << "\n";
    //short vacation = 23;
    short vacation = readNumber("Please enter vacation days?\n");

    
    returnDate = vacationReturnDate(startDate, vacation);
    printDate("Return Date: ", returnDate);

    cout << "\n\n";



    system("pause>0");
    return main();
}