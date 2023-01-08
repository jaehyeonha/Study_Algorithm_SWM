#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <deque>
#include <vector>

/**
 * @brief BOJ - 1966번 문제
 */
int main()
{
    int iter_num;
    int document_num, target_index;
    int each_document, print_cnt = 0;
    std::cin >> iter_num;

    std::deque<int> dq;

    for (int i = 0; i < iter_num; i++)
    {
        // 우리의 최종 목표는 target_index가 몇번째에 출력되는 지이다.
        std::cin >> document_num >> target_index;

        // 데크에 값들을 입력받는 과정이다.
        for (int j = 0; j < document_num; j++)
        {
            std::cin >> each_document;
            dq.push_back(each_document);
        }

        while (true)
        {
            // n >= 1 ? n - 1 : document_num(x) ->dq.size() 왜나면 우선순위가 높은것을 출력하면서 길이가 변하기 때문이다.;
            while (std::any_of(dq.begin(), dq.end(), [&dq](int &dq_each_value)
                               { return dq_each_value > dq.front(); }))
            {
                dq.push_back(dq.front());
                dq.pop_front();
                target_index >= 1 ? target_index-- : target_index = dq.size() - 1;
                // std::cout << "check target_index (1) >> " << target_index << std::endl;
            }

            // 빼내고 cnt++
            dq.pop_front();
            print_cnt++;

            // 출력하고 봤는데, 0번째 였다면, 종료
            if (target_index == 0)
                break;

            target_index >= 1 ? target_index-- : target_index = dq.size() - 1;
            // std::cout << "check target_index (2) >> " << target_index << std::endl;
            // 만약 빠져나와서 출력하는 경우인데, target_index가 0번이라면 끝내면 된다.
        }
        std::cout << print_cnt << std::endl;

        // 데크 초기화
        while (dq.begin() != dq.end())
            dq.pop_front();

        // cnt 초기화
        print_cnt = 0;
    }

    return 0;
}

/**
 * 1. 현재 Queue의 가장 앞에 있는 문서의 '중요도'를 확인합니다.
 * 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있으면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 합니다. 그렇지 않으면 바로 인쇄합니다.
 * Queue -> 1(x) 1 9 1 1 1
 * -> 9 1 1 1 1(x) 1 ( 9 출력 )
 * -> 1 1 1 1(x) 1 ( 1 출력 )
 *
 * 출력: 5 ( check o )
 *
 * 1 2 3 4
 * 2 3 4 1 (3)
 * 3 4 1 2 (2)
 * 4 1 2 3 (1)
 *
 *
 *
 */