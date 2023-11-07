#include <iostream>
using namespace std;



short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

struct stDate
{
    short day;
    short month;
    short year;
};

stDate readStDate()
{
    stDate Date;

    Date.day = readNumber("\n\nPlease Enter a Day ");
    Date.month = readNumber("\n\nPlease Enter a Month ");
    Date.year = readNumber("\n\nPlease Enter a Year ");

    return Date;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    //return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? ((Date1.month < Date2.month) ? true : ((Date1.month == Date2.month) ? ((Date1.day < Date2.day) ? true : false) : false)) : false);
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? (Date1.day < Date2.day) : false)) : false);
}



int main()
{
    stDate Date1, Date2;

    cout << "Enter Date1 \n";
    Date1 = readStDate();

    cout << "Enter Date2 \n";
    Date2 = readStDate();

    if (isDate1BeforeDate2(Date1, Date2))
        cout << "Yes, Date1 is Less than Date2\n";
    else
        cout << "No, Date1 is Not Less than Date2\n";



    system("pause>0");

    return main();
}


//
//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <vector>
//using namespace std;
//
//
//
//short readNumber(string msg)
//{
//    short num;
//
//    cout << msg;
//    cin >> num;
//
//    return num;
//}
//
//bool isLeapYear(short year)
//{
//    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
//}
//
//short numberOfDaysInMonth(short year, short month)
//{
//    if (month == 2)
//    {
//        if (isLeapYear(year))
//            return  29;
//        else
//            return  28;
//    }
//
//    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//        return  31;
//
//    else if (month == 4 || month == 6 || month == 9 || month == 11)
//        return 30;
//
//    else
//        return 0;
//}
//
//short daysFromBegingOfYear(short year, short month, short day)
//{
//    short numberOfDays = 0;
//
//    for (short mon = 1; mon < month; mon++)
//    {
//        numberOfDays += numberOfDaysInMonth(year, mon);
//    }
//    numberOfDays += day;
//
//    return numberOfDays;
//}
//
//void dateForNumberOfDays(short year, short numberOfDays)
//{
//    short month = 1;
//    short monthDays = 0;
//
//    do
//    {
//        monthDays = numberOfDaysInMonth(year, month);
//        numberOfDays -= monthDays;
//        month++;
//
//        if (month == 12)
//        {
//            year++;
//            monthDays = numberOfDaysInMonth(year, month);
//            numberOfDays -= monthDays;
//            month = 1;
//        }
//        else
//            monthDays = numberOfDaysInMonth(year, month);
//
//    } while (numberOfDays > monthDays);
//
//    cout << numberOfDays << "/" << month << "/" << year << endl;
//}
//
//
//int main()
//{
//    short day1 = readNumber("\n\nPlease Enter a Day1? ");
//    short month1 = readNumber("\n\nPlease Enter a Month1? ");
//    short year1 = readNumber("\n\nPlease Enter a Year1? ");
//
//    short date1 = daysFromBegingOfYear(year1, month1, day1);
//
//    short day2 = readNumber("\n\nPlease Enter a Day2? ");
//    short month2 = readNumber("\n\nPlease Enter a Month2? ");
//    short year2 = readNumber("\n\nPlease Enter a Year2? ");
//
//    short date2 = daysFromBegingOfYear(year2, month2, day2);
//    cout << "Date1= " << date1 << "\n";
//    cout << "Date2= " << date2 << "\n";
//
//    if (date1 < date2)
//    {
//        cout << "Yes, Date1 is Less than Date2\n";
//    }
//    else
//    {
//        cout << "No, Date1 is Not Less than Date2\n";
//    }
//
//
//
//
//
//
//
//
//
//
//    system("pause>0");
//
//    return main();
//}
