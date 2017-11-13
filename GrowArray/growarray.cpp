#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class GrowArray{
	private:
		vector<int> arr;
	public:
		GrowArray(){
		}
		~GrowArray(){
			arr.clear();
		}
		void add_front(int start,int next,int end);
		void add_back(int start,int next,int end);
		void output();
		void remove_front(int n);
		void remove_back(int n);
};
void GrowArray::add_front(int start,int next,int end){
	for(int i=start;i<=end;i+=next){
		arr.insert(arr.begin(),i);
	}
}
void GrowArray::add_back(int start,int next,int end){
	for(int i=start;i<=end;i+=next){
		arr.push_back(i);
	}
}
void GrowArray::output(){
	cout<<arr[0];
	for(unsigned int i=1;i<arr.size();i++){
		cout<<","<<arr[i];
	}
	cout<<"\n";
}
void GrowArray::remove_front(int n){
	for(int i=0;i<n;i++){
		arr.erase(arr.begin());
	}
}
void GrowArray::remove_back(int n){
	for(int i=0;i<n;i++){
		arr.pop_back();
	}
}
int main(){
    string instruction,n;
    int r=0,k=0,start,next,end;
    GrowArray obj;
    ifstream inFile;
  	inFile.open("HW4a.txt");
  	if (inFile.fail()){
    	cout << "unable to open file HW4a.txt for reading" << endl;
      	exit(1);
  	}
    while(inFile>>instruction){
    	if(instruction.compare("OUTPUT")==0){
    		n="\0";
    	}
    	else{
    		inFile>>n;
    	}
    	for(int i=0;n[i]!='\0';i++){
    		if(n[i]!=':'){
    			r=(r*10)+(n[i]-48);
    		}
    		else{
    			k++;
    			if((k==1&&instruction.compare("ADD_FRONT")==0)||(k==1&&instruction.compare("ADD_BACK")==0)){
    				start=r;
    				r=0;
    			}
    			else if((k==2&&instruction.compare("ADD_FRONT")==0)||(k==2&&instruction.compare("ADD_BACK")==0)){
    				next=r;
    				r=0;
    			}
    			else{
    				start=0;
    				next=0;
    			}
    		}
    	}
    	if(instruction.compare("ADD_FRONT")==0){
			end=r;
    		obj.add_front(start,next,end);
    	}
    	else if(instruction.compare("OUTPUT")==0){
    		obj.output();
    	}
    	else if(instruction.compare("ADD_BACK")==0){
    		end=r;
    		obj.add_back(start,next,end);
    	}
    	else if(instruction.compare("REMOVE_FRONT")==0){
    		end=r;
    		obj.remove_front(end);
    	}
    	else if(instruction.compare("REMOVE_BACK")==0){
    		end=r;
    		obj.remove_back(end);
    	}
    	r=0;
    	k=0;
    }
}
