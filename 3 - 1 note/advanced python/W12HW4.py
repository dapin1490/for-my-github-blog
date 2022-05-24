import pandas as pd
import numpy as np

'''
Assignment 4(과제 4)
첨부파일로 있는 seoul_cctv.csv파일이 존재한다. 아래의 문제들을 확인하여서 진행하시요. (문제별로 함수 또는 메소드를 만드시요.)

* 하나의 파일로 제출해야 하며 numpy 기능 사용 필수
* 문제별 함수/메소드이름은 step_one, step_two, step_three로 하시오.
'''

# 본 파일을 읽어서 print로 출력하시요 (1점)
def step_one():
    data = pd.read_csv("seoul_cctv.csv", thousands = ',', encoding='cp949')  # UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb1 in position 0: invalid start byte
    print(data)
    return

step_one()


# 본 파일내 두번째 열이 소계값인데 해당 값과 세번째 이후 열의 총합의 값이 동일한지 여부에 대한 결론을 출력하시요(2점)
	# 단 검증 출력의 경우 행 번호에 맞춰 True/False 여부만 출력
def step_two():
    data = pd.read_csv("seoul_cctv.csv", thousands = ',', encoding='cp949')
    data["sum_years"] = np.sum(data.iloc[:, 2:10], axis=1)  # 인덱스로 직접 추출 start:end 하면 start부터 (end - 1)까지. 두 인자의 순서는 행, 열
    data["is_sum_same"] = True if data["소계"].all() == data["sum_years"].all() else False
    print(data["is_sum_same"])
    return

step_two()


# 결과값 True/False을 새로운 열에 입력하고 새로운 파일인 seoul_cctv_result.csv 파일로 저장 완료하시요. (1점)
	# 단 해당 csv파일 생성후 엑셀 프로그램으로 정상 open 작동 필수
def step_three():
    data = pd.read_csv("seoul_cctv.csv", thousands = ',', encoding='cp949')
    sum_years = data.iloc[:, 2:10].sum(axis=1)  # 인덱스로 직접 추출 start:end 하면 start부터 (end - 1)까지. 두 인자의 순서는 행, 열
    data["is_sum_same"] = True if data["소계"].all() == sum_years.all() else False
    data.to_csv("seoul_cctv_result.csv", encoding='cp949')  # 정상 open 확인했음
    return

step_three()
