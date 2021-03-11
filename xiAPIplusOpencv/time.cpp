#include <iostream>
#include <time.h>
#include <string>
#define PST (-8)
#define PDT (-7)
using namespace std;

string get_formmated_time()
{
    time_t rawtime;
    struct tm * ptm;
    time (&rawtime);
    ptm = gmtime (&rawtime);

    int year = ptm->tm_year+1900, month = ptm->tm_mon+1, day = ptm->tm_mday, hour = (ptm->tm_hour+PST)%24, min = ptm->tm_min, sec = ptm->tm_sec;

    string year_s = to_string(year);
    string month_s = to_string(month);
    string day_s = to_string(day);
    string hour_s = to_string(hour);
    string min_s = to_string(min);
    string sec_s = to_string(sec);

    return year_s + "-" + month_s + "-" + day_s + "_" + hour_s + "." + min_s + "." + sec_s;
}

string generate_file_name(int exposure, int gain)
{
    string filename;
    filename += get_formmated_time() + "_exposure-" + to_string(exposure) + "_gain-" + to_string(gain);
    return filename;
}

int main() {
    string out = generate_file_name(100, 100);
    std::cout << out << std::endl;
}