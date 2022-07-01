'''
다음과 같은 두 개의 DataFrame이 있다.
(DataFrame 생략)
위의 값을 가지는 DataFrame 두 개를 생성하고 다음 조건에 맞게 병합하시오.
(1) 교집합
(2) 합집합
(3) AgeKorMa에 있는 학생들에 대하여 과학 영어점수가 있는 경우에 병합
'''

import pandas as pd

SciEng = pd.DataFrame({
    "Student_no" : [20140308, 20150209, 20150215, 20150221, 20160207, 20160592, 20160605],
    "Science" : [84, 90, 96, 92, 91, 91, 89],
    "English" : [95, 99, 84, 98, 85, 97, 96]
})

AgeKorMa = pd.DataFrame({
    "Student_no" : [20140106, 20150209, 20150221, 20150308, 20160207, 20160592],
    "Age" : [22, 21, 21, 21, 20, 19],
    "Korean" : [92, 95, 93, 94, 91, 88],
    "Math" : [89, 82, 95, 86, 90, 85]
})

# (1) 교집합
answer1 = pd.merge(SciEng, AgeKorMa, on='Student_no', how='inner')

# (2) 합집합
answer2 = pd.merge(SciEng, AgeKorMa, on='Student_no', how='outer')

# (3) AgeKorMa에 있는 학생들에 대하여 과학 영어점수가 있는 경우에 병합
answer3 = pd.merge(SciEng, AgeKorMa, on='Student_no', how='right')
answer3 = answer3.dropna().reset_index(drop=True)  # 인덱스 리셋 코드 참고 : https://seong6496.tistory.com/73
