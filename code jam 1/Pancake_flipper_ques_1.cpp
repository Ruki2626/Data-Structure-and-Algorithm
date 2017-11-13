#include <iostream>
using namespace std;
int main() {
    	int test;
    	cin >> test;
    	std::string pancakes;
    	int flipper;
    	for(int i=0;i<test;i++) {
    		cin >> pancakes >> flipper;
    		std::string ans;
    		int len = pancakes.length();
    		int count = 0;
    		for(int pc=0;pc<len;pc++) {
    			if(pancakes.at(pc)=='-') {
    				if((pc+flipper-1)>=len) {
    					ans = "IMPOSSIBLE";
    					break;
    				}
    				for(int j=0;j<flipper;j++) {
    					if(pancakes.at(pc+j)=='+')
    						pancakes.at(pc+j) = '-';
    					else if(pancakes.at(pc+j)=='-')
    						pancakes.at(pc+j) = '+';
    				}
    				count++;
    			}
    			ans = std::to_string(count);
    		}

    		cout << "Case #" << i+1 << ": " << ans << endl;
    	}
    	return 0;
    }
