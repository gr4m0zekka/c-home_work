#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <string_view>

class Time {
	private: int mHours, mMinutes, mSeconds;
	public:
		Time(int Hours, int Minutes, int Seconds) {
			mHours = Hours;
			mMinutes = Minutes;
			mSeconds = Seconds;
		}

		Time(std::string_view s) {
			mHours = (s[0] - '0') * 10 + (s[1] - '0');
			mMinutes = (s[3] - '0') * 10 + (s[4] - '0');
			mSeconds = (s[6] - '0') * 10 + (s[7] - '0');
		}

		Time operator+ (Time b) const {
			Time result = { mHours + b.mHours, mMinutes + b.mMinutes, mSeconds + b.mSeconds };
			return result;
		}

		int hours() {
			return mHours;
		}

		int minutes() {
			return mMinutes;
		}

		int seconds() {
			return mSeconds;
		}

	
};

std::vector<Time> getTimesFromString(std::string_view & s) {
	std::vector<Time> mass_time;
	int time = 0;
	int point = 0;
	while (time <= s.size()) {
		if (time == s.size()) {
			mass_time.push_back(Time(s.substr(point, time - point + 1)));
			break;
		}
		else if (s[time] == ' ') {
			mass_time.push_back(Time(s.substr(point, time - point + 1)));
			time++;
			point = time;
		}
		else {
			time++;
		}
	}
	return mass_time;
}

Time sumTimes(std::vector<Time>& v) {
	int hours = 0; 
	int minutes = 0; 
	int seconds = 0;
	for (int i = 0; i < v.size(); i++) {
		hours += v[i].hours();
		minutes += v[i].minutes();
		seconds += v[i].seconds();
	}
	minutes += seconds / 60;
	seconds = seconds % 60;
	hours += minutes / 60;
	minutes = minutes % 60;
	return Time(hours, minutes, seconds);
}
int main()
{
	std::string_view s{ "01:23:34 21:36:56 19:49:24" };//проверяем 4 задание пункт первый 
	std::vector<Time> v = getTimesFromString(s);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i].hours() << " " << v[i].minutes() << " " << v[i].seconds() << std::endl;
	}

	Time new_time = sumTimes(v);//проверяем 4 задние 2 пункт
	std::cout << new_time.hours() << " " << new_time.minutes() << " " << new_time.seconds() << std::endl;

}

