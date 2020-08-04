#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
//이코드는 시간복잡도가 N*M이기 때문에 시간초과를 유발함
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M, ans=0;  // N이 1이면 IOI 2이면 IOIOI
	string s1="I", s2;
	cin >> N >> M;
	cin >> s2;
	for (int i = 0; i < N; i++) {
		s1.append("OI");
	}

	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		if (s1 == s2.substr(i, s1.length()))
			ans++;
	}

	cout << ans;
	return 0;
}
*/

//KMP 알고리즘을 사용하자 https://bowbowbow.tistory.com/6
vector<int> getPi(string p){  // pi배열을 얻는 함수 -> 접두사와 접미사의 일치하는 글자 개수를 찾는것
							  //ABAABAB 면 0,0,1,1,2,3,2
	int m = (int)p.size(), j=0; 
	vector<int> pi(m, 0); //p의 길이인 m개의 벡터원소를 0으로 할당
	for(int i = 1; i< m ; i++){ 
		while(j > 0 && p[i] != p[j]) 
			j = pi[j-1]; 
		if(p[i] == p[j]) 
			pi[i] = ++j; 
	} 
	return pi; 
}

vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) //일치했던 부분을 이용해서 중간단계를 뛰어넘는다.
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, M, ans = 0;  // N이 1이면 IOI 2이면 IOIOI
	string s1 = "I", s2;
	cin >> N >> M;
	cin >> s2;
	for (int i = 0; i < N; i++) {
		s1.append("OI");
	}

	auto matched = kmp(s2, s1);

	cout << matched.size();


	return 0;
}

