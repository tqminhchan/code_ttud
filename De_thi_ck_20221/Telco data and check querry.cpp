#include <bit/stdc++.h>
using namespace std;

int incorrectPhone = 0;
int totalCalls = 0;
map <string,int> numberCalls, timeCall;

// return 0 if it is not a number, else return 1
bool checkPhone(string phoneNumber){ 
    if(phoneNumber.length() == 10){
        for(int i = 0;i < phoneNumber.length();i++){
            if(isdigit(phoneNumber[i]) == 0 ) return false;
        }
        return true;
    }
    return false;
}

int countTime(string time1 , string time2){
    int startTime;
    startTime = 3600 * ((time1[0] - '0')*10 +(time1[1]-'0')) 
    + 60 * ((time1[3] - '0')*10 + (time1[4]-'0'))
    + ((time1[6]-'0')*10 + time1[7]);

    int endTime;
    endTime = 3600 * ((time2[0] - '0')*10 +(time2[1]-'0')) 
    + 60 * ((time2[3] - '0')*10 + (time2[4]-'0'))
    + ((time2[6]-'0')*10 + time2[7]);

    return endTime - startTime;
}
// 10:10:10
int main(int argc, char const* argv[])
{
    string type ;
    do{
        cin >> type;
        if(type == "#") continue;
        ++totalCalls;
        string fnum, tnume, date, ftime, etime;
        cin >> fnum >> tnume >> date >> ftime >> etime;
        if(!checkPhone(fnum) || !checkPhone(tnume)) ++incorrectPhone;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime , etime);
    }while(type != "#");

    string chosen;
    do{
        cin >> type;
        if(type == "?check_phone_number"){
            if(incorrectPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(type == "?number_total_calls"){
            cout << totalCalls << endl;
        }else if(type == "?number_calls_from"){
            cin >> chosen;
            cout << numberCalls[chosen] << endl;
        }else if(type == "?count_time_calls_from"){
            cin >> chosen;
            cout << timeCall[chosen] << endl;
        }
    }while(type != "#");
}
