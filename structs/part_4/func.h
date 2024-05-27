
struct date{
	int day, month, year;
}typedef Date;

struct time{
	int hour, minute, second;
}typedef Time;

struct person{
	float height, weight;
	int age;
	char gender;
}typedef Person;

void init_date(Date * date);
void read_date(Date * date);
void print_date(Date * date);

void init_time(Time * time);
void read_time(Time * time);
void print_time(Time * time);

void init_person(Person * person);
void read_person(Person * person);
void print_person(Person * person);

void fullDate(Date * date);
void USTimePattern(Time * time);
float getIMC(Person * person);
int countMonthDates(Date * arrDate, int size, int month);
int countAfterHourAppointments(Time * arrTime, int size, int hour);
float imcMedia(Person * arrPerson, int size);
Person * youngestPerson(Person * arrPerson, int size);
Person * shortestPerson(Person * arrPerson, int size);
