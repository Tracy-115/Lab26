#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    cout << setw(12) << "Operation"<< setw(12) << "Vector"<< setw(12) << "List"<< setw(12) << "Set" << endl;
    
    ifstream fin("codes.txt");
    if (!fin.is_open()){
        cout << "Could not open the file :'(" << endl;
        return 1;
    }

    vector<string>data;
    string code;
    while(fin>>code){
        data.push_back(code);
    }
    fin.close();

    //ONE
    vector<string> numbers;
    auto start = high_resolution_clock::now();
    for (const auto &c : data){
        numbers.push_back(c);
    }
    auto end = high_resolution_clock::now();
    auto durationVECTOR = duration_cast<microseconds>(end - start);
    long long vectorT = durationVECTOR.count();

    list<string> lists;
    start = high_resolution_clock::now();
    for (const auto &c : data){
        lists.push_back(c);
    }
    end = high_resolution_clock::now();
    auto durationLIST = duration_cast<microseconds>(end - start);
    long long listT = durationLIST.count();
    
    set<string> SET;
    start = high_resolution_clock::now();
    for (const auto &c : data){
        SET.insert(c);
    }
    end = high_resolution_clock::now();
    auto durationSET = duration_cast<microseconds>(end - start);
    long long setT = durationSET.count();

    cout << setw(12) << "Read" << setw(12) << vectorT << setw(12) << listT << setw(12) << setT << endl;

    //TWO
     start = high_resolution_clock::now();
    sort(numbers.begin(), numbers.end());
     end = high_resolution_clock::now();
    auto durationSv = duration_cast<microseconds>(end - start);
    long long vectorS = durationSv.count();
    
    start = high_resolution_clock::now();
    lists.sort();
    end = high_resolution_clock::now();
    auto durationSl = duration_cast<microseconds>(end - start);
    long long listS= durationSl.count();
    
    long long setSORT = -1;

    cout << setw(12) << "Set" << setw(12) << vectorS << setw(12) << listS << setw(12) << setSORT << endl;


    //THREE
    string setValue ="TESTCODE";
    
    vector<string> vectorIns=numbers;
    start = high_resolution_clock::now();
    vectorIns.insert(vectorIns.begin()+vectorIns.size()/2, setValue);
    end = high_resolution_clock::now();
    auto durationVI = duration_cast<microseconds>(end - start);
    long long vectorI = durationVI.count();
    
    list<string> listIns = lists;
    auto listMiddle = listIns.begin();
    advance(listMiddle, listIns.size() / 2);
    start = high_resolution_clock::now();
    listIns.insert(listMiddle,setValue);
    end = high_resolution_clock::now();
    auto durationLI = duration_cast<microseconds>(end - start);
    long long listI = durationLI.count();
    
    set<string> setIns= SET;
    start = high_resolution_clock::now();
    setIns.insert(setValue);
    end = high_resolution_clock::now();
    auto durationSETI = duration_cast<microseconds>(end - start);
    long long setI = durationSETI.count();
    cout << setw(12) << "Insert" << setw(12) << vectorI << setw(12) <<  listI << setw(12) << setI << endl;

    //FoOUR
    vector<string> vectorDel=numbers;
    start = high_resolution_clock::now();
    vectorIns.erase(vectorIns.begin()+vectorIns.size()/2);
    end = high_resolution_clock::now();
    auto durationVECTORE = duration_cast<microseconds>(end - start);
    long long vectorE = durationVECTORE.count();

    list<string> listDel = lists;
    auto listDelMid = listDel.begin();
    advance(listDelMid, listDel.size() / 2);
    start = high_resolution_clock::now();
    listDel.erase(listDelMid);
    end = high_resolution_clock::now();
    auto durationLISTE = duration_cast<microseconds>(end - start);
    long long listE = durationLISTE.count();

    set<string> setDel= SET;
    auto setMiddle = setDel.begin();
    advance(setMiddle, setDel.size() / 2);
    start = high_resolution_clock::now();
    setDel.erase(setMiddle);
    end = high_resolution_clock::now();
    auto durationSETE = duration_cast<microseconds>(end - start);
    long long setE = durationSETE.count();
    cout << setw(12) << "Delete" << setw(12) << vectorE << setw(12) << listE << setw(12) << setE << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/