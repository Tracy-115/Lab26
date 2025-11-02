//Kyawt Thinzar Min 
//IDE used: VS code
//:)
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

const int slice = 2, event = 4, structs = 3;
//slice: 0 holds the data and 1 accumulates it
//events is the number of actions being done here
//structs are for vectors, string, and list
long long array3 [slice][event][structs];

int main() {
    for (int i=0; i < event ; i++){ // this initializes the slice 1 to be 0
        for (int a=0; a<structs; a++){
            array3 [1][i][a] =0;
        }
    }
    cout << "Number of Simulations: 15" << endl;

    cout << setw(12) << "Operation"<< setw(12) << "Vector"<< setw(12) << "List"<< setw(12) << "Set" << endl;
    
    string operations[4] ={"Read","Sort", "Insert", "Delete"};

    for (int i = 0; i<15; i++){
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
        //at the end of each sub-section e.g like the vector in Read, I added array3 [0][0][0] so that the data taken out from code.txt is stored in that specific 3D index in the array
        //ONE
        vector<string> numbers;
        auto start = high_resolution_clock::now();
        for (const auto &c : data){
            numbers.push_back(c);
        }
        auto end = high_resolution_clock::now();
        auto durationVECTOR = duration_cast<microseconds>(end - start);
        array3 [0][0][0] = durationVECTOR.count();

        list<string> lists;
        start = high_resolution_clock::now();
        for (const auto &c : data){
            lists.push_back(c);
         }
        end = high_resolution_clock::now();
        auto durationLIST = duration_cast<microseconds>(end - start);
        array3 [0][0][1] = durationLIST.count();
         
        set<string> SET;
        start = high_resolution_clock::now();
        for (const auto &c : data){
            SET.insert(c);
        }
        end = high_resolution_clock::now();
        auto durationSET = duration_cast<microseconds>(end - start);
        array3 [0][0][2] = durationSET.count();

         //TWO
         start = high_resolution_clock::now();
        sort(numbers.begin(), numbers.end());
         end = high_resolution_clock::now();
        auto durationSv = duration_cast<microseconds>(end - start);
        array3 [0][1][0] = durationSv.count();
        
        start = high_resolution_clock::now();
        lists.sort();
        end = high_resolution_clock::now();
        auto durationSl = duration_cast<microseconds>(end - start);
        array3 [0][1][1]= durationSl.count();
        
        array3 [0][1][2] = -1;


        //THREE
        string setValue ="TESTCODE";
        
        vector<string> vectorIns=numbers;
        start = high_resolution_clock::now();
        vectorIns.insert(vectorIns.begin()+vectorIns.size()/2, setValue);
        end = high_resolution_clock::now();
        auto durationVI = duration_cast<nanoseconds>(end - start);
        array3 [0][2][0] = durationVI.count();
        
        list<string> listIns = lists;
        auto listMiddle = listIns.begin();
        advance(listMiddle, listIns.size() / 2);
        start = high_resolution_clock::now();
        listIns.insert(listMiddle,setValue);
        end = high_resolution_clock::now();
        auto durationLI = duration_cast<nanoseconds>(end - start);
        array3 [0][2][1] = durationLI.count();
        
        set<string> setIns= SET;
        start = high_resolution_clock::now();
        setIns.insert(setValue);
        end = high_resolution_clock::now();
        auto durationSETI = duration_cast<nanoseconds>(end - start);
        array3 [0][2][2] = durationSETI.count();
        //four
        vector<string> vectorDel=numbers;
        start = high_resolution_clock::now();
        vectorIns.erase(vectorIns.begin()+vectorIns.size()/2);
        end = high_resolution_clock::now();
        auto durationVECTORE = duration_cast<nanoseconds>(end - start);
        array3 [0][3][0] = durationVECTORE.count();

        list<string> listDel = lists;
        auto listDelMid = listDel.begin();
        advance(listDelMid, listDel.size() / 2);
        start = high_resolution_clock::now();
        listDel.erase(listDelMid);
        end = high_resolution_clock::now();
        auto durationLISTE = duration_cast<nanoseconds>(end - start);
        array3 [0][3][1] = durationLISTE.count();

        set<string> setDel= SET;
        auto setMiddle = setDel.begin();
        advance(setMiddle, setDel.size() / 2);
        start = high_resolution_clock::now();
        setDel.erase(setMiddle);
        end = high_resolution_clock::now();
        auto durationSETE = duration_cast<nanoseconds>(end - start);
        array3 [0][3][2] = durationSETE.count();

        for (int c=0; c < event ; c++){ //if it's only this, there is just too much data 
            for (int a=0; a<structs; a++){
                array3 [1][c][a] += array3 [0][c][a] ;
                //cout << array3 [0][c][a] << endl;
            }
        }
    }
    for (int c=0; c < event ; c++){ 
        cout  << setw(12) << operations[c] << setw(12);
            for (int a=0; a<structs; a++){
                long long aveg = array3 [1][c][a]/15; //here, i divided it out by 15 so that i will get the average over 15 simulations
                cout << setw(12) << aveg;
            }
            cout << endl;
        }
    
    return 0;
}
//at first, I was getting zeros for both insert and delet, but when I changed it into nanoseconds, it worked out
//i think this is because the operation got less time to compute because it was a small operation