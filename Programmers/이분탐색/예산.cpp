// 문제 설명
// 국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것입니다. 국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있습니다. 그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정합니다.

// 1. 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정합니다.
// 2. 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정합니다. 
//    상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정합니다. 
// 예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150일 때, 상한액을 127로 잡으면 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 됩니다.
// 각 지방에서 요청하는 예산이 담긴 배열 budgets과 총 예산 M이 매개변수로 주어질 때, 위의 조건을 모두 만족하는 상한액을 return 하도록 solution 함수를 작성해주세요.

// 제한 사항
// 지방의 수는 3 이상 100,000 이하인 자연수입니다.
// 각 지방에서 요청하는 예산은 1 이상 100,000 이하인 자연수입니다.
// 총 예산은 지방의 수 이상 1,000,000,000 이하인 자연수입니다.
// 입출력 예
// budgets	M	return
// [120, 110, 140, 150]	485	127
// 출처

// ※ 공지 - 2019년 3월 15일, 테스트케이스가 강화되었습니다.

// 이번 업데이트로 인해 지방의 수가 최대 10,000개에서 100,000개로 늘어났으며, 이에 따라 테스트케이스가 수정되었습니다.

// 이로 인해 이전에 통과하던 코드가 더 이상 통과하지 않을 수 있습니다.


#include <string>
#include <vector>
#include <algorithm>

int result = 0;
using namespace std;
int mid = 0;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int low = 0;
    int high = 100000;
    int mid = 0;
    int cnt = 0;
    long sum = 0;
    sort(budgets.begin(), budgets.end());
    for(int i = 0; i<budgets.size();i++){
       sum += budgets[i];
    }
    if(sum<=M){
        return budgets[budgets.size() - 1];
    }

    
    //high = budgets[budgets.size()-1];
    
    
   while(low+1 < high){
			mid = (low+high)/2;
			sum = 0; 

			for(int i=0; i<budgets.size(); i++){

				if(budgets[i] < mid)
					sum += budgets[i];
				else
					sum += mid;

			}

			if(sum <= M)
				low = mid;

			else 
				high = mid;
		}	
    
    answer = low;
    return answer;
}