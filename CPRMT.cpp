#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    while( cin >> str1 >> str2 ) {
        int count[128] = {0};
        vector<char> permute;
        vector<char>::iterator iter;
        int len = str2.size();
            for(int i = 0; i < len; i++) {
                count[str2[i]]++;
            }
            len = str1.size();
            for( int i = 0; i < len; i++) {
                if( count[str1[i]]) {
                    count[str1[i]]--;
                    permute.push_back(str1[i]);
                }
            }
            sort( permute.begin(), permute.end() );

            for( iter = permute.begin(); iter != permute.end(); iter++){
                cout << *iter;
            }
            cout << endl;
    }
 return 0;
}
