    #include <iostream>
    #include <queue>
    using namespace std;

    int main() {
    	int tc;
    	cin >> tc;
    	for(int i=0;i<tc;i++) {
    		int n,k;
    		std::priority_queue<int> loc;
    		cin >> n >> k;
    		int j=1, ls, rs;
    		int curr = n;
    		while(j<=k && curr>0) {
        			if(!loc.empty()) {
    				curr = loc.top();
    				loc.pop();
    			}
    			if(curr>0) {
    				if(curr%2==0) {
    					ls = (curr/2)-1;
    					rs = curr/2;
    				} else {
    					ls = (curr-1)/2;
    					rs = (curr-1)/2;
    				}
    			}

    			loc.push(rs);
    			loc.push(ls);
    			j++;
    		}
    		cout << "Case #" << i+1 << ": " << rs << " " << ls << endl;
    	}
    	return 0;
    }
