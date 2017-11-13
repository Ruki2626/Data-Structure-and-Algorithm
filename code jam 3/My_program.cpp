#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int max(long long int a,long long int b){return a>b?a:b;};
long long int min(long long int a,long long int b){return a<b?a:b;};
int main(){
	long long int te;
	vector<long long int> vec;
	cin >> te;
	for(long long int s=1;s<=te;s++){
		long long int n,k;
		cin>> n >> k;
		vec.clear();
		vec.push_back(1);
		vec.push_back(n+2);
        long long int num;
        pair<long long int,long long int> distance;

        for(long long int j=1;j<=k;j++){
        	num = -1;
        	for(unsigned long long int i=1;i<vec.size();i++){
        		if(vec.at(i)-vec.at(i-1) == 1)
        			continue;

        		long long int tempnum = (vec.at(i-1)+vec.at(i))/2;;
        		pair<long long int,long long int> tempdis = make_pair(tempnum-vec.at(i-1)-1,vec.at(i)-tempnum-1);
        		if(num == -1){
        			num = tempnum;
                    distance = tempdis;
        		}
        		if(vec.at(i-1)%2 == vec.at(i)%2){
        			if( min(distance.first,distance.second) < min(tempdis.first,tempdis.second) ){
                            num = tempnum;
                            distance = tempdis;
                    }
                    else if( min(distance.first,distance.second) == min(tempdis.first,tempdis.second) ){
                    	if( max(distance.first,distance.second) < max(tempdis.first,tempdis.second) ){
                                num = tempnum;
                                distance = tempdis;
                        }
                    }
                }
                else{
                	if( min(distance.first,distance.second) < min(tempdis.first,tempdis.second) ){
                		num = tempnum;
                		distance = tempdis;
                	}
                    else if( min(distance.first,distance.second) == min(tempdis.first,tempdis.second) ){
                    	if( max(distance.first,distance.second) < max(tempdis.first,tempdis.second) ){
                    		num = tempnum;
                    		distance = tempdis;
                        }
                    }

                	tempnum++;
                	tempdis = make_pair(tempdis.first+1, tempdis.second-1);

                	if( min(distance.first,distance.second) < min(tempdis.first,tempdis.second) ){
                		num = tempnum;
                		distance = tempdis;
                	}
                	else if( min(distance.first,distance.second) == min(tempdis.first,tempdis.second) ){
                		if( max(distance.first,distance.second) < max(tempdis.first,tempdis.second) ){
                			num = tempnum;
                			distance = tempdis;
                    }
                }
            }
        }
        	vec.push_back(num);
        	sort(vec.begin(),vec.end());
        }
            cout << "Case #"<<s<<":   "<<  distance.second  <<"\t"<<  distance.first<<endl;
	}
}
