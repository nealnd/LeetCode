#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        set<char>vowels{'a', 'e', 'i', 'o','u','A', 'E', 'I', 'O','U'};
  
        while(i<j){
            if(vowels.contains(s[i])&&!vowels.contains(s[j])){
                j--;
            }
            else if(vowels.contains(s[j])&&!vowels.contains(s[i])){
                i++;
            }
            else if(vowels.contains(s[j])&&vowels.contains(s[i]))
            {
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};

int main(){
    string s="leetcode";
    Solution Sol;
    cout<<Sol.reverseVowels(s)<<endl;

}